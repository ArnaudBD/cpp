#include "Form.hpp"

Form::Form() : _isSigned(0), _gradeToSign(100), _gradeToExec(100)
{
	if (this->getGradeToSign() > 150 || this->getGradeToExec() > 150)
	{
		throw Form::GradeTooLowException();
	}
	if (this->getGradeToSign() < 1 || this->getGradeToExec() < 1)
	{
		throw Form::GradeTooHighException();
	}
}

Form::~Form()
{
}

Form::Form( std::string name, int gradeToSign, int gradeToExec) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (this->getGradeToSign() > 150 || this->getGradeToExec() > 150)
	{
		throw Form::GradeTooHighException();
	}
	if (this->getGradeToSign() < 1 || this->getGradeToExec() < 1)
	{
		throw Form::GradeTooLowException();
	}
}

Form::Form( Form const & copy ) : _name(copy._name), _isSigned(copy._isSigned), _gradeToSign(copy._gradeToSign), _gradeToExec(copy._gradeToExec)
{
	*this = copy;
	return ;
}
Form & Form::operator=( Form const & rhs )
{
	this->_isSigned = rhs.getIsSigned();
	return *this;
}

std::string Form::getName( void ) const
{
	return this->_name;
}

bool Form::getIsSigned( void ) const
{
	return this->_isSigned;
}
int Form::getGradeToSign( void ) const
{
	return this->_gradeToSign;
}
int Form::getGradeToExec( void ) const
{
	return this->_gradeToExec;
}

std::ostream & operator<<( std::ostream & o , Form const & rhs )
{
	o	<< "\t- Name: " << rhs.getName() << std::endl
		<< "\t- Signed: " << (rhs.getIsSigned() ? "yes" : "no") << std::endl
		<< "\t- Grade to sign: " << rhs.getGradeToSign() << std::endl
		<< "\t- Grade to execute: " << rhs.getGradeToExec() << std::endl;
	return (o);
}