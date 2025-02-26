#include "PresidentialPardonForm.hpp"

/* Orthodox Canonical Form(private part) */
PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &rhv)
{
	(void)rhv;
	return (*this);
}

/* Orthodox Canonical Form(public part) */
PresidentialPardonForm::PresidentialPardonForm() : AForm() {}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &cp) \
	throw (GradeTooHighException, GradeTooLowException): AForm(cp) {}
PresidentialPardonForm::~PresidentialPardonForm() {};

/* Constructor */
PresidentialPardonForm::PresidentialPardonForm(const string &target) \
	: AForm("PresidentialPardomForm", target, 25, 5) {}

/* virtual function overriding */
void	PresidentialPardonForm::execute(Bureaucrat const &executor) const throw(GradeTooLowException)
{
	if (isExecutable(executor.getGrade()) == false)
		return ;
	cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << endl;
}
