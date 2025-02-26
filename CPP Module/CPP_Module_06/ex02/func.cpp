#include "func.hpp"

Base	*generate(void)
{
	int	r;

	std::srand(time(NULL));
	r = rand() % 3;

	if (r == 0)
		return (new A);
	else if (r == 1)
		return (new B);
	else
		return (new C);
}
void	identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		cout << "This is A." << endl;
	if (dynamic_cast<B *>(p))
		cout << "This is B." << endl;
	if (dynamic_cast<C *>(p))
		cout << "This is C." << endl;
}

void	identify(Base &p)
{
	try
	{	
		(void)dynamic_cast<A &>(p);
		cout << "This is A." << endl;
	}
	catch(std::bad_cast &e)
	{
		(void)e;
	}

	try
	{	
		(void)dynamic_cast<B &>(p);
		cout << "This is B." << endl;
	}
	catch(std::bad_cast &e)
	{
		(void)e;
	}

	try
	{	
		(void)dynamic_cast<C &>(p);
		cout << "This is C." << endl;
	}
	catch(std::bad_cast &e)
	{
		(void)e;
	}
}
