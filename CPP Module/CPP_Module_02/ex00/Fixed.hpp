#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

using std::cout;
using std::endl;

class Fixed
{
	private	:
		int					fixed_point_number;
		static const int	fractional = 8;
	public	:
		/* Orthodox Canonical Form */
		Fixed();
		Fixed(const Fixed &cp);
		~Fixed();
		Fixed	&operator=(const Fixed &right_val);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif