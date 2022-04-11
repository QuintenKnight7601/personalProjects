#include "pch.h"
#include "sudoku.h"


bool sudoku::puzzIn ( vector<int> in )
{
    //Defining variables
    int i = 0, j = 0, x = 0, y = 0, c = 0;
    int size = basePuzz.size;

    //If vector does not match puzzle size return false
    if ( sqrt ( in.size ( ) ) != size )
    {
        return false;
    }

    //Loop until at the end of the vector
    for ( i = 0; i < int ( in.size ( ) ); ++i )
    {
        //Update x, y, and cell positions
        x = ( i % size );
        y = ( i / size );
        c = ( ( ( y / int ( sqrt ( size ) ) ) * int ( sqrt ( size ) ) )
            + ( x / int ( sqrt ( size ) ) ) );

        //If vector position is a puzzle value
        if ( in.at ( i ) != 0 )
        {
            //If the value is not valid return false
            if ( in.at ( i ) <= basePuzz.size && !is_valid ( in.at ( i ), i ) )
            {
                return false;
            }

            //Update puzzle value and used values
            basePuzz.cont[y][x] = in.at ( i );
            basePuzz.usedH[y][( in[i] - 1 )] = true;
            basePuzz.usedV[x][( in[i] - 1 )] = true;
            basePuzz.usedC[c][( in[i] - 1 )] = true;
        }
    }

    return true;
}


bool sudoku::puzzIn ( ifstream& in, string filename )
{
    //Defining variables
    vector<int> puzzVals;
    int tempint, i, x, y, c;
    int size = basePuzz.size; 
    int sizeVect = int ( pow ( basePuzz.size, 2 ) );
    int sizeCell = int ( sqrt ( basePuzz.size ) );

    if ( !in.is_open ( ) )
    {
        if ( filename == "" )
        {
            return false;
        }

        in.open ( filename );

        if ( !in.is_open ( ) )
        {
            return false;
        }
    }

    in.seekg ( ios::beg );

    while ( !in.eof ( ) )
    {
        in >> tempint;

        puzzVals.push_back ( tempint );
    }

    if ( sizeVect != puzzVals.size( ) )
    {
        return false;
    }


    //Loop until at the end of the vector
    for ( i = 0; i < sizeVect; ++i )
    {
        //Update x, y, and cell positions
        x = ( i % size );
        y = ( i / size );
        c = ( ( int ( y / sizeCell ) * sizeCell )
            + ( x / sizeCell ) );

        //If vector position is a puzzle value
        if ( puzzVals.at ( i ) != 0 )
        {
            //If the value is not valid return false
            if ( puzzVals.at ( i ) > size && !is_valid ( puzzVals.at ( i ), i ) )
            {
                return false;
            }

            //Update puzzle value and used values
            basePuzz.cont[y][x] = puzzVals.at ( i );
            basePuzz.usedH[y][( puzzVals[i] - 1 )] = true;
            basePuzz.usedV[x][( puzzVals[i] - 1 )] = true;
            basePuzz.usedC[c][( puzzVals[i] - 1 )] = true;
        }
    }

    return true;
}


bool sudoku::templateOut ( vector<int> out )
{
    if ( !out.empty ( ) )
    {
        out.clear ( );
    }

    out.resize ( int ( pow ( basePuzz.size, 2 ) ) );

    return true;
}


bool sudoku::templateOut ( ofstream& out )
{
    //Defining variables
    int i = 0, j = 0, size = basePuzz.size;


    if ( !out.is_open ( ) )
    {
        return false;
    }

    out.seekp ( ios::beg );

    for ( i = 0; i < size; ++i )
    {
        for ( j = 0; j < ( size - 1 ); ++j )
        {
            out << "0 ";
        }

        out << "0\n";
    }

    return true;
}


bool sudoku::templateOut ( ofstream& out, string filename )
{
    //Defining variables
    int i = 0, j = 0, size = basePuzz.size;

    if ( !out.is_open ( ) )
    {
        out.open ( filename, ios::out | ios::trunc );

        if ( !out.is_open ( ) )
        {
            return false;
        }
    }

    out.seekp ( ios::beg );

    for ( i = 0; i < size; ++i )
    {
        for ( j = 0; j < ( size - 1 ); ++j )
        {
            out << "0 ";
        }

        out << "0\n";
    }

    return true;
}