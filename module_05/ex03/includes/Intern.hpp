#ifndef INTERN_HPP
# define INTERN_HPP
# include "Form.hpp"
class Form;

class Intern
{
private:
    
public:
    Intern();
    ~Intern();
    Intern( Intern const & );
    Intern & operator=( Intern const & );

    Form* makeForm( std::string name, std::string target );
};

#endif