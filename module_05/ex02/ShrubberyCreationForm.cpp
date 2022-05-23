#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : _isSigned(0), _gradeToSign(145), _gradeToExec(137)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string name) : _name(name), _gradeToSign(145), _gradeToExec(137)
{
	if (this->getGradeToSign() >= 150 || this->getGradeToExec() >= 150)
	{
		throw ShrubberyCreationForm::GradeTooHighException();
	}
	if (this->getGradeToSign() < 1 || this->getGradeToExec() < 1)
	{
		throw ShrubberyCreationForm::GradeTooLowException();
	}
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & copy ) : _name(copy._name), _gradeToSign(copy._gradeToSign), _gradeToExec(copy._gradeToExec)
{
	*this = copy;
	return ;
}
ShrubberyCreationForm & ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	// this = new tmp(rhs.getName(), rhs.getGradeToSign(), rhs.getGradeToExec());
	// _name = rhs._name;
	// this->_gradeToSign = rhs._gradeToSign;
	// this->_gradeToExec = rhs.getGradeToExec();
	this->_isSigned = rhs.getIsSigned();
	return *this;
}

std::string ShrubberyCreationForm::getName( void ) const
{
	return this->_name;
}

bool ShrubberyCreationForm::getIsSigned( void ) const
{
	return this->_isSigned;
}
int ShrubberyCreationForm::getGradeToSign( void ) const
{
	return this->_gradeToSign;
}
int ShrubberyCreationForm::getGradeToExec( void ) const
{
	return this->_gradeToExec;
}
void ShrubberyCreationForm::beSigned( Bureaucrat bureaucrat )
{
	if (this->getGradeToSign() >= bureaucrat.getGrade())
		this->_isSigned = 1;
	else
		throw ShrubberyCreationForm::GradeTooLowException();
}

std::ostream & operator<<( std::ostream & o , ShrubberyCreationForm const & rhs )
{
	o	<< "\t- Name: " << rhs.getName() << std::endl
		<< "\t- Signed: " << (rhs.getIsSigned() ? "yes" : "no") << std::endl
		<< "\t- Grade to sign: " << rhs.getGradeToSign() << std::endl
		<< "\t- Grade to execute: " << rhs.getGradeToExec() << std::endl;
	return (o);
}

void ShrubberyCreationForm::beExecuted( std::string target )
{
	
}
