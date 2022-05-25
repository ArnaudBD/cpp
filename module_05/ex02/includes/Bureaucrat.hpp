#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <string>
# include <iostream>
# include "Form.hpp"
class Form;

class Bureaucrat
{
private:
    std::string const _name;
    int _grade;
public:
    Bureaucrat();
    Bureaucrat( std::string );
    Bureaucrat( std::string, int );
    ~Bureaucrat();
    Bureaucrat( Bureaucrat const & );
    Bureaucrat & operator=( Bureaucrat const & );
    Bureaucrat & operator++( void );
    Bureaucrat & operator--( void );

    std::string const getName( void ) const;
    int getGrade( void ) const;
    void setGrade( int );

    void signForm( Form & );
    void executeForm( Form const & form );



    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char* what() const throw()
        {
            return ("Grade is too high");
        };
    };

    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char* what() const throw()
        {
            return ("Grade is too low");
        };
    };

    
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & );

#endif