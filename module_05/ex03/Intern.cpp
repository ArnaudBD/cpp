#include "Intern.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern( Intern const & copy )
{
    *this = copy;
    return ;
}

Intern & Intern::operator=( Intern const & rhs )
{
    return (*this);
}