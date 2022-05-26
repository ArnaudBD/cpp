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

PresidentialPardonForm::PresidentialPardonForm( std::string target) : Form("PresidentialPardonForm", 25, 5), _target(target)
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

void PresidentialPardonForm::beExecuted( std::string target ) const
{
	std::cout << target << " was pardoned by Zaphod Beeblebrox" << std::endl;
}

void PresidentialPardonForm::execute( Bureaucrat const & executor ) const
{
	if (_isSigned == 0)
		throw PresidentialPardonForm::NotSignedException();
	if (executor.getGrade() > this->getGradeToExec())
		throw PresidentialPardonForm::GradeTooLowException();
	this->beExecuted( _target );
}

std::string PresidentialPardonForm::getTarget( void ) const
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