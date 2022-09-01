#pragma once

#include "framework.h"
#include "pch.h"

#ifdef  PLAYINGCARDS_EXPORTS 
/*Enabled as "export" while compiling the dll project*/
#define PLAYINGCARDSEXPORT __declspec(dllexport)  
#else
/*Enabled as "import" in the Client side for using already created dll file*/
#define PLAYINGCARDSEXPORT __declspec(dllimport)  
#endif

#ifndef __PLAYINGCARDS__H__
#define __PLAYINGCARDS__H__

class PLAYINGCARDSEXPORT playingCards : protected vector<CARDS::_cards>
{


public:
    typedef CARDS::_cards card;

    //Con/Deconstructors
    playingCards ( );
    ~playingCards ( );

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
    const bool operator==( const playingCards rhs );
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