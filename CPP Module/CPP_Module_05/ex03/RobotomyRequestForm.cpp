#include "RobotomyRequestForm.hpp"

/* Orthodox Canonical Form(private part) */
RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &rhv)
{
	(void)rhv;
	return (*this);
}

/* Orthodox Canonical Form(public part) */
RobotomyRequestForm::RobotomyRequestForm() : AForm() {}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cp) \
	throw(GradeTooHighException, GradeTooLowException) : AForm(cp) {}
RobotomyRequestForm::~RobotomyRequestForm() {};

/* Constructor */
RobotomyRequestForm::RobotomyRequestForm(const string &target) \
	: AForm("RobotomyRequestForm", target, 72, 45) {}

/* virtual function overriding */
void	RobotomyRequestForm::execute(Bureaucrat const &executor) const throw(GradeTooLowException)
{
	if (isExecutable(executor.getGrade()) == false)
		return ;

	int	halfPossibility;

	std::srand(std::time(NULL));
	halfPossibility = std::rand() % 2;

	cout << "Drrrrrr........." << endl;
	if (halfPossibility)
		cout << getTarget() << " has been Successfully robotomized." << endl;
	else
		cout << getTarget() << " has failed to robotomized." << endl;
}
