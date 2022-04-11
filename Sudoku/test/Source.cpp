#include "sudoku.h"
#include <iostream>

using namespace std;

int main ( )
{
    //Defining variables
    sudoku puzzle;
    int selection;

    selection = menu ( puzzle );
    
}


int menu ( sudoku puzzle )
{
    //Defining variables
    int selection;

    cout << "---Sudoku DLL tester---";
    cout << "\n\n";
    cout << "  Puzzle size [" << puzzle.size ( ) << ", " << puzzle.size ( );
    cout << "]\n\n";
    cout << "  1) export template\n";
    cout << "  2) import puzzle file (must match size of puzzle)\n";
    cout << "  3) resize puzzle (sqrt of size must be an integer)\n";
    cout << "  4) solve puzzle\n\n";

    cin.getline ( (char*) selection );

}