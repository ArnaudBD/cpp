#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
class ShrubberyCreationForm;

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
    (void)rhs;
    return (*this);
}

Form* Intern::_newShrubbery( std::string target )
{
    return new ShrubberyCreationForm( target );
}
Form* Intern::_newRobotomy( std::string target )
{
    return new RobotomyRequestForm( target );
}
Form* Intern::_newPresidential( std::string target )
{
    return new PresidentialPardonForm( target );
}

Form* Intern::makeForm( std::string name, std::string target )
{
    std::string nameList[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};

    Form* (Intern::*functionList[])( std::string ) = {&Intern::_newShrubbery, &Intern::_newRobotomy, &Intern::_newPresidential};
    for (int i = 0 ; i < 3 ; i++)
    {
        if (nameList[i] == name)
        {
            std::cout << "Intern creates " << name << std::endl;
            Form* (Intern::*theOne)( std::string ) = functionList[i];
            return (this->*theOne)(target);
        }
    }
    std::cout << "Error: the name does not exist" << std::endl;
    return NULL;
}