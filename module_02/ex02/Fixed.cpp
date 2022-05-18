#include "Fixed.hpp"

Fixed::Fixed( int const RawBits )
{
	this->_RawBits = RawBits << this->_decimalBits;
	return ;
}

Fixed::Fixed( float const RawBits )
{
	this->_RawBits = roundf(RawBits * pow(2, this->_decimalBits));
}


Fixed::Fixed() : _RawBits(0)
{
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits( void ) const
{
	return this->_RawBits;
}

void Fixed::setRawBits( int const raw )
{
	this->_RawBits = raw;
	return ;
}

Fixed::Fixed( Fixed const & copy )
{
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
	// this->_RawBits = _RawBits + (1 << _decimalBits);
	this->setRawBits(this->_RawBits + 1);
	return *this;
}

Fixed Fixed::operator++( int )
{
	Fixed old(this->toFloat());
	// this->_RawBits = _RawBits + (1 << _decimalBits);
	this->setRawBits(this->_RawBits + 1);
	return (old);
}

Fixed const & Fixed::min(Fixed const & former, Fixed const & latter)
{
	return ((former < latter) ? former : latter);
}
Fixed & Fixed::min(Fixed & former, Fixed & latter)
{
	return ((former < latter) ? former : latter);
}

Fixed & Fixed::max(Fixed & former, Fixed & latter)
{
	return ((former > latter) ? former : latter);
}

Fixed const & Fixed::max(Fixed const & former, Fixed const & latter)
{
	return ((former > latter) ? former : latter);
}