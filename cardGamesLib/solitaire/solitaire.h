#pragma once

#include "framework.h"

#ifndef __SOLITAIRE__H__
#define __SOLITAIRE__H__

class solitaire : protected cards {
    cards tableau[7];
    cards foundations[4];
    cards draw;
    cards discard;

public:
    //Con/Deconstructors
    solitaire(cards deck);
    solitaire(bool fill = false);
    ~solitaire();
};





#endif