#include "sudoku.h"
#include <iostream>

using namespace std;

int main ( )
{
    sudoku puzzle;
    ifstream fin("..\\test.txt");
    vector<int> temp = { 1, 2, 3, 4,
                         3, 4, 1, 2,
                         2, 1, 4, 3,
                         4, 3, 2, 0 };


    puzzle.resize ( 9 );
    puzzle.puzzIn ( fin );
    puzzle.solve ( 1 );
    temp = puzzle.cont ( 1 );

    for ( int i = 0; i < 81; ++i )
    {
        cout << temp.at ( i );
        
        if ( ( i % 9 ) == 8 )
        {
            cout << endl;
        }
        else
        {
            cout << " ";
        }
    }
}