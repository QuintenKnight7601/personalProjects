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
    bool place ( cardStruct cardIn, int pos = 0, bool reverse = false );            //Insert card on front
    bool draw ( cardStruct& cardOut, int pos = 0, bool reverse = false );                       //Remove front item
    bool shuffle ( );                   //Randomizes cards in deck

    //Information
    cardStruct peek(int pos = 0, bool reverse = false);
    int seek (cardStruct card, bool reverse = false );
    bool empty();
    int size();

    //Conversion


    //Operator
    const bool operator==( const cards& rhs );
    friend bool operator==( const cardStruct& lhs, const cardStruct& rhs );
    friend bool operator!=( const cardStruct& lhs, const cardStruct& rhs );
    

protected:
    bool used[52] = { false };
};


#endif