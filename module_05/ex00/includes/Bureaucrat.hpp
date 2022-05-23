#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <string>

class Bureaucrat
{
private:
    std::string const _name;
    int _grade;
public:
    Bureaucrat();
    ~Bureaucrat();
    Bureaucrat( Bureaucrat const & );
    Bureaucrat & operator=( Bureaucrat const & );
    Bureaucrat & operator++( void );

    std::string const getName( void );
    int getGrade( void );



    class GradeTooHighException : std::exception
    {
    private:
        /* data */
    public:
        GradeTooHighException(/* args */);
        ~GradeTooHighException();
    };
    class GradeTooLowException : std::exception
    {
    private:
        /* data */
    public:
        GradeTooLowException(/* args */);
        ~GradeTooLowException();
    };

    
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & );

#endif