#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
private:
	int _RawBits;
	int const static _decimalBits = 8;
public:
	Fixed();
	~Fixed();

	Fixed( Fixed const & );
	Fixed & operator=( Fixed const & );

	int getRawBits( void ) const;
	void setRawBits( int const );
};
#endif