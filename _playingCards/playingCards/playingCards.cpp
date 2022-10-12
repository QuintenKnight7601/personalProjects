#include "pch.h"
#include "playingCards.h"

playingCards::playingCards(bool setBool, bool shuffleBool)
{
    if (setBool) {
        set();
        if (shuffleBool) {
            shuffle();
        }
    }
}

playingCards::playingCards(playingCards* deck, bool shuffleBool)
{
    assign(deck->begin(), deck->end());
    if (shuffleBool) {
        shuffle();
    }
}

playingCards::~playingCards()
{
}

