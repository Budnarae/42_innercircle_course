#include "AForm.hpp"

/* Orthodox Canonical Form(private part) */
AForm	&AForm::operator=(const AForm &rhv)
{
	(void)rhv;
	return (*this);
}

/* Orthodox Canonical Form(public part) */
AForm::AForm() : name("PolarBear"), target("42Seoul"), sign(false), \
	grade_to_sign(150), grade_to_execute(150) {}
AForm::AForm(const AForm &cp) : name(cp.name), target(cp.target), sign(cp.sign), \
	grade_to_sign(150), grade_to_execute(150) {}
AForm::~AForm() {}

/* Constructor */
AForm::AForm(const string &name, const string &target, int gs, int ge) \
	throw(GradeTooHighException, GradeTooLowException) \
	: name(name), target(target), sign(false), grade_to_sign(gs), grade_to_execute(ge)
{
	inspectGradeRange(gs, ge);
}

/* public member function */
const string	&AForm::getName() const
{
	return (name);
}

const string	&AForm::getTarget() const
{
	return (target);
}

bool			AForm::getSign() const
{
	return (sign);
}

int				AForm::getGradeToSign() const
{
	return (grade_to_sign);
}

int				AForm::getGradeToExecute() const
{
	return (grade_to_execute);
}

void			AForm::inspectGradeRange(int gs, int ge) \
	throw(GradeTooHighException, GradeTooLowException)
{
	if (gs < 1 || ge < 1)
		throw (GradeTooHighException());
	if (gs > 150 || ge > 150)
		throw (GradeTooLowException());
}

bool			AForm::isExecutable(int bureaucratGrade) const \
	throw (GradeTooLowException)
{
	if (sign == false)
	{
		cout << "Form must be signed to be executed" << endl;
		return (false);
	}
	if (bureaucratGrade > grade_to_execute)
		throw (GradeTooLowException());
	return (true);
}

void			AForm::beSigned(const Bureaucrat &b) throw(GradeTooLowException)
{
	sign = b.signForm(grade_to_sign, name);
	if (sign == false)
		throw (GradeTooLowException());
}

/* exception handler class */
const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("Error : Grade is too high.");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("Error : Grade is too low.");
}

/* operator overloading */
std::ostream	&operator<<(std::ostream &c, const AForm &f)
{
	c << "Info of " << f.getName() << endl;
	c << "Target : " << f.getTarget() << endl;
	if (f.getSign())
		c << "Signed." << endl;
	else
		c << "Not signed." << endl;
	c << "Grade to sign : " << f.getGradeToSign() << endl;
	c << "Grade to excute : " << f.getGradeToExecute() << endl;
	return (c);	
}