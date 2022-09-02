#pragma once

#ifndef __CARDSFRAMEWORK__H__
#define __CARDSFRAMEWORK__H__

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

namespace CARDS
{
    enum class suits { club, diamond, heart, spade }; //Lowest to highest value

    suits fromInt(const int val);

    struct _cards
    {
        int val; //value from 1 to 13, 1 being ace, and 13 being king
        suits suit;

        //Function to convert from int to _cards
        inline _cards fromInt(const int input) {
            _cards tempCard;
            tempCard.val = input % 13;
            tempCard.suit = CARDS::fromInt(input / 13);
            return tempCard;
        }
    };


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