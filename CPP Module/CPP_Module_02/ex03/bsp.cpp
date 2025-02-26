#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	t = Point::cross(c - b, a - b);
	Fixed	t1 = Point::cross(point - b, a - b);
	Fixed	t2 = Point::cross(c - b, point - b);
	Fixed	t3 = Point::cross(a - c, point - c);
	// check valid triangle
	if (t == Fixed(0))
		return (false);
	// check point on edge
	if (t1 == Fixed(0))
		return (false);
	if (t2 == Fixed(0))
		return (false);
	if (t3 == Fixed(0))
		return (false);

	t = Point::negate_negative_number(t);
	t1 = Point::negate_negative_number(t1);
	t2 = Point::negate_negative_number(t2);
	t3 = Point::negate_negative_number(t3);

	if (t == t1 + t2 + t3)
		return (true);
	else
		return (false);
}