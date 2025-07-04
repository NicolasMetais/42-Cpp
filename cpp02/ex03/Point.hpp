#pragma once
#include "Fixed.hpp"

class Point 
{
	private:
		const Fixed x;
		const Fixed y;
	public:
		Point();
		Point(const Fixed& new_x, const Fixed& new_y);
		Point(const Point& other);
		//il sert a R mais il est la
		Point& operator=(const Point& other);
		Fixed getX() const;
		Fixed getY() const;
		~Point();
};
