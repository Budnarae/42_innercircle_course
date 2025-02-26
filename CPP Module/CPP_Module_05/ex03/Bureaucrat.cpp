#include "Bureaucrat.hpp"

/* Orthodox Canonical Form(private part) */
Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &rhv)
{
	grade = rhv.grade;
	return (*this);
}

/* Orthodox Canonical Form(public part) */
Bureaucrat::Bureaucrat() : name("PolarBear"), grade(150) {}
Bureaucrat::Bureaucrat(const Bureaucrat &cp) : name(cp.name), grade(cp.grade) {}
Bureaucrat::~Bureaucrat() {}

/* Constructor */
Bureaucrat::Bureaucrat(int grade) \
	throw(GradeTooHighException, GradeTooLowException) : name("PolarBear")
{
	if (grade < 1)
		throw (GradeTooHighException());
	if (grade > 150)
		throw (GradeTooLowException());
	this->grade = grade;
}
Bureaucrat::Bureaucrat(const string &name, int grade) \
	throw(GradeTooHighException, GradeTooLowException) : name(name)
{
	if (grade < 1)
		throw (GradeTooHighException());
	if (grade > 150)
		throw (GradeTooLowException());
	this->grade = grade;
}

/* public member function */
const string	&Bureaucrat::getName() const
{
	return (name);
}

int				Bureaucrat::getGrade() const
{
	return (grade);
}

void			Bureaucrat::incrementGrade() throw(GradeTooHighException)
{
	if (grade - 1 < 1)
		throw (GradeTooHighException());
	grade -= 1;
}

void			Bureaucrat::decrementGrade() throw(GradeTooLowException)
{
	if (grade + 1 > 150)
		throw (GradeTooLowException());
	grade += 1;
}

bool			Bureaucrat::signForm(int grade_to_sign, const string &form_name) const
{
	if (grade <= grade_to_sign)
	{
		cout << name << " signed " << form_name << endl;
		return (true);
	}
	else
	{
		cout << name << " couldn't sign " << form_name \
			<< " because grade is too low." << endl;
		return (false);
	}
}

void			Bureaucrat::executeForm(AForm const &form) const
{
	form.execute(*this);
}

/* exception handler class function */
const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Error : Grade is too high.");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Error : Grade is too low.");
}

/* operator overloading */
std::ostream	&operator<<(std::ostream &c, const Bureaucrat &b)
{
	c << b.getName() << ", bureaucrat grade " << b.getGrade() << "."<< endl;
	return (c);
}