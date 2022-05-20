#include "Dog.hpp"
Dog::Dog()
{
	this->_type = "Dog";
}

Dog::~Dog()
{
}

Dog::Dog( Dog const & copy )
{
	*this = copy;
	return ;
}

Dog & Dog::operator=( Dog const & rhs )
{
	this->_type = rhs._type;
	return (*this);
}

void Dog::makeSound( void ) const
{
	std::cout << "Woof!" << std::endl;
}