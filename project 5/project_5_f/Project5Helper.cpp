#include "Project5Helper.h"

Project5Helper::Project5Helper()
{
    
}

bool Project5Helper::endsWithPM(const string & mainStr )
{
    return( endsWith( mainStr, "PM" ) );
}

bool Project5Helper::endsWith(const string & mainStr, const string & toMatch)
{
    bool result( false );
    if(mainStr.size() >= toMatch.size() &&
       mainStr.compare(mainStr.size() - toMatch.size(), toMatch.size(), toMatch) == 0)
    {
        result = true;
    }
    return( result );
}


bool Project5Helper::startsWith(const string & mainStr, const string & toMatch)
{
    bool result( false );
    // string::find returns 0 if toMatch is found at starting
    if(mainStr.find(toMatch) == 0)
    {
        result = true;
    }
    return( result );
}


bool Project5Helper::startsWithOrchestra(const string & mainStr )
{
    return( startsWith( mainStr, "Orchestra" ) );
}
