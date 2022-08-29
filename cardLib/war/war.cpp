#include "framework.h"
#include "war.h"



war::war()
{
    deck.set();
}

war::war(cards deckIn)
{
    deck = deckIn;
}

war::~war()
{
}

bool war::warMain()
{
    //Defining variables
    cards hand1, hand2;

    //Prepare game
    if (!setHands());

    
}


bool war::setHands()
{
    //Defining variables
    int size = deck.size();
    cards tempDeck;
    CARDS::cards tempCard;

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
}



bool war::playGame()
{


}


bool war::playRound()
{
    //Defining variables
    CARDS::cards tempCard;

    //Both players discard a card
    disc1.place(hand1.draw());
    disc2.place(hand2.draw());


}

bool war::compare() 
{
    //Defining variables
    int val1 = disc1.peek().val, val2 = disc2.peek().val;

    if (val1 == 0)

}
