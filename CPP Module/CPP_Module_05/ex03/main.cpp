#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Intern		intern;
	Bureaucrat	soul("soul", 1);
	AForm		*form;

	form = intern.makeForm("robotomy request", "Bender");
	form->beSigned(soul);
	form->execute(soul);
	delete form;

	form = intern.makeForm("shrubbery creation", "cluster");
	form->beSigned(soul);
	form->execute(soul);
	delete form;

	form = intern.makeForm("presidential pardon", "42");
	form->beSigned(soul);
	form->execute(soul);
	delete form;

	form = intern.makeForm("blank", "42");

	return (0);
}