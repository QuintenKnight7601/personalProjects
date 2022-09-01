#pragma once

#ifndef __WAR__H__
#define __WAR__H__

class war : protected playingCards {
    playingCards deck, hand1, hand2, disc1, disc2;
    int rounds = 0;

public:
    war();
    war(playingCards deckIn);
    ~war();

    bool setHands();
    bool playGame();
    bool playRound();
    int compare(); //Positive if right hand side is greater, negative if left hand side is greater
};


#endif