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

RobotomyRequestForm::RobotomyRequestForm( std::string target) : Form(target, 72, 45)
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

void RobotomyRequestForm::beExecuted( std::string target )
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

void RobotomyRequestForm::execute( Bureaucrat const & executor )
{
	if (_isSigned == 0)
		throw RobotomyRequestForm::NotSignedException();
	if (executor.getGrade() > this->getGradeToExec())
		throw RobotomyRequestForm::GradeTooLowException();
	this->beExecuted( _name );
}