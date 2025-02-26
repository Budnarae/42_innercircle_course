#include "Fixed.hpp"

int main( void )
{
	Fixed	a;
	Fixed	const b( Fixed( 5.05f ) * Fixed( 2 ) );
	cout << a << endl;
	cout << ++a << endl;
	cout << a << endl;
	cout << a++ << endl;
	cout << a << endl;
	cout << b << endl;
	cout << Fixed::max( a, b ) << endl;

	cout << endl << "-----Additional Test-----" << endl << endl;

	cout << Fixed::min( a, b ) << endl;

	Fixed	c(84.3f);
	Fixed	d(42.1f);

	cout << c << endl;
	cout << d << endl;
	cout << c * d << endl;
	cout << c / d << endl;

	return 0;
}