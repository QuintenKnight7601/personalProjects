#include "framework.h"
#include "card.h"

playingCards::playingCards ( )
{

}

playingCards::playingCards ( playingCards& orig )
{
    //Defining variables
    _card* otemp = orig.headptr;    //Temporary pointer for orig list
    _card* ntemp = headptr;         //Temporary pointer for new list
    _card* ptemp = headptr;         //Previous pointer for new list

    //If the original is empty, return
    if ( orig.empty ( ) )
    {
        return;
    }

    //Copy the contents of used
    for ( int i = 0; i < 52; ++i )
    {
        used[i] = orig.used[i];
    }

    //Copy the first card
    headptr = new ( nothrow ) _card;
    ntemp = headptr;
    ptemp = headptr;
    ntemp->val = otemp->val;
    otemp = otemp->next;

    //Copy the contents of the cards
    while ( otemp != orig.headptr )
    {
        ntemp->next = new ( nothrow ) _card;
        ntemp = ntemp->next;
        ntemp->prev = ptemp;
        ntemp->val = otemp->val;
        otemp = otemp->next;
    }
}

playingCards::~playingCards ( )
{
    //Defining variables
    _card* ptr = headptr;

    //If list is empty return
    if ( empty ( ) )
    {
        return;
    }

    //Move through list until at end, deleting cards
    while ( headptr != nullptr )
    {
        headptr = headptr->next;
        delete ptr;
        ptr = headptr;
    }
}

bool playingCards::clear ( )
{
    //Defining variables
    _card* temp = headptr;

    //While there are cards, delete them
    while ( headptr != nullptr )
    {
        headptr = headptr->next;
        delete temp;
        temp = headptr;
    }

    //Set used to false
    for ( int i = 0; i < 52; ++i )
    {
        used[i] = false;
    }

    return true;
}

bool playingCards::push ( card ins )
{
    //Defining variables
    _card* temp = headptr;

    //If list is empty, create the first card
    if ( empty ( ) )
    {
        headptr = new ( nothrow ) _card;

        if ( headptr == nullptr )
            return false;
    }
    //Else add a new card at the beginning
    else
    {
        headptr->prev = new( nothrow ) _card;

        if ( headptr->prev == nullptr )
            return false;

        headptr = headptr->prev;
        headptr->next = temp;
    }

    //Copy contents into card
    headptr->val = ins;

    return true;
}

bool playingCards::_push ( card ins )
{
    //Defining variables
    _card* temp = headptr;
    _card* prev = headptr;

    //If list is empty, create the first card
    if ( empty ( ) )
    {
        headptr = new ( nothrow ) _card;

        if ( headptr == nullptr )
            return false;
    }
    else //traverse to end and add new card
    {
        while ( temp->next != nullptr )
        {
            temp = temp->next;
        }

        temp->next = new( nothrow )_card;

        if ( temp->next == nullptr )
            return false;

        prev = temp;
        temp = temp->next;
    }

    temp->prev = prev;
    temp->val = ins;
    return true;
}

playingCards::card playingCards::top ( )
{
    //Return value
    return headptr->val;
}

bool playingCards::empty ( )
{
    //If no cards return true
    if ( headptr == nullptr )
        return true;

    return false;
}

bool operator==( const playingCards::card& lhs, const playingCards::card& rhs )
{
    //If the suits are equal
    if ( lhs.suit == rhs.suit )
    {
        //If the values are equal return true
        if ( lhs.value == rhs.value )
        {
            return true;
        }
    }

    return false;
}