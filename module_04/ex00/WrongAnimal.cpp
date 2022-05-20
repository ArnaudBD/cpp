#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	_type = "";
	std::cout << "Constructor called for WrongAnimal" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructor called for WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal( WrongAnimal const & copy )
{
	*this = copy;
	return ;
}

WrongAnimal & WrongAnimal::operator=( WrongAnimal const & rhs )
{
	this->_type = rhs._type;
	return (*this);
}

std::string WrongAnimal::getType( void ) const
{
	return (this->_type);
}

void WrongAnimal::makeSound( void ) const
{
	std::cout << "Wrong Animal sound" << std::endl;
}