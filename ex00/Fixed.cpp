#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_RawBits = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_RawBits;
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawbits called" << std::endl;
	this->_RawBits = raw;
	return ;
}

Fixed::Fixed( Fixed const & copy )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
	return ;
}

Fixed & Fixed::operator=( Fixed const & inst )
{
	std::cout << "Copy asignement operator called" << std::endl;
	this->_RawBits = inst.getRawBits();

	return *this;
}