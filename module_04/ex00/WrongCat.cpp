#include "WrongCat.hpp"
WrongCat::WrongCat()
{
	this->_type = "WrongCat";
}

WrongCat::~WrongCat()
{
}

WrongCat::WrongCat( WrongCat const & copy )
{
	*this = copy;
	return ;
}

WrongCat & WrongCat::operator=( WrongCat const & rhs )
{
	this->_type = rhs._type;
	return (*this);
}

void WrongCat::makeSound( void ) const
{
	std::cout << "Meeeeeeeeow" << std::endl;
}