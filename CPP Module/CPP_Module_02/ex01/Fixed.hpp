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
		
		void	check_valid_integer_range(const int integer);
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
};

ostream	&operator<<(ostream &out, const Fixed &f);

#endif