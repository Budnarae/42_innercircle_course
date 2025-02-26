#include "Fixed.hpp"

/* private member function */
void	Fixed::print_err_exit(const char *s) const
{
	cout << s << endl;
	exit(1);
}

void	Fixed::check_valid_integer_range(const int integer) const
{
	if (integer > 8388607)
		print_err_exit("error : overflow occured");
	if (integer < -8388608)
		print_err_exit("error : underflow occured");
}

/* Orthodox Canonical Form */
// default constructor
Fixed::Fixed() : fixed_point_number(0) {}

// copy constructor
Fixed::Fixed(const Fixed &cp) : fixed_point_number(cp.fixed_point_number) {}

// destructor
Fixed::~Fixed() {}

// assignment operator overloading
Fixed	&Fixed::operator=(const Fixed &right_val)
{
	fixed_point_number = right_val.fixed_point_number;
	return (*this);
}

/* Constructor*/
// int to fixed-point number
Fixed::Fixed(const int integer)
{
	check_valid_integer_range(integer);
	fixed_point_number = integer << 8;
}

// float to fixed-point number

Fixed::Fixed(const float floating)
{
	int	tmp = static_cast<int>(floating);
	check_valid_integer_range(tmp);

	fixed_point_number = static_cast<int>(roundf(floating * (1 << 8)));
}

/* public member function */

int		Fixed::getRawBits(void) const
{
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

/* Comparision operators overloading */
bool	Fixed::operator>(const Fixed &f) const
{
	if (fixed_point_number > f.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator<(const Fixed &f) const
{
	if (fixed_point_number < f.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator>=(const Fixed &f) const
{
	if (fixed_point_number >= f.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator<=(const Fixed &f) const
{
	if (fixed_point_number <= f.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator==(const Fixed &f) const
{
	if (fixed_point_number == f.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator!=(const Fixed &f) const
{
	if (fixed_point_number != f.getRawBits())
		return (true);
	else
		return (false);
}

/* Arithmetic operators overloading */
Fixed	Fixed::operator+(const Fixed &f) const
{
	long long	tmp;

	tmp = static_cast<long long>(fixed_point_number) \
		+ static_cast<long long>(f.getRawBits());
	if (tmp != static_cast<long long>(fixed_point_number + f.getRawBits()))
		print_err_exit("error : valid range exceeded");

	Fixed	output;

	output.setRawBits(fixed_point_number + f.getRawBits());
	return (output);
}

Fixed	Fixed::operator-(const Fixed &f) const
{
	long long	tmp;

	tmp = static_cast<long long>(fixed_point_number) \
		- static_cast<long long>(f.getRawBits());
	if (tmp != static_cast<long long>(fixed_point_number - f.getRawBits()))
		print_err_exit("error : valid range exceeded");

	Fixed	output;

	output.setRawBits(fixed_point_number - f.getRawBits());
	return (output);
}

Fixed	Fixed::operator*(const Fixed &f) const
{
	long long	tmp;

	tmp = static_cast<long long>(fixed_point_number) \
		* static_cast<long long>(f.getRawBits());
	if (tmp != static_cast<long long>(fixed_point_number * f.getRawBits()))
		print_err_exit("error : valid range exceeded");

	Fixed	output;

	output.setRawBits(fixed_point_number * f.getRawBits() >> 8);
	return (output);
}

Fixed	Fixed::operator/(const Fixed &f) const
{
	if (f.getRawBits() == 0)
		print_err_exit("error : cannot divide with zero");

	long long	tmp;

	tmp = static_cast<long long>(fixed_point_number) \
		/ static_cast<long long>(f.getRawBits());
	if (tmp != static_cast<long long>(fixed_point_number / f.getRawBits()))
		print_err_exit("error : valid range exceeded");

	Fixed	output;

	output.setRawBits(fixed_point_number / f.getRawBits() << 8);
	return (output);
}

/* increment/decrement operators overloading */
Fixed	&Fixed::operator++()
{
	long long	tmp;

	tmp = static_cast<long long>(fixed_point_number) + 1;
	if (tmp != static_cast<long long>(fixed_point_number + 1))
		print_err_exit("error : valid range exceeded");
	
	fixed_point_number++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	long long	tmp;

	tmp = static_cast<long long>(fixed_point_number) + 1;
	if (tmp != static_cast<long long>(fixed_point_number + 1))
		print_err_exit("error : valid range exceeded");
	
	Fixed	output = *this;
	fixed_point_number++;
	return (output);
}

Fixed	&Fixed::operator--()
{
	long long	tmp;

	tmp = static_cast<long long>(fixed_point_number) - 1;
	if (tmp != static_cast<long long>(fixed_point_number - 1))
		print_err_exit("error : valid range exceeded");
	
	fixed_point_number--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	long long	tmp;

	tmp = static_cast<long long>(fixed_point_number) - 1;
	if (tmp != static_cast<long long>(fixed_point_number - 1))
		print_err_exit("error : valid range exceeded");
	
	Fixed	output = *this;
	fixed_point_number--;
	return (output);
}

/* Static Member function */
Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a < b)
		return (b);
	else
		return (a);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (b);
	else
		return (a);
}