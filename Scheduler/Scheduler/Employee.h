#pragma once

#include "Availability.h"

using namespace std;

#ifndef __Employee__H__
#define __Employee__H__

class employee
{
public:

    //Con\Deconstructors
    employee ( );
    ~employee ( );


    //Manipulation
    bool firstName ( string name );
    bool lastName ( string name );
    bool id ( string id );
    bool avoid ( string id );
    bool unavoid ( string id );
    bool seek ( string id );
    bool unseek ( string id );
    bool unavailable ( int from, int to );
    bool available ( int from, int to );


    //Information




protected:
    struct card
    {
        string fName;
        string lName;
        string ID;
        vector <string> avoid;
        vector <string> seek;
        
    };



private:
    


};


#endif