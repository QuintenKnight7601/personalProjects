#pragma once

#include "framework.h"


#ifndef __CARDS__H__
#define __CARDS__H__

typedef CARDS::cards cardStruct;

class cards : public vector<CARDS::cards>
{


public:

    //Con/Deconstructors
    cards ( );
    ~cards ( );

    //Manipulation
    bool set();                         //Fill deck with missing cards
    bool reset ( );                     //Reset to default
    bool clear ( );                     //Clear deck
    bool place (CARDS::cards cardIn, int pos = 0, bool reverse = false );            //Insert card on front
    bool draw (CARDS::cards& cardOut, int pos = 0, bool reverse = false );                       //Remove front item
    bool shuffle ( );                   //Randomizes cards in deck

    //Information
    const CARDS::cards peek(int pos = 0, bool reverse = false);
    const int seek (CARDS::cards card, bool reverse = false );
    const bool empty();
    const int size();

    //Conversion


    //Operator
    const bool operator==( const cards rhs );
    friend bool operator==( const CARDS::cards& lhs, const CARDS::cards rhs );
    friend bool operator!=( const CARDS::cards& lhs, const CARDS::cards& rhs );
    

protected:
};

bool operator==(const CARDS::cards& lhs, const CARDS::cards rhs)
{
    if (lhs.suit == rhs.suit && lhs.val == rhs.val)
        return true;
    return false;
}

bool operator!=(const CARDS::cards& lhs, const CARDS::cards& rhs)
{
    if (lhs.suit == rhs.suit && lhs.val == rhs.val)
        return false;
    return true;
}


#endif