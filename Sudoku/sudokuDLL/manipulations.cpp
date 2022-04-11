#include "pch.h"
#include "sudoku.h"


bool sudoku::resize ( int size )
{
    //Defining Variables
    int i = 0, j = 0;

    //If the square root of size is not an integer or solutions have been made return false
    if ( int ( sqrt ( size ) ) != double ( sqrt ( size ) ) )
    {
        return false;
    }

    //If solutions are made return false
    if ( tailptr != nullptr )
    {
        return false;
    }

    if ( basePuzz.size != 0 )
    {
        clear ( );
    }

    //Resize base vectors
    basePuzz.size = size;
    basePuzz.cont.resize ( size, vector<int> ( size, 0 ) );
    basePuzz.usedC.resize ( size, vector<bool> ( size, false ) );
    basePuzz.usedH.resize ( size, vector<bool> ( size, false ) );
    basePuzz.usedV.resize ( size, vector<bool> ( size, false ) );

    return true;
}


void sudoku::clear ( )
{
    //Defining pointer
    puzzle* tempptr = tailptr;

    //While there are puzzles allocated
    while ( tailptr != nullptr )
    {
        //Set tempptr to tailptr and increment
        tempptr = tailptr;
        tailptr = tailptr->next;

        //Delete teapptr
        delete tempptr;
    }

    //If the base is still 0
    if ( basePuzz.size == 0 )
    {
        return;
    }

    //Reset basePuzz
    basePuzz.size = 0;
    basePuzz.cont.clear ( );
    basePuzz.usedC.clear ( );
    basePuzz.usedH.clear ( );
    basePuzz.usedV.clear ( );
    basePuzz.cont.resize ( 0, vector<int> ( 0 ) );
    basePuzz.usedC.resize ( 0, vector<bool> ( 0 ) );
    basePuzz.usedH.resize ( 0, vector<bool> ( 0 ) );
    basePuzz.usedV.resize ( 0, vector<bool> ( 0 ) );

    return;
}


bool sudoku::solve ( int num )
{
    //Defining variables
    puzzle temppuzz;
    puzzle* tempptr = tailptr;

    while ( basePuzz.possNum < num )
    {
        //Clear the puzzle
        clearPuzz ( temppuzz );

        //If the permutation was not completed return false
        if ( !permute ( temppuzz ) )
        {
            return false;
        }

        //If no puzzle possibilities yet
        if ( tailptr == nullptr )
        {
            //Create a new node at the tailptr
            tailptr = new ( nothrow ) puzzle;
            tempptr = tailptr;
        }
        else
        {
            //Create a new node at next and increment
            tempptr->next = new ( nothrow ) puzzle;
            tempptr = tempptr->next;
        }

        //Move temppuzz values to tempptr and fix circle
        *tempptr = temppuzz;
        tempptr->next = tailptr;
    }

    //All permutations were completed, return true
    return true;
}