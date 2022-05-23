#ifndef FORM_HPP
# define FORM_HPP
# include <string>
# include "Bureaucrat.hpp"
class Bureaucrat;

class Form
{
private:
	std::string const _name;
	bool _isSigned;
	int const _gradeToSign;
	int const _gradeToExec;
public:
	Form();
	// Form( std::string );
	~Form();
	Form( Form const &);
	Form & operator=( Form const &);


	std::string getName( void ) const;
	bool getIsSigned( void ) const;
	int getGradeToSign( void ) const;
	int getGradeToExec( void ) const;
	virtual void beSigned( Bureaucrat ) = 0;
	virtual void beExecuted( std::string target ) = 0;

	class GradeTooHighException : public std::exception
    {
    public:
        virtual const char* what() const throw()
        {
            return ("Form: Grade is too high");
        };
    };

    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char* what() const throw()
        {
            return ("Form: Grade is too low");
        };
    };
};

std::ostream & operator<<( std::ostream & o, Form const & );
#endif