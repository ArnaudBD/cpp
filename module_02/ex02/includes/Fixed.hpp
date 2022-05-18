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
	Fixed operator+( Fixed const & ) const;
	Fixed operator-( Fixed const & ) const;
	Fixed operator*( Fixed const & ) const;
	Fixed operator/( Fixed const & ) const;

	bool operator==( Fixed const & ) const;
	bool operator>( Fixed const & ) const;
	bool operator>=( Fixed const & ) const;
	bool operator<=( Fixed const & ) const;
	bool operator<( Fixed const & ) const;
	bool operator!=( Fixed const & ) const;

	Fixed & operator++();		//prefix
	Fixed operator++( int );	//postfix

	int getRawBits( void ) const;
	void setRawBits( int const );

	float toFloat( void ) const;
	int toInt( void ) const;

	Fixed static & min(Fixed &, Fixed &);
	Fixed static & max(Fixed &, Fixed &);
	Fixed const static & min(Fixed const &, Fixed const &);
	Fixed const static & max(Fixed const &, Fixed const &);
};

std::ostream & operator<<(std::ostream & o, Fixed const & );

#endif