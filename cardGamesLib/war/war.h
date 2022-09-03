#pragma once
#include "framework.h"

#ifndef __WAR__H__
#define __WAR__H__

class war : protected cards {

public:
    war(bool start = true);
    war(cards deckIn, bool start = true);
    ~war();

    //Game backend functions
    bool setHands();
    bool playGame();
    bool iterateGame();
    bool playRound();
    int compare(); //Positive if discard 1 is greater, negative if discard 2 is greater

    //Information functions
    bool winner(int& player);
    int numRounds();
    cards hand(bool player /*true for player 1, false for player 2*/);

protected:
    cards deck, hand1, hand2, disc1, disc2;
    int rounds = 0;
};

bool warGame();

#endif