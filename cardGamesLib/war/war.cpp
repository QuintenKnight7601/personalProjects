#include "framework.h"
#include "war.h"

war::war( bool start )
{
    deck.reset();
    deck.shuffle();

    if (start)
        playGame();
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

bool war::setHands()
{
    //Defining variables
    int size = deck.size();
    cards tempDeck;
    card tempCard;

    //If the deck is empty, fill it
    if (size == 0)
        if (!deck.reset() || !deck.shuffle()) //If the deck does not fill, return false
            return false;
 

    //Update deck size and temporary deck
    size = deck.size();
    tempDeck = deck;

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
    if (hand1.empty() || hand2.empty())
        return true;
    
    if (!playRound())
        return false;

    return playGame();
}

bool war::playRound()
{
    //Defining variables
    int dif = 0;

    while (dif == 0)
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
    }

    if (dif > 0)
    {
        while (!disc1.empty())
            if (!hand1.place(disc1.draw(), 0, true))
                return false;
        while (!disc2.empty())
            if (!hand1.place(disc2.draw(), 0, true))
                return false;

        return true;
    }

    while (!disc2.empty())
        if (!hand2.place(disc2.draw(), 0, true))
            return false;
    while (!disc1.empty())
        if (!hand2.place(disc1.draw(), 0, true))
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

bool warGame()
{
    int winner;

    cout << "Welcome to War!" << endl << endl;

    war game;

    game.winner(winner);

    cout << "Player " << winner << " won the war!" << endl;

    return false;
}
