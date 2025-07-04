#include "Point.hpp"
#include <iostream>

extern bool bsp(Point const a, Point const b, Point const c, Point const point);

int main( void ) 
{
	Point a(Fixed(0), Fixed(0));
	Point b(Fixed(5), Fixed(0));
	Point c(Fixed(2), Fixed(5));
	
	std::cout << std::boolalpha;

	Point p1(Fixed(2), Fixed(2));
	std::cout << "point = 2,2 : " << bsp(a, b, c, p1) << std::endl;

	Point p2(Fixed(6), Fixed(6));
	std::cout << "point = 6,6 : " << bsp(a, b, c, p2) << std::endl;

	Point p3(Fixed(3), Fixed(3));
	std::cout << "point = 3,3 : " << bsp(a, b, c, p3) << std::endl;

	Point p4(Fixed(0), Fixed(0));
	std::cout << "point = 0,0 : " << bsp(a, b, c, p4) << std::endl;

	return 0;
}