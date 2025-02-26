#include "Fixed.hpp"

/* private member function */
void	Fixed::check_valid_integer_range(const int integer)
{
	if (integer > 8388607 /* 1 << 23 - 1*/)
	{
		cout << "error : overflow occured" << endl;
		exit(1);
	}
	if (integer < -8388608)
	{
		cout << "error : underflow occured" << endl;
		exit(1);
	}
}

/* Orthodox Canonical Form */
// default constructor
Fixed::Fixed() : fixed_point_number(0)
{
	cout << "Default constructor called" << endl;
}

// copy constructor
Fixed::Fixed(const Fixed &cp) : fixed_point_number(cp.fixed_point_number)
{
	cout << "Copy constructor called" << endl;
}

// destructor
Fixed::~Fixed()
{
	cout << "Destructor called" << endl;
}

// assignment operator overloading
Fixed	&Fixed::operator=(const Fixed &right_val)
{
	cout << "Copy assignment operator called" << endl;
	fixed_point_number = right_val.fixed_point_number;
	
	return (*this);
}

/* Constructor*/
// int to fixed-point number
Fixed::Fixed(const int integer)
{
	cout << "Int constructor called" << endl;

	check_valid_integer_range(integer);
	fixed_point_number = integer << 8;
}

// float to fixed-point number

Fixed::Fixed(const float floating)
{
	cout << "Float constructor called" << endl;

	int	tmp = static_cast<int>(floating);
	check_valid_integer_range(tmp);

	fixed_point_number = static_cast<int>(roundf(floating * (1 << 8)));
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

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(fixed_point_number) / 256.0f);
}

int		Fixed::toInt(void) const
{
	return (fixed_point_number / 256);
}

/* << operator overloading */
ostream	&operator<<(ostream &out, const Fixed &f)
{
	out << f.toFloat();
	return (out);
}