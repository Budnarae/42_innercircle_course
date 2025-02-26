#include "Fixed.hpp"

/* default constructor */
Fixed::Fixed() : fixed_point_number(0)
{
	cout << "Default constructor called" << endl;
}

/* copy constructor */
Fixed::Fixed(const Fixed &cp) : fixed_point_number(cp.fixed_point_number)
{
	cout << "Copy constructor called" << endl;
}

/* destructor */
Fixed::~Fixed()
{
	cout << "Destructor called" << endl;
}

/* assignment operator overloading */
Fixed	&Fixed::operator=(const Fixed &right_val)
{
	cout << "Copy assignment operator called" << endl;
	fixed_point_number = right_val.fixed_point_number;
	
	return (*this);
}

/* public member function */

int		Fixed::getRawBits(void) const
{
	cout << "getRawBits member function called" << endl;

	return (fixed_point_number);
}

void	Fixed::setRawBits(int const raw)
{
	fixed_point_number = raw;
}