#include "PresidentialPardonForm.hpp"
#include "Form.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>

class Form;

PresidentialPardonForm::PresidentialPardonForm()
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm( std::string target) : Form(target, 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & copy ) : Form(copy)
{
	*this = copy;
	return ;
}
PresidentialPardonForm & PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs )
{
	this->_isSigned = rhs.getIsSigned();
	return *this;
}

void PresidentialPardonForm::beSigned( Bureaucrat & bureaucrat )
{
	if (this->getGradeToSign() >= bureaucrat.getGrade())
		this->_isSigned = true;
	else
		throw PresidentialPardonForm::GradeTooLowException();
}

void PresidentialPardonForm::beExecuted( std::string target )
{
	std::cout << target << " was pardoned by Zaphod Beeblebrox" << std::endl;
}

void PresidentialPardonForm::execute( Bureaucrat const & executor )
{
	if (_isSigned == 0)
		throw PresidentialPardonForm::NotSignedException();
	if (executor.getGrade() > this->getGradeToExec())
		throw PresidentialPardonForm::GradeTooLowException();
	this->beExecuted( _name );
}