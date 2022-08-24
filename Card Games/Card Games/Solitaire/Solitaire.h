#pragma once

#include "framework.h"

#ifndef __SOLITAIRE__H__
#define __SOLITAIRE__H__

class solitaire : protected playingCards
{
    struct game
    {
        queue <card> stock;
        queue <card> discard;
        stack <card> suits[4];
        stack <card> tableau[7];
    };

public:
    solitaire ( );
    solitaire ( _card deck );
    ~solitaire ( );

    //Manipulation functions
    bool reset ( );

    //Tabluau functions
    bool mTableau ( int x, int y, int to );   //x left to right, y starts top, to placement point


    //Suit functions
    bool mSuit ( int x, int y );            //x left to right, y starts top

    //Stock functions
    bool rStock ( );
    bool mStock ( );

    //Information
    


private:


};


#endif