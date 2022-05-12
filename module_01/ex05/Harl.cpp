#include "Harl.hpp"

Harl::Harl(/* args */)
{
}

Harl::~Harl()
{
}

void    Harl::complain( std::string level )
{
    std::string levelList[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*complainList[])( void ) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    for (size_t i = 0; i < 4 ; i++)
    {
        void (Harl::*theOne)( void ) = complainList[i];
        if (level == levelList[i])
            (this->*theOne)();
    }

}

void    Harl::debug( void )
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void    Harl::info( void )
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void    Harl::warning( void )
{
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void    Harl::error( void )
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
