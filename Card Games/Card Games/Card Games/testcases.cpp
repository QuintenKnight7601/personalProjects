#include "framework.h"
#include "card.h"
#include "..\..\..\catch.hpp"

TEST_CASE ( "Constructor/Deconstructor" )
{
    playingCards deck;
}

TEST_CASE ( "push - Sections" )
{
    playingCards deck;

    SECTION ( "Initial push" )
    {
        playingCards::card temp;
        playingCards::card temp2;
        temp.suit = suits::diamond;
        temp.value = 1;

        deck.push ( temp );

        temp2 = deck.top ( );

        REQUIRE ( temp == temp2 );
    }

    SECTION ( "Double push" )
    {
        playingCards::card temp;
        playingCards::card temp2;
        temp.suit = suits::diamond;
        temp.value = 1;

        deck.push ( temp );

        temp.suit = suits::heart;
        temp.value = 8;

        deck.push ( temp );

        temp2 = deck.top ( );

        REQUIRE ( temp == temp2 );

    }
}