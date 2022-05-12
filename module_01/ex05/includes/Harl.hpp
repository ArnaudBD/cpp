#ifndef HARL_CPP
# define HARL_CPP
# include <string>
# include <iostream>

class Harl
{
private:
    typedef void (Harl::*functionTab) ( void );
    void debug( void );
    void info( void );
    void warning( void );
    void error( void );

public:
    Harl(/* args */);
    ~Harl();

    void complain( std::string level );
};

#endif