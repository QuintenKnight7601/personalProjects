#pragma once

#include "framework.h"

#ifndef __CARDS__H__
#define __CARDS__H__

class cards : protected vector<CARDS::_cards>
{


public:
    typedef CARDS::_cards card;

    //Con/Deconstructors
    cards ( );
    ~cards ( );

    //Manipulation
    bool set();                         //Fill deck with missing cards
    bool reset ( );                     //Reset to default
    bool clear ( );                     //Clear deck
    bool place (CARDS::_cards cardIn, int pos = 0, bool reverse = false );            //Insert card on front
    CARDS::_cards draw ( int pos = 0, bool reverse = false );                       //Remove front item
    bool shuffle ( );                   //Randomizes cards in deck

    //Information
    const CARDS::_cards peek(int pos = 0, bool reverse = false);
    const int seek (CARDS::_cards card, bool reverse = false );
    const bool empty();
    const int size();

    //Conversion


    //Operator
    const bool operator==( const cards rhs );
    friend bool operator==( const CARDS::_cards lhs, const CARDS::_cards rhs );
    friend bool operator!=( const CARDS::_cards lhs, const CARDS::_cards rhs );
    

protected:
};
bool operator==(const CARDS::_cards lhs, const CARDS::_cards rhs)
{
    if (lhs.suit == rhs.suit && lhs.val == rhs.val)
        return true;
    return false;
}

bool operator!=(const CARDS::_cards lhs, const CARDS::_cards rhs)
{
    if (lhs.suit == rhs.suit && lhs.val == rhs.val)
        return false;
    return true;
}


#endif