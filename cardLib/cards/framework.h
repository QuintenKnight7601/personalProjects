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

    struct cards 
    {
        int val; //value from 1 to 13, 1 being ace, and 13 being king
        suits suit;
    };


    inline suits fromInt(const int val)  //Converts int to enum value
    {
        if (val == 0)
            return suits::club;
        if (val == 1)
            return suits::diamond;
        if (val == 2)
            return suits::heart;
        if (val == 3)
            return suits::spade;
        return suits();
    } 
}

#endif