#ifndef HARL_CPP
# define HARL_CPP
# include <string>
# include <iostream>

class Harl
{
private:
    void debug( void );
    void info( void );
    void warning( void );
    void error( void );

    void* level[4] = 
public:
    Harl(/* args */);
    ~Harl();

    void complain( std::string level );
};

#endif