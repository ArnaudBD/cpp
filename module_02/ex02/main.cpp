#include "Fixed.hpp"
#include <iostream>
int main( void ) {
Fixed a;
Fixed test(2);
a = test;
Fixed test2(3);

std::cout << a + test2 << std::endl;

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