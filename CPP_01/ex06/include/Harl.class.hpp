#ifndef _HARL_
#define _HARL_
#include <iostream>

class Harl
{
private:
    void debug( void );
    void info( void );
    void warning( void );
    void error( void );
    void other( void );
public:
    void complain( std::string level );
};

#endif