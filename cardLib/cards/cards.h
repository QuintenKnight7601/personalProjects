#pragma once

#include "framework.h"


#ifndef __CARDS__H__
#define __CARDS__H__

template <typename YT>
class cards : public queue<YT>
{


public:

    //Con/Deconstructors
    cards ( );
    cards ( cards& orig );
    ~cards ( );

    //Manipulation
    bool reset ( );                     //Reset to default
    bool clear ( );                     //Clear deck
    bool fill ( );                      //Fill deck with missing cards
    bool push ( card ins ) : push_back();             //Insert card on front
    bool _push ( card ins );            //Insert card on end
    bool insert ( card ins, int pos );  //Insert card at position
    card pop ( ) : pop_front;                       //Remove front item
    card _pop ( );                      //Remove end item
    card remove ( card val );           //Remove specific card
    card remove ( int pos );            //Remove card at position
    bool shuffle ( );                   //Randomizes cards in deck

    //Information
    card front() : front();
    card back() : back();
    int find ( card val );
    card at ( int pos );
    bool empty() : empty();
    int size ( ) : size();
    const bool operator==( const cards& rhs );
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