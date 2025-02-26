#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	ShrubberyCreationForm	a("42_Seoul");
	RobotomyRequestForm		b("42_Seoul");
	PresidentialPardonForm	c("42_Seoul");

	Bureaucrat				t("Tang", 1);
	Bureaucrat				pb("PolarBear", 150);

	a.execute(pb);
	b.execute(pb);
	c.execute(pb);

	a.beSigned(t);
	b.beSigned(t);
	c.beSigned(t);

	try
	{
		a.execute(pb);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		b.execute(pb);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		c.execute(pb);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	a.execute(t);
	b.execute(t);
	c.execute(t);

	return (0);
}