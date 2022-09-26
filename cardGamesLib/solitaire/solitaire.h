#pragma once

#include "framework.h"

#ifndef __SOLITAIRE__H__
#define __SOLITAIRE__H__

class solitaire : protected cards {
    class foundationClass:public cards {
        CARD::suits suit;

    public:
        foundationClass(CARD::suits value = CARD::suits()) {
            suit = value;
        }
        ~foundationClass() {}

        inline bool change(CARD::suits value) { suit = value; return true; };
    };
    class tableauClass:public cards {
    public:
        tableauClass();
        ~tableauClass();
    };

    tableauClass tableau[7];
    foundationClass clubFoun(CARD::suits::club);
    foundationClass diamFoun(CARD::suits::diamond);
    foundationClass hearFoun(CARD::suits::heart);
    foundationClass spadFoun(CARD::suits::spade);
    cards discard;
    cards moving;

public:
    //Con/Deconstructors
    solitaire(cards deck);
    solitaire(bool prepare = false);
    ~solitaire();

    //Game Format functions
    bool prepare();
    bool checkValues();
    bool checkColors();
    bool checkStack();


    //Manipulation Functions
    bool clear(bool prepare = false);
    bool setTableau();
    bool discard();
    bool moveCard(bool checkStack = true, bool checkPlacement = true);
    bool moveStack(int pos, bool checkStack = true, bool checkPlacement = true);

    //Information Functions




    friend bool startSolitaire();
};

bool startSolitaire() {
    return true;
}





#endif