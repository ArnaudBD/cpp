#include "Form.hpp"

Form::Form() : _isSigned(0), _gradeToExec(10), _gradeToSign(20)
{
}

Form::~Form()
{
}

Form::Form( std::string name, int const gradeToSign, int const gradeToExec ) : _name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
}

Form::Form( Form const & copy )
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
int Form::getGradeToSign( void )
{
	return this->_gradeToSign;
}
int Form::getGradeToExec( void )
{
	return this->_gradeToExec;
}
void Form::beSigned( Bureaucrat )
{

}

Form & operator<<( std::ostream & o , Form & rhs )
{
	o	<< "\t- Name: " << rhs.getName() << std::endl
		<< "\t- Signed: " << (rhs.getIsSigned() ? "yes" : "no") << std::endl
		<< "\t- Grade to sign: " << rhs.getGradeToSign() << std::endl
		<< "\t- Grade to execute: " << rhs.getGradeToExec() << std::endl;
}
