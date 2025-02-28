#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private	:
		/* Orthodox Canonical Form(private part) */
		RobotomyRequestForm	&operator=(const RobotomyRequestForm &rhv);
	public	:
		/* Orthodox Canonical Form(public part) */
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &cp) \
			throw(GradeTooHighException, GradeTooLowException);
		~RobotomyRequestForm();
		/* Constructor */
		RobotomyRequestForm(const string &target);
		/* virtual function overriding */
		virtual void	execute(Bureaucrat const &executor) const throw(GradeTooLowException);
};

#endif