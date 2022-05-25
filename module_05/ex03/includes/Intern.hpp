#ifndef INTERN_HPP
# define INTERN_HPP
# include "Form.hpp"
class Form;

class Intern
{
private:
    Form* _newShrubbery( std::string target );
    Form* _newRobotomy( std::string target );
    Form* _newPresidential( std::string target );
    
public:
    Intern();
    virtual ~Intern();
    Intern( Intern const & );
    Intern & operator=( Intern const & );

    Form* makeForm( std::string name, std::string target );
};

#endif