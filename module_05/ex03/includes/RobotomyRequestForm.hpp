#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include <string>
# include "Bureaucrat.hpp"
class Bureaucrat;

class RobotomyRequestForm : public Form
{
private:
	std::string _target;
	RobotomyRequestForm();
public:
	RobotomyRequestForm( std::string );
	~RobotomyRequestForm();
	RobotomyRequestForm( RobotomyRequestForm const & );
	RobotomyRequestForm & operator=( RobotomyRequestForm const & );
	void beSigned ( Bureaucrat & );
	void beExecuted( std::string target );
	virtual void execute( Bureaucrat const & executor );
};

#endif