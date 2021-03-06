#include "Dog.hpp"
Dog::Dog()
{
	this->_type = "Dog";
	std::cout << "Constructor called for " << this->_type << std::endl; 
}

Dog::~Dog()
{
	std::cout << "Destructor called for " << this->_type << std::endl; 
}

Dog::Dog( Dog const & copy ) : Animal()
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