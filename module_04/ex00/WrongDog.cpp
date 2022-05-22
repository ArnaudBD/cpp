#include "WrongDog.hpp"
WrongDog::WrongDog()
{
	this->_type = "WrongDog";
	std::cout << "Constructor called for " << this->_type << std::endl;
}

WrongDog::~WrongDog()
{
	std::cout << "Destructor called for " << this->_type << std::endl;
}

WrongDog::WrongDog( WrongDog const & copy ) : WrongAnimal()
{
	*this = copy;
	return ;
}

WrongDog & WrongDog::operator=( WrongDog const & rhs )
{
	this->_type = rhs._type;
	return (*this);
}

void WrongDog::makeSound( void ) const
{
	std::cout << "Woof!" << std::endl;
}