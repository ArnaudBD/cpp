#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed
{
private:
	int _RawBits;
	int const static _decimalBits = 8;
public:
	Fixed();
	~Fixed();

	Fixed( int const );
	Fixed( float const );
	Fixed( Fixed const & );
	Fixed & operator=( Fixed const & );

	int getRawBits( void ) const;
	void setRawBits( int const );

	float toFloat( void ) const;
	int toInt( void ) const;
};

std::ostream & operator<<(std::ostream & o, Fixed const & );

#endif