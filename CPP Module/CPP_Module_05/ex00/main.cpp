#include "Bureaucrat.hpp"

int main()
{	
	try
	{
		Bureaucrat	a(0);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat	b(1);
		b.incrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat	c(151);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat	d(150);
		d.decrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	Bureaucrat	e("sihong", 24);
	cout << e;

	return (0);
}