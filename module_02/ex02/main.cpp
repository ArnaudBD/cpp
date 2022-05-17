#include "Fixed.hpp"
#include <iostream>
int main( void ) {
Fixed a;
Fixed test(2);
Fixed test2(3.5f);
Fixed zero;

a = test2;

std::cout << "a  == " << a << std::endl;
std::cout << "test == " << test << std::endl;
std::cout << "a + test == " << a + test << std::endl;
std::cout << "a / zero == " << a / zero << std::endl;
std::cout << "a / test == " << a / test << std::endl;
std::cout << "a * test == " << a * test << std::endl;
std::cout << "a * zero == " << a * zero << std::endl;

test = test2;
if (test == test2)
	std::cout << "test == test2" << std::endl;
else
	std::cout << "test != test2" << std::endl;
std::cout << "++a = " << ++a << std::endl;


// Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
// std::cout << a << std::endl;
// std::cout << ++a << std::endl;
// std::cout << a << std::endl;
// std::cout << a++ << std::endl;
// std::cout << a << std::endl;
// std::cout << b << std::endl;
// std::cout << Fixed::max( a, b ) << std::endl;
return 0;
}