#include "framework.h"
#include "cards.h"

cards::cards()
{
    set();

    return;
}

cards::~cards()
{
}

bool cards::set()
{
    if (!empty())
    {

    }

    for (int i = 0; i < 52; ++i)
    {
        place(i);
    }
}

bool cards::reset()
{
    if (clear())
        return set();
    return false;
}

bool cards::clear()
{
    vector::clear();

    if (!empty())
        return false;

    return true;
}

bool cards::place(CARDS::cards cardIn, int pos, bool reverse)
{
    //Defining variables
    int initSize = size();

    

    if (empty())
    {
        insert(begin(), cardIn);
        if (empty())
            return false;
        return true;
    }

    if (pos > initSize)
    {
        push_back(cardIn);

        if (initSize == size())
            return false;
        return true;
    }

    insert(begin() + pos, cardIn);

    if (initSize == size())
        return false;
    return true;
}

CARDS::cards cards::draw( int pos, bool reverse)
{
    //Defining variables
    int initSize = size();
    int cardPos = pos;
    CARDS::cards tempCard;

    if (empty())
        return CARDS::cards();

    if (pos > size())
    {
        if (reverse)
        {
            tempCard = front();
            erase(begin());
        }
        else
        {
            tempCard = back();
            erase(end());
        }

        return tempCard;
    }

    if (reverse)
    {
        cardPos = size() - pos;
    }

    tempCard = at(cardPos);

    erase(begin() + cardPos);

    return tempCard;
}


bool cards::shuffle()
{
    //Defining variables
    cards temp = *this;
    bool track[52] = { false };
    int num = size();
    int i = 0;
    int to;
    int numUsed = 0;

    srand(int(time(0)));

    //Check if empty
    if (empty())
        return true;

    //Randomize cards for each card in deck
    for (i = 0; i < num; ++i)
    {
        numUsed = 0;
        to = rand() % (num - i);
        for (int n = 0; n < to; ++n)
        {
            if (track[n])
            {
                --n;
                ++numUsed;
            }
        }

        to += numUsed;

        at(to) = temp.at(i);
    }

    return true;
}


const cardStruct cards::peek(int pos, bool reverse)
{
    int cardPos = pos;

    if (pos > size())
        return cardStruct();

    if (reverse)
        cardPos = size() - pos;

    return at(cardPos);
}

const int cards::seek(CARDS::cards card, bool reverse)
{
    int deckSize = size();

    if (empty())
        return -1;

    for (int i = 0; i < deckSize; ++i)
    {
        if (at(i) == card)
        {
            if (reverse)
                return (deckSize - i);
            return i;
        }
    }

    return -1;
}

const bool cards::empty()
{
    return vector::empty();
}

const int cards::size()
{
    return int(vector::size());
}

const bool cards::operator==(cards rhs)
{
    int deckSize = size();

    if (empty())
    {
        if (rhs.empty())
            return true;
        return false;
    }
    else if (rhs.empty())
        return false;

    if (deckSize != rhs.size())
        return false;

    for (int i = 0; i < deckSize; ++i)
        if (at(i) != rhs.at(i))
            return false;

    return true;
}
