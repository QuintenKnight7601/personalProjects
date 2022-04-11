#include "sudoku.h"
#include <iostream>
#include <iomanip>

using namespace std;

int menu ( sudoku puzzle );

int main ( )
{
    //Defining variables
    sudoku puzzle;
    ofstream fout;
    ifstream fin;
    vector<vector<int>> contents;
    int selection, size, x, i;
    bool cont = true;

    while ( cont )
    {
        selection = menu ( puzzle );

        if ( selection == 1 )
        {
            puzzle.templateOut ( fout, "template.txt" );
        }
        else if ( selection == 2 )
        {
            puzzle.puzzIn ( fin, "template.txt" );
        }
        else if ( selection == 3 )
        {
            cout << "Input size: ";
            cin >> size;
            cout << "\n";
            puzzle.resize ( size );
        }
        else if ( selection == 4 )
        {

            cout << "Number of solutions: ";
            cin >> size;
            cout << "\n";
            if ( puzzle.solve ( size ) )
            {
                cout << size << " solutions created\n\n";
            }
            else
            {
                cout << "Ran out of solutions\n"
                    << puzzle.numPoss ( ) << " solutions created\n\n";
            }
        }
        else if ( selection == 5 )
        {
            contents = puzzle.cont ( );
            for ( x = 0; x < puzzle.numPoss(); ++x )
            {
                for ( i = 0; i < int ( contents[x].size ( ) ); ++i )
                {
                    cout << setw ( 4 ) << right << contents[x][i];

                    if ( ( i % puzzle.size ( ) ) == ( puzzle.size ( ) - 1 ) )
                    {
                        cout << endl;
                    }
                }
                cout << endl;
            }
        }
        else if ( selection == 0 )
        {
            cont = false;
        }
    }
    
    fout.close ( );
    fin.close ( );
}


int menu ( sudoku puzzle )
{
    //Defining variables
    int selection;

    cout << "---Sudoku DLL tester---";
    cout << "\n\n";
    cout << "  Puzzle size " << puzzle.size ( ) << "x" << puzzle.size ( );
    cout << "\n\n";
    cout << "  1) export template (exports template for current size)\n";
    cout << "  2) import puzzle file (must match size of puzzle)\n";
    cout << "  3) resize puzzle (sqrt of size must be an integer)\n";
    cout << "  4) solve puzzle\n";
    cout << "  5) view solutions\n";
    cout << "\n";
    cout << "  0) exit\n\n";
    cout << "  Menu option: ";

    cin >> selection;

    cout << "\n";

    if ( selection < 0 || selection > 5 )
    {
        selection = menu ( puzzle );
    }

    return selection;
}