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
	~ShrubberyCreationForm();
	ShrubberyCreationForm( ShrubberyCreationForm const & );
	ShrubberyCreationForm & operator=( ShrubberyCreationForm const & );
	void beSigned ( Bureaucrat & );
	void beExecuted( std::string target );
	virtual void execute( Bureaucrat const & executor );
};

#endif