#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <cstdlib>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private	:
		/* Orthodox Canonical Form(private part) */
		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &rhv);
	public	:
		/* Orthodox Canonical Form(public part) */
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &cp) \
			throw(GradeTooHighException, GradeTooLowException);
		~ShrubberyCreationForm();
		/* Constructor */
		ShrubberyCreationForm(const string &target);
		/* virtual function overriding */
		virtual void	execute(Bureaucrat const &executor) const throw(GradeTooLowException);
};

#endif
