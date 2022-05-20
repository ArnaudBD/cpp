#include "Cat.hpp"
Cat::Cat()
{
	this->_type = "Cat";
}

Cat::~Cat()
{
}

Cat::Cat( Cat const & copy )
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