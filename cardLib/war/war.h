#pragma once

#ifndef __WAR__H__
#define __WAR__H__

class war : protected cards {
    cards deck, hand1, hand2, disc1, disc2;
    int rounds = 0;

public:
    war();
    war(cards deckIn);
    ~war();

    bool warMain();
    bool setHands();
    bool playGame();
    bool playRound();
    bool compare();
};


#endif