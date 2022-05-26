#ifndef SHUBBERYCREATIONFORM_HPP
# define SHUBBERYCREATIONFORM_HPP
# include <string>
# include "Bureaucrat.hpp"
class Bureaucrat;

class ShrubberyCreationForm : public Form
{
private:
	std::string _target;
	ShrubberyCreationForm();
public:
	ShrubberyCreationForm( std::string );
	virtual ~ShrubberyCreationForm();
	ShrubberyCreationForm( ShrubberyCreationForm const & );
	ShrubberyCreationForm & operator=( ShrubberyCreationForm const & );
	void beSigned ( Bureaucrat & );
	void beExecuted( std::string target ) const;
	virtual void execute( Bureaucrat const & executor ) const;
	std::string getTarget( void ) const;
};

#endif