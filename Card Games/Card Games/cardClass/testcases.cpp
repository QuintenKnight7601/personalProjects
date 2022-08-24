#include "framework.h"
#include "card.h"
#include "..\..\..\catch.hpp"

TEST_CASE ( "Constructor/Deconstructor" )
{
    playingCards deck;
}

TEST_CASE ( "reset - with sections (also tests fill/empty functions)" )
{
    playingCards deck1;
    playingCards deck2;
    bool temp;

    SECTION ( "Empty reset" )
    {
        deck1.reset ( );
        deck2.fill ( );

        temp = ( deck1 == deck2 );
        REQUIRE ( temp );
    }

    SECTION ( "Filled reset" )
    {
        deck1.fill ( );
        deck1.reset ( );
        deck2.fill ( );

        temp = ( deck1 == deck2 );
        REQUIRE ( temp );
    }

    SECTION ( "Partial full reset" )
    {
        playingCards::card card = { suits::diamond, 2 };

        deck1.push ( card );

        deck1.reset ( );
        deck2.fill ( );

        temp = ( deck1 == deck2 );
        REQUIRE ( temp );
    }
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

TEST_CASE ( "pop - with sections" )
{

}

TEST_CASE ( "remove - with sections" )
{

}

TEST_CASE ( "shuffle - with sections" )
{

}

TEST_CASE ( "top - with sections" )
{

}

TEST_CASE ( "bottom - with sections" )
{

}

TEST_CASE ( "find - with sections" )
{

}

TEST_CASE ( "at - with sections" )
{

}

TEST_CASE ( "empty - with sections" )
{

}

TEST_CASE ( "size - with sections" )
{

}

TEST_CASE ( "operators - with sections" )
{

}