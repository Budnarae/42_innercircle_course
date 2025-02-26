#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
#include <cstdlib>

using std::cout;
using std::endl;
using std::ostream;

class Fixed
{
	private	:
		int					fixed_point_number;
		static const int	fractional = 8;
		
		void	check_valid_integer_range(const int integer) const;
		void	print_err_exit(const char *s) const;
	public	:
		/* Orthodox Canonical Form */
		Fixed();
		Fixed(const Fixed &cp);
		~Fixed();
		Fixed	&operator=(const Fixed &right_val);

		/* Constructors */
		Fixed(const int integer);
		Fixed(const float flaoting);

		/* Member function */
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt(void) const;

		/* Comparision operators overloading */
		bool	operator>(const Fixed &f) const;
		bool	operator<(const Fixed &f) const;
		bool	operator>=(const Fixed &f) const;
		bool	operator<=(const Fixed &f) const;
		bool	operator==(const Fixed &f) const;
		bool	operator!=(const Fixed &f) const;

		/* Arithmetic operators overloading */
		Fixed	operator+(const Fixed &f) const;
		Fixed	operator-(const Fixed &f) const;
		Fixed	operator*(const Fixed &f) const;
		Fixed	operator/(const Fixed &f) const;

		/* increment/decrement operators overloading */
		Fixed	&operator++();
		Fixed	operator++(int);
		Fixed	&operator--();
		Fixed	operator--(int);

		/* Static Member function */
		static Fixed		&min(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);
};

ostream	&operator<<(ostream &out, const Fixed &f);

#endif