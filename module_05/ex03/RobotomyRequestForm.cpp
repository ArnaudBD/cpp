#include "RobotomyRequestForm.hpp"
#include "Form.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>

class Form;

RobotomyRequestForm::RobotomyRequestForm()
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm( std::string target) : Form("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & copy ) : Form(copy)
{
	*this = copy;
	return ;
}
RobotomyRequestForm & RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	this->_isSigned = rhs.getIsSigned();
	return *this;
}

void RobotomyRequestForm::beSigned( Bureaucrat & bureaucrat )
{
	if (this->getGradeToSign() >= bureaucrat.getGrade())
		this->_isSigned = true;
	else
		throw RobotomyRequestForm::GradeTooLowException();
}

void RobotomyRequestForm::beExecuted( std::string target ) const
{
	std::cout << "vrrrrrrr" << std::endl;
	std::cout << "VRRRRRRRRRRRRR" << std::endl;
	srand(time(NULL));
	int r = rand() % 2;
	if (r)
		std::cout << target << " was successfully robotomiesed" << std::endl;
	else
		std::cout << "Robotomy failed on " << target << std::endl;
}

void RobotomyRequestForm::execute( Bureaucrat const & executor ) const
{
	if (_isSigned == 0)
		throw RobotomyRequestForm::NotSignedException();
	if (executor.getGrade() > this->getGradeToExec())
		throw RobotomyRequestForm::GradeTooLowException();
	this->beExecuted( _target );
}

std::string RobotomyRequestForm::getTarget( void ) const
{
	return this->_target;
}

// std::ostream & operator<<( std::ostream & o , Form const & rhs )
// {
// 	o	<< "\t- Name: " << rhs.getName() << std::endl
// 		<< "\t- Signed: " << (rhs.getIsSigned() ? "yes" : "no") << std::endl
// 		<< "\t- Grade to sign: " << rhs.getGradeToSign() << std::endl
// 		<< "\t- Grade to execute: " << rhs.getGradeToExec() << std::endl
// 		<< "\t- Target: " << rhs.getTarget() << std::endl;
// 	return (o);
// }