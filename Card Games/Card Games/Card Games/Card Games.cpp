#define CATCH_CONFIG_RUNNER

#include "framework.h"
#include "..\..\..\catch.hpp"

const bool RUNCATCH = true;

int main ( )
{
    Catch::Session session;
    int result;

    if ( RUNCATCH )
    {
        result = session.run ( );
        if ( result != 0 )
        {
            cout << "Test cases didn't pass." << endl;
            return result;
        }
    }
}