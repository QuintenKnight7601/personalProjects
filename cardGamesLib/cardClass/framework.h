#pragma once

#ifndef __CARDSFRAMEWORK__H__
#define __CARDSFRAMEWORK__H__

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

namespace CARDS
{
    enum class suits { club, diamond, heart, spade }; //Lowest to highest value

    suits fromInt(const int val);
    suits fromChar(const char val);

    struct _card
    {
        int val; //value from 1 to 13, 1 being ace, and 13 being king
        suits suit;

        inline _card() { val = 0; suit = suits::club; };
        inline _card(int val) {
            fromInt(val);
        }

        //Function to convert from int to _cards
        inline _card fromInt(const int input) {

            //Calculate card value and suit from input number and return
            val = (input%52) % 13;
            suit = CARDS::fromInt((input%52) / 13);
            return *this;
        }


        friend ostream& operator<<(ostream& out, const _card& rhs);
        friend ifstream& operator>>(ifstream& in, _card& rhs);
    };


    inline ostream& operator<< (ostream& out, const _card& rhs) {
        //Output card value
        out << setfill(' ') << setw(2) << rhs.val;

        //Ouput suit
        if (rhs.suit == suits::club)
            out << "C";
        else if (rhs.suit == suits::diamond)
            out << "D";
        else if (rhs.suit == suits::heart)
            out << "H";
        else if (rhs.suit == suits::spade)
            out << "S";

        return out;
    }

    inline ifstream& operator>> (ifstream& in, _card& rhs) {
        //Defining variables
        int tempInt;
        
        //Read in values
        in >> tempInt;
        rhs.fromInt(tempInt);

        return in;
    }

    inline suits fromInt(const int input)  //Converts int to enum value
    {
        if (input == 0)
            return suits::club;
        if (input == 1)
            return suits::diamond;
        if (input == 2)
            return suits::heart;
        if (input == 3)
            return suits::spade;
        return suits();
    }

    inline suits fromChar(const char input) {
        if (toupper(input) == 'C')
            return suits::club;
        if (toupper(input) == 'D')
            return suits::diamond;
        if (toupper(input) == 'H')
            return suits::heart;
        if (toupper(input) == 'S')
            return suits::spade;
        return suits();
    }
}

#endif