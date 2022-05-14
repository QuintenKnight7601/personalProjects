#include "Availability.h"

availability::availability ( )
{

}

availability::~availability ( )
{

}

bool availability::insert ( _time from, _time to )
{
    //Defining variables
    card tempCard;

    //If a time value is not set
    if ( from.minute < 0 || from.minute > 59 || from.hour < 1 || from.hour > 12
        || to.minute < 0 || to.minute > 59 || to.hour < 1 || to.hour > 12 )
        return false;

    //If invalid time values
    if ( from.minute  )

    //Add times to card
    tempCard.from = from;
    tempCard.to = to;

    //Add card to list
    cardList.push_back ( tempCard );

    return true;
    
}


bool availability::remove ( int pos )
{
    //Check if card exists
    if ( cardList.size ( ) < ( pos + 1 ) )
        return false;

    //Erase card
    cardList.erase ( cardList.begin() + pos );

    return true;
}

bool availability::change ( int pos, _time from, _time to )
{
    //Check if card exists
    if ( cardList.size ( ) < ( pos + 1 ) )
        return false;

    //If a time value is not set
    if ( from.minute < 0 || from.minute > 59 || from.hour < 1 || from.hour > 12
        || to.minute < 0 || to.minute > 59 || to.hour < 1 || to.hour > 12 )
        return false;

    //Change contents
    cardList.at ( pos ).from = from;
    cardList.at ( pos ).to = to;

    return true;

}