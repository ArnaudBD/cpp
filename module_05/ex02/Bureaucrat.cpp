#include "Bureaucrat.hpp"
#include "Form.hpp"
class Form;

Bureaucrat::Bureaucrat() : _name("NoName")
{
}

Bureaucrat::Bureaucrat( std::string name ) : _name(name)
{
}

Bureaucrat::Bureaucrat( std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade > 150)
	{
		throw Bureaucrat::GradeTooHighException::exception();
	}
	if (grade < 1)
	{
		throw Bureaucrat::GradeTooLowException::exception();
	}
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
	return *this;
}

Bureaucrat & Bureaucrat::operator++( void )
{
	if (this->getGrade() > 150)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	if (this->getGrade() <= 1)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	this->_grade--;

	return (*this);
}

Bureaucrat & Bureaucrat::operator--( void )
{
	if (this->getGrade() >= 150)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	if (this->getGrade() < 1)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	this->setGrade( _grade + 1 );

	return (*this);
}

std::string const Bureaucrat::getName( void ) const
{
	return this->_name;
}

int Bureaucrat::getGrade( void ) const
{
	return this->_grade;		
}

void Bureaucrat::setGrade( int newGrade )
{
	this->_grade = newGrade;
	return ;
}

std::ostream & operator<<( std::ostream & o, Bureaucrat const & rhs )
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return (o);
}

void Bureaucrat::signForm( Form & form )
{
	form.beSigned( *this );
	if (form.getIsSigned())
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	else
		std::cout << this->getName() << " coudn't sign " << form.getName() << " because his grade is " << this->getGrade() << std::endl;
}
