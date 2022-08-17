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

bool playingCards::reset ( )
{
    //Clear deck
    if ( !clear ( ) )
        return false;

    //Refill deck
    if ( !fill ( ) )
        return false;

    return true;
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

bool playingCards::fill ( )
{
    //Defining variables
    card temp;

    //For each card in a deck
    for ( int i = 0; i < 52; ++i )
    {
        //If the card is not used
        if ( used[i] )
        {
            //Add card to the deck
            temp.suit = suits::fromInt ( i / 13 );
            temp.value = i % 13;

            if ( !push ( temp ) )
            {
                return false;
            }
        }
    }

    return true;
}

bool playingCards::push ( card val )
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
    headptr->val = val;

    //Update used array
    used[( int(val.suit) * 13 ) + val.value ] = true;

    return true;
}

bool playingCards::_push ( card val )
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

    //Navigate to the end
    while ( temp->next != nullptr )
    {
        temp = temp->next;
    }

    //Create a new card
    temp->next = new( nothrow )_card;

    if ( temp->next == nullptr )
        return false;

    //Set values
    temp->next->prev = temp;
    temp->next->val = val;

    //Update used array
    used[( int ( val.suit ) * 13 ) + val.value] = true;

    return true;
}

bool playingCards::insert ( card val, int pos )
{
    //Defining variables
    _card* curptr = headptr;
    _card* prevptr = headptr;

    //If empty create the first card
    if ( empty ( ) )
    {
        headptr = new ( nothrow ) _card;

        if ( headptr == nullptr )
            return false;

        curptr = headptr;
        prevptr = curptr;
    }
    else //Navigate to position, or end of cards
    {
        for ( int i = 0; curptr != nullptr && i < pos; ++i )
        {
            prevptr = curptr;
            curptr = curptr->next;
        }
    }

    //Update used array
    used[( int ( val.suit ) * 13 ) + val.value] = true;

    //If at the end of the list
    if ( curptr == nullptr ) 
    {
        //Create new card
        prevptr->next = new ( nothrow ) _card;

        if ( prevptr->next == nullptr )
            return false;

        curptr = prevptr->next;
        curptr->prev = prevptr;

        //Copy card in
        curptr->val = val;

        return true;
    }

    //If at the front of the cards
    if ( curptr == headptr )
    {
        //Create new card
        curptr->prev = new ( nothrow ) _card;

        if ( curptr->prev == nullptr )
            return false;

        headptr = curptr->prev;
        headptr->next = curptr;

        //Copy value in
        headptr->val = val;

        return true;
    }

    //Create new card between pointers
    curptr->prev = new ( nothrow ) _card;

    if ( curptr->prev == nullptr )
        return false;

    curptr->prev->next = curptr;
    curptr->prev->prev = prevptr;
    prevptr->next = curptr->prev;

    //Copy value in
    curptr->prev->val = val;

    return true;
}

playingCards::card playingCards::pop ( )
{
    //Defining variables
    _card* temp = headptr;
    card out;

    //Check if empty
    if ( empty ( ) )
        return card ( );

    //Remove front card
    headptr = headptr->next;
    headptr->prev = nullptr;

    //Copy value and unallocate memory
    out = temp->val;
    delete temp;

    //Update used array
    used[( int ( out.suit ) * 13 ) + out.value] = false;

    return out;
}

playingCards::card playingCards::_pop ( )
{
    //Defining variables
    _card* temp = headptr;
    card out;

    //Check if empty
    if ( empty ( ) )
        return card ( );

    //Navigate to the last item and remove it
    while ( temp->next != nullptr )
        temp = temp->next;

    temp->prev->next = nullptr;

    //Copy value and unallocate memory
    out = temp->val;
    delete temp;

    //Update used array
    used[( int ( out.suit ) * 13 ) + out.value] = false;

    return out;
}

playingCards::card playingCards::remove ( card val )
{
    //Defining variables
    _card* temp = headptr;
    card out;

    //Checking if empty
    if ( empty ( ) )
        return card ( );

    //Navigate until the card is found
    while ( temp != nullptr && val != temp->val )
    {
        temp = temp->next;
    }

    //If card is not found
    if ( temp == nullptr )
        return card();

    //Remove card from list
    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;

    //Copy values and unallocate memory
    out = temp->val;
    delete temp;

    //Update used array
    used[( int ( out.suit ) * 13 ) + out.value] = false;

    return out;
}

playingCards::card playingCards::remove ( int pos )
{
    //Defining variables
    _card* temp = headptr;
    card out;

    //Checking if empty
    if ( empty ( ) )
        return card ( );

    //Navigate until the card is found
    for ( int i = 0; temp != nullptr && i < pos; ++i )
        temp = temp->next;

    //If card is not found
    if ( temp == nullptr )
        return card ( );

    //Remove card from list
    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;

    //Copy values and unallocate memory
    out = temp->val;
    delete temp;

    //Update used array
    used[( int ( out.suit ) * 13 ) + out.value] = false;

    return out;
}

bool playingCards::shuffle ( )
{
    //Defining variables
    _card* ptr = headptr;
    _card** addresses;
    int num = size();
    int i = 0;
    int a;
    int b;

    srand ( int ( time ( 0 ) ) );

    //Check if empty
    if ( empty ( ) )
        return true;

    //Set address array size and copy addresses in
    addresses = new ( nothrow ) _card*[ num ];

    if ( addresses == nullptr )
        return false;

    for ( int i = 0; ptr != nullptr && i < num; ++i )
    {
        addresses[i] = ptr;
        ptr = ptr->next;
    }

    //Randomize cards for each card in deck
    for ( i = 0; i < num; ++i )
    {
        do
        {
            a = rand ( ) % num;
            b = rand ( ) % num;
        }
        while ( a == b );

        swap ( addresses[a], addresses[b] );
    }

    return true;
}

playingCards::card playingCards::top ( )
{
    //Return value
    return headptr->val;
}

playingCards::card playingCards::bottom ( )
{
    //Defining variables
    _card* temp = headptr;

    //Check if empty
    if ( empty ( ) )
        return card ( );

    //Navigate to last card
    while ( temp->next != nullptr )
        temp = temp->next;

    return temp->val;
}

int playingCards::find ( card val )
{
    //Defining variables
    _card* temp = headptr;
    int i = 0;

    //Check if empty
    if ( empty ( ) )
        return -1;

    //Navigate to card
    while ( temp != nullptr && temp->val != val )
    {
        temp = temp->next;
        ++i;
    }

    //If card was not found
    if ( temp == nullptr )
        return -1;

    return i;
}

playingCards::card playingCards::at ( int pos )
{
    //Defining variables
    _card* temp = headptr;

    //Check if empty
    if ( empty ( ) )
        return card ( );

    //Navigate to position
    for ( int i = 0; temp != nullptr && i < pos; ++i )
        temp = temp->next;

    //If overstepped
    if ( temp == nullptr )
        return card ( );

    return temp->val;
}

bool playingCards::empty ( )
{
    //If no cards return true
    if ( headptr == nullptr )
        return true;

    return false;
}

int playingCards::size ( )
{
    //Defining variables
    _card* temp = headptr;
    int i = 0;

    //Check if empty
    if ( empty ( ) )
        return 0;

    //Count cards
    while ( temp != nullptr )
    {
        ++i;
        temp = temp->next;
    }

    return i;
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

bool operator!=( const playingCards::card& lhs, const playingCards::card& rhs )
{
    //If the suits are equal
    if ( lhs.suit != rhs.suit )
    {
        //If the values are equal return true
        if ( lhs.value != rhs.value )
        {
            return true;
        }
    }

    return false;
}
