#pragma once

#include "framework.h"
#include <iostream>
#include <iomanip>
#include <vector>

#ifndef SUITS
#define SUITS
namespace suits
{
    enum Enum { club, diamond, heart, spade };
    Enum fromInt ( const int val );

    inline Enum fromInt ( const int val )
    {
        if ( val == 0 )
            return club;
        if ( val == 1 )
            return diamond;
        if ( val == 2 )
            return heart;
        if ( val == 3 )
            return spade;
        return Enum ( );
    }
}

#endif

#ifndef __CARD__H__
#define __CARD__H__

class playingCards
{


public:

    struct card
    {
        suits::Enum suit;     //Current card suit
        int value;      //Current card value
    };

    //Con/Deconstructors
    playingCards ( );
    playingCards ( playingCards& orig );
    ~playingCards ( );

    //Manipulation
    bool reset ( );                     //Reset to default
    bool clear ( );                     //Clear deck
    bool fill ( );                      //Fill deck with missing cards
    bool push ( card ins );             //Insert card on front
    bool _push ( card ins );            //Insert card on end
    bool insert ( card ins, int pos );  //Insert card at position
    card pop ( );                       //Remove front item
    card _pop ( );                      //Remove end item
    card remove ( card val );           //Remove specific card
    card remove ( int pos );            //Remove card at position
    bool shuffle ( );                   //Randomizes cards in deck

    //Information
    card top ( );
    card bottom ( );
    int find ( card val );
    card at ( int pos );
    bool empty ( );
    int size ( );
    const bool operator==( const playingCards& rhs );
    friend bool operator==( const card& lhs, const card& rhs );
    friend bool operator!=( const card& lhs, const card& rhs );
    

protected:
    struct _card
    {
        card val;
        _card* next = nullptr;
        _card* prev = nullptr;
    };

    _card* headptr = nullptr;
    bool used[52] = { false };    //order: c, d, h, s
};


#endif