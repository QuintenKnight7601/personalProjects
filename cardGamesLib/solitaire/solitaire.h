#pragma once

#include "framework.h"

#ifndef __SOLITAIRE__H__
#define __SOLITAIRE__H__

class solitaire : protected cards {

public:
    solitaire(cards deck);
    solitaire(bool fill = false);
};





#endif