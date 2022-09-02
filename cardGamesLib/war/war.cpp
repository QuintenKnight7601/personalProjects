#include "framework.h"
#include "war.h"

int main() {

}

war::war()
{
    deck.set();
}

war::war(playingCards deckIn)
{
    deck = deckIn;
}

war::~war()
{
}

bool war::setHands()
{
    //Defining variables
    int size = deck.size();
    playingCards tempDeck;
    card tempCard;

    //If the deck is empty, fill it
    if (size == 0)
        if (!deck.set() || !deck.shuffle()) //If the deck does not fill, return false
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

    return true;
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