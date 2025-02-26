#include "Form.hpp"

/* Orthodox Canonical Form(private part) */
Form	&Form::operator=(const Form &rhv)
{
	sign = rhv.sign;
	return (*this);
}

/* Orthodox Canonical Form(public part) */
Form::Form() : name("PolarBear"), sign(false), \
	grade_to_sign(150), grade_to_execute(150) {}
Form::Form(const Form &cp) : name(cp.name), sign(cp.sign), \
	grade_to_sign(150), grade_to_execute(150) {}
Form::~Form() {}

/* Constructor */
Form::Form(const string &name, int gs, int ge) \
	throw(GradeTooHighException, GradeTooLowException) \
	: name(name), sign(false), grade_to_sign(gs), grade_to_execute(ge)
{
	if (gs < 1 || ge < 1)
		throw (GradeTooHighException());
	if (gs > 150 || ge > 150)
		throw (GradeTooLowException());
}

/* public member function */
const string	&Form::getName() const
{
	return (name);
}

bool			Form::getSign() const
{
	return (sign);
}

int				Form::getGradeToSign() const
{
	return (grade_to_sign);
}

int				Form::getGradeToExecute() const
{
	return (grade_to_execute);
}

void			Form::beSigned(const Bureaucrat &b) throw(GradeTooLowException)
{
	sign = b.signForm(grade_to_sign, name);
	if (sign == false)
		throw (GradeTooLowException());
}

/* exception handler class */
const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Error : Grade is too high.");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Error : Grade is too low.");
}

/* operator overloading */
std::ostream	&operator<<(std::ostream &c, const Form &f)
{
	c << "Info of " << f.getName() << endl;
	if (f.getSign())
		c << "Signed." << endl;
	else
		c << "Not signed." << endl;
	c << "Grade to sign : " << f.getGradeToSign() << endl;
	c << "Grade to excute : " << f.getGradeToExecute() << endl;
	return (c);	
}