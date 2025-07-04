#include "Point.hpp"

Point::Point(void) : x(0), y(0) {};

Point::Point(const Fixed& new_x, const Fixed& new_y) : x(new_x), y(new_y) {};

Point::Point(const Point& other) : x(other.x), y(other.y) {};

Point::~Point() {};

Fixed Point::getX() const
{
	return this->x;
}

Fixed Point::getY() const
{
	return this->y;
}
