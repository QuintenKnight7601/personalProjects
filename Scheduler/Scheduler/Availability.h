#pragma once


#ifndef __Availability__H__
#define __Availability__H__

#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

enum days
{
    EVERYDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY
};

struct _time
{
    int hour = -1;
    int minute = -1;
    days day = EVERYDAY;
};


class availability
{
public:
    
    //Con\Deconstructors
    availability ( );
    ~availability ( );


    //Manipulation
    bool insert ( _time from, _time to );
    bool remove ( int pos );
    bool change ( int pos, _time from, _time to );
    bool clear ( );
    bool optimize ( );


    //Information
    bool empty ( );
    bool size ( );
    bool contains ( _time value );
    bool print ( );
    bool output ( ostream out );

    


private:
    struct card
    {
        _time from;
        _time to;
    };

    vector <card> cardList;


};


#endif