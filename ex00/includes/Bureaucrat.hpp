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
    Bureaucrat & operator=( Bureaucrat const & )

    std::string const getName( void );
    int getGrade( void );
};

#endif