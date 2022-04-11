#pragma once

#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

#ifndef __sudoku__H__
#define sudokuDLL_API __declspec(dllexport)

class sudokuDLL_API sudoku
{
public:
    //Constructors/Deconstructor
    sudoku ( );
    sudoku ( sudoku& s );
    ~sudoku ( );

    //Manipulation
    bool resize ( int size );
    void clear ( );
    bool solve ( int num );

    //Information
    int size ( );
    int numPoss ( );
    vector<int> cont ( int pos );
    vector<vector<int>> cont ( );
    vector<int> puzz ( );

    //Input/Output
    bool puzzIn ( vector<int> in );
    bool puzzIn ( ifstream& in, string filename = "" );
    bool templateOut ( ostream& out );
    bool templateOut ( vector<int> out );
    bool templateOut ( ofstream& out, string filename = "" );


private:
    struct puzzle
    {
        vector<vector<int>> cont;
        vector<vector<bool>> usedH;
        vector<vector<bool>> usedV;
        vector<vector<bool>> usedC;
        int possNum = 0;
        int size = 0;
        puzzle* next;
    };

    //Function prototypes
    bool is_valid ( int val, int pos );
    void clearPuzz ( puzzle& poss );
    bool permute ( puzzle& temp, int pos = 0 );

    puzzle* tailptr;
    puzzle basePuzz;
};

#endif