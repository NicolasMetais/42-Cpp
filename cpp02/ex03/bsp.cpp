#include "Point.hpp"

Fixed	Triangle_area(Point const& a, Point const& b, Point const& c)
{
	Fixed x1;
	Fixed x2;
	Fixed x3;
	Fixed area;

	x1 = a.getX() * (b.getY() - c.getY());
	x2 = b.getX() * (c.getY() - a.getY());
	x3 = c.getX() * (a.getY() - b.getY());
	area = x1 + x2 + x3;
	if (area < 0)
		area = area * Fixed(-1);
	return area / Fixed(2);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed bigArea = Triangle_area(a, b, c);
	Fixed smallArea1 = Triangle_area(a, b, point);
	Fixed smallArea2 = Triangle_area(b, c, point);
	Fixed smallArea3 = Triangle_area(c, a, point);

	if (smallArea1 + smallArea2 + smallArea3 == bigArea
		&& smallArea1 != 0 && smallArea2 != 0 && smallArea3 != 0)
		return true;
	return false;
}