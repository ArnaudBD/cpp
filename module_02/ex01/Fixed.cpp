#include "Fixed.hpp"

Fixed::Fixed( int const RawBits )
{
	std::cout << "Int constructor called" << std::endl;
	this->_RawBits = RawBits << this->_decimalBits;
	return ;
}

Fixed::Fixed( float const RawBits )
{
	std::cout << "Float constructor called" << std::endl;
	this->_RawBits = roundf(RawBits * pow(2, this->_decimalBits));
}

Fixed::Fixed() : _RawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
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

float Fixed::toFloat( void ) const
{
	return ((float)this->_RawBits / (float)(1 << this->_decimalBits));
}

int Fixed::toInt( void ) const
{
	return (this->_RawBits / pow(2, this->_decimalBits));
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs )
{
	o << rhs.toFloat();
	return (o);
}

Fixed & Fixed::operator=( Fixed const & inst )
{
	std::cout << "Copy asignement operator called" << std::endl;
	this->_RawBits = inst.getRawBits();

	return *this;
}

Fixed Fixed::operator+( Fixed const & inst ) const
{
	return Fixed(this->_RawBits + inst.getRawBits());
}

Fixed Fixed::operator-( Fixed const & inst ) const
{
	return Fixed(this->_RawBits - inst.getRawBits());
}