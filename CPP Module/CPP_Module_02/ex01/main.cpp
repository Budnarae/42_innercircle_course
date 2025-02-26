#include "Fixed.hpp"

int	main( void )
{
	Fixed		a;
	Fixed const	b( -10 );
	Fixed const	c( -42.42f );
	Fixed const	d( b );

	a = Fixed( -1234.9321f );

	cout << endl << "*** testing << operator overloading ***" << endl << endl;

	cout << "a is " << a << endl;
	cout << "b is " << b << endl;
	cout << "c is " << c << endl;
	cout << "d is " << d << endl;

	cout << endl << "*** testing toFloat() ***" << endl << endl;

	cout << "a is " << a.toFloat() << " as integer" << endl;
	cout << "b is " << b.toFloat() << " as integer" << endl;
	cout << "c is " << c.toFloat() << " as integer" << endl;
	cout << "d is " << d.toFloat() << " as integer" << endl;

	cout << endl << "*** testing toInt() ***" << endl << endl;

	cout << "a is " << a.toInt() << " as integer" << endl;
	cout << "b is " << b.toInt() << " as integer" << endl;
	cout << "c is " << c.toInt() << " as integer" << endl;
	cout << "d is " << d.toInt() << " as integer" << endl;

	cout << endl << "*** testing overflow handling ***" << endl << endl;
	
	return 0;
}