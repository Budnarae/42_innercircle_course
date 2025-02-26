#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private	:
		/* Orthodox Canonical Form(private part) */
		PresidentialPardonForm	&operator=(const PresidentialPardonForm &rhv);
	public	:
		/* Orthodox Canonical Form(public part) */
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &cp) \
			throw(GradeTooHighException, GradeTooLowException);
		~PresidentialPardonForm();
		/* Constructor */
		PresidentialPardonForm(const string &target);
		/* virtual function overriding */
		virtual void	execute(Bureaucrat const &executor) const throw(GradeTooLowException);
};

#endif
