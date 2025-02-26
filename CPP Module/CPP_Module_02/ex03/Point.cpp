#include "Point.hpp"

/* Orthodox Canonical Form */
Point::Point() : x(0), y(0) {}

Point::Point(const float x, const float y) : x(x), y(y) {}

Point::Point(const Point &cp) : x(cp.x), y(cp.y) {}

Point::~Point() {}

Point	&Point::operator=(const Point &right_val)
{
	this->~Point();
	new(this) Point(right_val.x.toFloat(), right_val.y.toFloat());
	return (*this);
}

/* substract operator overloading */
Point	Point::operator-(const Point &p) const
{
	return (Point((x - p.x).toFloat(), (y - p.y).toFloat()));
}

/* static member function */
Fixed	Point::cross(const Point &a, const Point &b)
{
	return (a.x * b.y - a.y * b.x);
}

Fixed	Point::negate_negative_number(const Fixed &f)
{
	if (f < Fixed(0))
		return (f * Fixed(-1));
	else
		return (f);
}
