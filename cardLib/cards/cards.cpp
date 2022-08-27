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
    return false;
}

bool cards::place(cardStruct cardIn, int pos, bool reverse)
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

bool cards::draw(cardStruct& cardOut, int pos, bool reverse)
{
    //Defining variables
    int initSize = size();


    if (empty())
        return false;

    if (reverse)
    {
        if (pos > initSize)
        {
            cardOut = front();
            erase(begin());
            
            if (initSize == size())
                return false;
            return true;
        }
    }


}
