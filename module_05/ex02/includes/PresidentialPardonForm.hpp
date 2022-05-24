#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include <string>
# include "Bureaucrat.hpp"
class Bureaucrat;

class PresidentialPardonForm : public Form
{
private:
	PresidentialPardonForm();
public:
	PresidentialPardonForm( std::string );
	~PresidentialPardonForm();
	PresidentialPardonForm( PresidentialPardonForm const & );
	PresidentialPardonForm & operator=( PresidentialPardonForm const & );
	void beSigned ( Bureaucrat & );
	void beExecuted( std::string target );
	virtual void execute( Bureaucrat const & executor );
};

#endif