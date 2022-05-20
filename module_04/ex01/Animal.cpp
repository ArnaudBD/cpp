#include "Animal.hpp"

Animal::Animal()
{
	_type = "";
}

Animal::~Animal()
{
}

Animal::Animal( Animal const & copy )
{
	*this = copy;
	return ;
}

Animal & Animal::operator=( Animal const & rhs )
{
	this->_type = rhs._type;
	return (*this);
}

std::string Animal::getType( void ) const
{
	return (this->_type);
}

void Animal::makeSound( void ) const
{
	std::cout << "Animal sound" << std::endl;
}