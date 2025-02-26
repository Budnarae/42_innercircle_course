#include "Intern.hpp"

/* Orthodox Canonical Form */
Intern::Intern() {}
Intern::Intern(const Intern &cp) {(void)cp;}
Intern::~Intern() {}
Intern	&Intern::operator=(const Intern &rhv) {(void)rhv; return (*this);};

/* public member function */
AForm	*Intern::makeForm(const string &form_name, const string &target)
{
	string	form_names[3];
	int		i;

	form_names[0] = "shrubbery creation";
	form_names[1] = "robotomy request";
	form_names[2] = "presidential pardon";

	for (i = 0; i < 3; i++)
	{
		if (form_names[i] == form_name)
			break ;
	}
	switch (i)
	{
	case 0:
		return (new ShrubberyCreationForm(target));
		break;
	case 1:
		return (new RobotomyRequestForm(target));
		break;
	case 2:
		return (new PresidentialPardonForm(target));
		break;
	default:
		cout << "There's no such form." << endl;
		return (0);
		break;
	}
}
