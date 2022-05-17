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

Fixed & Fixed::operator=( Fixed const & inst )
{
	std::cout << "Copy asignement operator called" << std::endl;
	this->_RawBits = inst.getRawBits();

	return *this;
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs )
{
	o << rhs.toFloat();
	return (o);
}

Fixed Fixed::operator+( Fixed const & inst ) const
{
	Fixed res;
	res.setRawBits(this->getRawBits() + inst.getRawBits());
	return res;
}

Fixed Fixed::operator-( Fixed const & inst ) const
{
	Fixed res;
	res.setRawBits(this->getRawBits() - inst.getRawBits());
	return res;
}

Fixed Fixed::operator*( Fixed const & inst ) const
{
	Fixed res(this->toFloat() * inst.toFloat());
	return res;
}

Fixed Fixed::operator/( Fixed const & inst ) const
{
	if (inst.toFloat())
	{	
		// res.setRawBits(this->getRawBits() / inst.getRawBits());
		Fixed res(this->toFloat() / inst.toFloat());
		return res;
	}
	std::cout << "Error: you can't divide by zero!" << std::endl;
	Fixed res(INFINITY);
	return (res);
}

bool Fixed::operator==( Fixed const & inst) const
{
	if (this->getRawBits() == inst.getRawBits())
		return (1);
	return (0);
}

bool Fixed::operator>( Fixed const & inst) const
{
	if (this->getRawBits() > inst.getRawBits())
		return (1);
	return (0);
}

bool Fixed::operator>=( Fixed const & inst) const
{
	if (this->getRawBits() == inst.getRawBits())
		return (1);
	return (0);
}

bool Fixed::operator<=( Fixed const & inst) const
{
	if (this->getRawBits() <= inst.getRawBits())
		return (1);
	return (0);
}

bool Fixed::operator<( Fixed const & inst) const
{
	if (this->getRawBits() < inst.getRawBits())
		return (1);
	return (0);
}

bool Fixed::operator!=( Fixed const & inst) const
{
	if (this->getRawBits() != inst.getRawBits())
		return (1);
	return (0);
}

Fixed & Fixed::operator++( void )
{
	int res;
	// std::cout << "_RawBits++ == " << _RawBits++ << std::endl;
	// std::cout << "_RawBits == " << _RawBits << std::endl; 
	res = this->getRawBits();
	res++;

	this->setRawBits(res);
	return *this;
}