#include "WrongDog.hpp"
WrongDog::WrongDog()
{
	this->_type = "WrongDog";
}

WrongDog::~WrongDog()
{
}

WrongDog::WrongDog( WrongDog const & copy )
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