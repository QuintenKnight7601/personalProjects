#pragma once

#include "framework.h"
#include <iostream>
#include <iomanip>
#include <vector>

class playingCards
{


public:
    enum suits
    {
        diamond, heart, club, spade
    };

    struct card
    {
        suits suit;     //Current card suit
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

    //Information
    card top ( );
    card bot ( );
    int find ( card val );
    card at ( int pos );
    bool empty ( );
    friend bool operator==( const card& lhs, const card& rhs );
    

private:
    struct _card
    {
        card val;
        _card* next = nullptr;
        _card* prev = nullptr;
    };

    _card* headptr = nullptr;
    bool used[52] = { false };    //order: c, d, h, s
};