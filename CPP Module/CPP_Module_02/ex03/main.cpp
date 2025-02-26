#include "Point.hpp"

/*
void	check_leaks()
{
	system("leaks bsp");
}
*/

int main( void )
{
	Point	a(2.0f, 8.0f);
	Point	b(8.0f, 3.0f);
	Point	c(2.0f, 3.0f);
	Point	p(2.0f, 3.0f);

	cout << "bsp result 1 - 0 expected : " << bsp(a, b, c, p) << endl;

	p = Point(2.1f, 3.0f);
	cout << "bsp result 2 - 0 expected : " << bsp(a, b, c, p) << endl;

	p = Point(2.0f, 3.1f);
	cout << "bsp result 3 - 0 expected : " << bsp(a, b, c, p) << endl;

	p = Point(2.1f, 3.1f);
	cout << "bsp result 4 - 1 expected : " << bsp(a, b, c, p) << endl;

	p = Point(2.1f, 7.0f);
	cout << "bsp result 5 - 1 expected : " << bsp(a, b, c, p) << endl;

	p = Point(2.1f, 8.0f);
	cout << "bsp result 6 - 0 expected : " << bsp(a, b, c, p) << endl;

	p = Point(7.5f, 3.1f);
	cout << "bsp result 7 - 1 expected : " << bsp(a, b, c, p) << endl;

	p = Point(8.0f, 3.1f);
	cout << "bsp result 8 - 0 expected : " << bsp(a, b, c, p) << endl;

	//atexit(check_leaks);

	return (0);
}