#ifndef INTERN_HPP
#define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public	:
		/* Orthodox Canonical Form */
		Intern();
		Intern(const Intern &cp);
		~Intern();
		Intern	&operator=(const Intern &rhv);
		/* public member function */
		AForm	*makeForm(const string &form_name, const string &target);
};

#endif