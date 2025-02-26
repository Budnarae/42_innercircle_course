#include "whatever.hpp"

int main( void )
{
	int	a = 2;
	int	b = 3;

	::swap(a, b);
	cout << "a = " << a << ", b = " << b << endl;
	cout << "min( a, b ) = " << ::min( a, b ) << endl;
	cout << "max( a, b ) = " << ::max( a, b ) << endl;

	string	c = "chaine1";
	string	d = "chaine2";

	::swap(c, d);
	cout << "c = " << c << ", d = " << d << endl;
	cout << "min( c, d ) = " << ::min( c, d ) << endl;
	cout << "max( c, d ) = " << ::max( c, d ) << endl;

	double	*e = new double;
	double	*f = new double;
	
	*e = 4.4;
	*f = 2.2;

	cout << "before swap" << endl;
	cout << "e = " << e << ", f = " << f << endl;
	cout << "*e = " << *e << ", *f = " << *f << endl;
	::swap(e, f);
	cout << "after swap" << endl;
	cout << "e = " << e << ", f = " << f << endl;
	cout << "*e = " << *e << ", *f = " << *f << endl;
	cout << "min( e, f ) = " << ::min( e, f ) << endl;
	cout << "max( e, f ) = " << ::max( e, f ) << endl;

	delete e;
	delete f;

	return (0);
}
