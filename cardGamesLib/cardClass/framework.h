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

    struct _card
    {
        int val; //value from 1 to 13, 1 being ace, and 13 being king
        suits suit;

        //Function to convert from int to _cards
        inline _card fromInt(const int input) {
            _card tempCard;
            tempCard.val = input % 13;
            tempCard.suit = CARDS::fromInt(input / 13);
            return tempCard;
        }

        friend ostream& operator<<(ostream& out, const _card& rhs);
    };

    inline ostream& operator<< (ostream& out, const _card& rhs) {
        out << setfill(' ') << setw(2) << rhs.val;

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

    inline suits fromInt(int input)  //Converts int to enum value
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
}

#endif