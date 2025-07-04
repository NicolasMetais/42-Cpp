#include "Fixed.hpp"
#include <iostream>

#include <iostream>
int main( void ) 
{
	Fixed a(5);
	Fixed b(10);
	const Fixed c(5);
	const Fixed d(10);

	std::cout << a << std::endl;
	std::cout << "incrementation ++a : " << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << "incrementation a++ : "<< a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << "a + b : " << a + b << std::endl;
	std::cout << "a * b : " << a * b << std::endl;
	std::cout << "a - b : "  << a - b << std::endl;
	std::cout << "a / b : "  << a / b << std::endl;
	std::cout << "a > b : "  << (a > b) << std::endl;
	std::cout << "a < b : "  << (a < b) << std::endl;
	std::cout << "a == b : "  << (a == b) << std::endl;
	std::cout << "a != b : "  << (a != b) << std::endl;
	std::cout << "max : "  << Fixed::max( a, b ) << std::endl;
	std::cout << "max : "  << Fixed::max( c, d ) << std::endl;
	std::cout  << "min : " << Fixed::min( a, b ) << std::endl;
	std::cout  << "min : " << Fixed::min( c, d ) << std::endl;
	return 0;
}