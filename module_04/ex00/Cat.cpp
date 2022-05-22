#include "Cat.hpp"
Cat::Cat()
{
	this->_type = "Cat";
	std::cout << "Constructor called for " << this->_type << std::endl; 
}

Cat::~Cat()
{
	std::cout << "Destructor called for " << this->_type << std::endl; 
}

Cat::Cat( Cat const & copy ) : Animal()
{
	*this = copy;
	return ;
}

Cat & Cat::operator=( Cat const & rhs )
{
	this->_type = rhs._type;
	return (*this);
}

void Cat::makeSound( void ) const
{
	std::cout << "Meeeeeeeeow" << std::endl;
}