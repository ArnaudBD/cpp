#ifndef SHUBBERYCREATIONFORM_HPP
# define SHUBBERYCREATIONFORM_HPP
# include <string>
# include "Bureaucrat.hpp"
class Bureaucrat;

class ShrubberyCreationForm : public Form
{
private:
	std::string const _name;
	bool _isSigned;
	int const _gradeToSign;
	int const _gradeToExec;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm( std::string);
	~ShrubberyCreationForm();
	ShrubberyCreationForm( ShrubberyCreationForm const &);
	ShrubberyCreationForm & operator=( ShrubberyCreationForm const &);


	std::string getName( void ) const;
	bool getIsSigned( void ) const;
	int getGradeToSign( void ) const;
	int getGradeToExec( void ) const;
	void beSigned ( Bureaucrat );
	void beExecuted( std::string target );

	class GradeTooHighException : public std::exception
    {
    public:
        virtual const char* what() const throw()
        {
            return ("ShrubberyCreationForm: Grade is too high");
        };
    };

    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char* what() const throw()
        {
            return ("ShrubberyCreationForm: Grade is too low");
        };
    };
};

std::ostream & operator<<( std::ostream & o, ShrubberyCreationForm const & );
#endif