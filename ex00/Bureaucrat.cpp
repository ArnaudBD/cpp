#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat( Bureaucrat const & copy )
{
	*this = copy;
	return ;
}

Bureaucrat & Bureaucrat::operator=( Bureaucrat const & rhs )
{
	this->_grade = rhs.getGrade();
	this->_name = rhs.getName();
	return (*this);
}

Bureaucrat & Bureaucrat::operator++( void )
{
	
}

std::string const Bureaucrat::getName( void )
{
	return this->_name;
}

int Bureaucrat::getGrade( void )
{
	return this->_grade;
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & );
