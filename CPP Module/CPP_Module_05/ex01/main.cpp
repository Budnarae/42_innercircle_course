#include "Form.hpp"

int main()
{
	try
	{
		Form	a("a", 0, 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Form	b("b", 151, 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	Form		c("c", 42, 42);
	Bureaucrat	d("sihong", 42);

	cout << "----------" << endl;
	cout << c;
	cout << "----------" << endl;

	c.beSigned(d);
	d.decrementGrade();

	try
	{
		c.beSigned(d);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}