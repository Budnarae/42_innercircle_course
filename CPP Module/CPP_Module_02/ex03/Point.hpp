#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private	:
		const Fixed	x;
		const Fixed	y;

	public	:
		/* Orthodox Canonical Form */
		Point();
		Point(const float x, const float y);
		Point(const Point &cp);
		~Point();
		Point	&operator=(const Point &right_val);
		
		/* substract operator overloading */
		Point	operator-(const Point &p) const;

		/* static member function */
		static Fixed	cross(const Point &a, const Point &b);
		static Fixed	negate_negative_number(const Fixed &f);
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif