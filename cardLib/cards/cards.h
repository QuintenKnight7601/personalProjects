#pragma once

#include "framework.h"


#ifndef __CARDS__H__
#define __CARDS__H__

typedef CARDS::cards cardStruct;

class cards : public queue<CARDS::cards>
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
    bool push_front(cardStruct card);             //Insert card on front
    bool push_back (cardStruct card);            //Insert card on end
    bool insert ( cardStruct card, int pos );  //Insert card at position
    cardStruct pop_front ( );                       //Remove front item
    cardStruct pop_back ( );                      //Remove end item
    cardStruct remove (cardStruct card);           //Remove specific card
    cardStruct remove ( int pos );            //Remove card at position
    bool shuffle ( );                   //Randomizes cards in deck

    //Information
    cardStruct front();
    cardStruct back();
    int find (cardStruct card);
    cardStruct at ( int pos );
    bool empty();
    int size ( );

    //Conversion


    //Operator
    const bool operator==( const cards& rhs );
    friend bool operator==( const cardStruct& lhs, const cardStruct& rhs );
    friend bool operator!=( const cardStruct& lhs, const cardStruct& rhs );
    

protected:
};


#endif