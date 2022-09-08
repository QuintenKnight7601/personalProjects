#include "framework.h"
#include "war.h"

war::war( bool set )
{
    if (set)
    {
        deck.reset();
        deck.shuffle();
    }
}

war::war(cards deckIn, bool start )
{
    deck = deckIn;
    if (start)
        playGame();
}

war::~war()
{
}


bool war::manual()
{
    int win;
    char choice;
    bool seeDeck = false;

    do
    {
        cout << "Choose an option:\n"
            << " 1: auto fill deck\n"
            << " 2: manual fill deck\n"
            << " 3: deck from file\nChoice: ";

        cin >> choice;

        if (choice == '1')
        {
            reset();
        }
        else if (choice == '2')
        {
            cout << "Feature still in development" << endl;
        }
        else if (choice == '3')
        {
            cout << "Feature still in development" << endl;
            ifstream fin("deck.txt");
            if (!fin.is_open())
            {
                cout << "Failed to open file" << endl;
            }
            else
            {
                cout << "File opened successfully" << endl;
                fin >> deck;
                cout << deck;
            }
        }
        else
        {
            cout << "INVALID CHOICE" << endl;
        }

        cout << "\n\n\n\n\n\n\n\n\n\n\n" << endl;
    } while (choice != '1' /* && choice != '2'*/ && choice != '3' );

    choice = 0;

    do
    {
        cin.clear();

        cout << "See deck order?\n 1: yes\n 2: no\n\nChoice: ";

        cin >> choice;

        if (choice == '1')
        {
            seeDeck = true;
        }
        else if (choice == '2')
        {
            seeDeck = false;
        }
        else
        {
            cout << "INVALID CHOICE" << endl;
        }

        cout << "\n\n\n\n\n\n\n\n\n\n" << endl;
    } while (choice != '1' && choice != '2');

    choice = 0;

    do
    {

        if (seeDeck)
        {
            choice = 0;
            cout << deck << endl << endl;

            do
            {
                cout << "Shuffle again?\n 1: yes\n 0: no\n\nChoice: ";

                cin >> choice;

                if (choice != '1' && choice != '0')
                    cout << "INVALID CHOICE\n\n\n\n";
            } while (choice != '1' && choice != '0');
        }
    } while (seeDeck && choice != '0');

    //ADD PLAYTHROUGH
    playGame();

    winner(win);

    if (win > 0)
    {
        cout << "YOU WIN!!!\nThe Game of War lasted " << rounds << " rounds!!\n\nYour final hand was:\n" << hand1 << endl;
    }
    else if (win < 0)
    {
        cout << "YOU LOST!!!\nThe Game of War lasted " << rounds << " rounds!!\n\nTheir final hand was:\n" << hand2 << endl;
    }
    else
    {
        cout << "The game never ended" << endl;
    }

    return true;
}

bool war::setHands()
{
    //Defining variables
    int size = deck.size();
    card tempCard;

    //If the deck is empty, fill it
    if (size == 0)
        if (!deck.reset() || !deck.shuffle()) //If the deck does not fill, return false
            return false;
 

    //Update deck size and temporary deck
    size = deck.size();

    //Iterate through the deck and move cards to hands
    for (int i = 0; i < size; ++i)
    {
        tempCard = deck.draw();

        //Alternate adding cards to hands
        if (i % 2 == 0)
            if (!hand1.place(tempCard))
                return false;
        if (i % 2 == 1)
            if (!hand2.place(tempCard))
                return false;
    }

    return true;
}

bool war::playGame()
{
    setHands();

    return iterateGame();
}

bool war::iterateGame()
{

    if (hand1.empty() || hand2.empty() || rounds > 3000)
        return true;

    if (!playRound())
        return false;

    ++rounds;

    return iterateGame();
}

bool war::playRound()
{
    //Defining variables
    int dif = 0;

    do
    {
        //Both players discard a card
        disc1.place(hand1.draw());
        disc2.place(hand2.draw());

        //Set difference integer
        dif = compare();

        //If tied then draw three and repeat
        if (dif == 0)
        {
            disc1.place(hand1.draw());
            disc2.place(hand2.draw());
            disc1.place(hand1.draw());
            disc2.place(hand2.draw());
            disc1.place(hand1.draw());
            disc2.place(hand2.draw());
        }
    } while (dif == 0);

    if (dif > 0)
    {
        while (!disc2.empty())
            if (!hand1.place(disc2.draw(), 0))
                return false;
        while (!disc1.empty())
            if (!hand1.place(disc1.draw(), 0))
                return false;

        return true;
    }

    while (!disc1.empty())
        if (!hand2.place(disc1.draw(), 0, true))
            return false;
    while (!disc2.empty())
        if (!hand2.place(disc2.draw(), 0, true))
            return false;

    return true;

}

int war::compare() 
{
    //Defining variables
    int val1 = disc1.peek().val, val2 = disc2.peek().val;
    int dif;

    //If aces, set as high cards
    if (val1 == 0)
        val1 += 13;
    if (val2 == 0)
        val2 += 13;

    //Find the difference between the values
    dif = val1 - val2;

    return dif;
}

bool war::winner(int& player)
{
    //If both hands are empty return false
    if (hand1.empty() && hand2.empty())
        return false;

    //If hand 1 is empty player 2 wins
    if (hand1.empty())
    {
        player = 2;
        return true;
    }
    //If hand 2 is empty player 1 wins
    if (hand2.empty())
    {
        player = 1;
        return true;
    }

    //No hands were empty, return false
    return false;
}

int war::numRounds()
{
    return rounds;
}

cards war::hand(bool player /*true for 1, false for 2*/)
{
    //return selected hand
    if (player)
        return hand1;
    return hand2;
}
