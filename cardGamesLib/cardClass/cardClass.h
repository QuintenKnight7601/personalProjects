#pragma once

#include "framework.h"

#ifndef __CARDS__H__
#define __CARDS__H__

const int DECK_SIZE = 52;

class cards : protected vector<CARDS::_card>
{


public:
    typedef CARDS::_card card;

    //Con/Deconstructors
    cards ( bool fill = false );
    ~cards ( );

    //Manipulation                    //Fill deck with missing cards
    bool reset ( );                     //Reset to default
    bool clear ( );                     //Clear deck
    bool place (CARDS::_card cardIn, int pos = 0, bool reverse = false );            //Insert card on front
    CARDS::_card draw ( int pos = 0, bool reverse = false );                       //Remove front item
    bool shuffle ( );                   //Randomizes cards in deck, current iteration is biased

    //Information
    const CARDS::_card peek(int pos = 0, bool reverse = false);
    const int seek (CARDS::_card card, bool reverse = false );
    const bool empty();
    const int size() const;

    //Conversion


    //Operator
    const bool operator==( const cards rhs );
    friend ostream& operator<<( ostream& out, const cards& rhs);
    friend bool operator==( const CARDS::_card lhs, const CARDS::_card rhs );
    friend bool operator!=( const CARDS::_card lhs, const CARDS::_card rhs );
    

protected:
};

inline ostream& operator<<(ostream& out, const cards& rhs)
{
    int size = rhs.size();

    for (int i = 0; i < size; ++i)
    {
        out << rhs.at(i) << " ";

        if ((i % 13) == 12)
            out << endl;
    }

    return out;
}

inline bool operator==(const CARDS::_card lhs, const CARDS::_card rhs)
{
    if (lhs.suit == rhs.suit && lhs.val == rhs.val)
        return true;
    return false;
}

inline bool operator!=(const CARDS::_card lhs, const CARDS::_card rhs)
{
    if (lhs.suit == rhs.suit && lhs.val == rhs.val)
        return false;
    return true;
}


#endif