#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

using	std::cout;
using	std::endl;
using	std::string;

class AForm;

class Bureaucrat
{
	private	:
		/* private member variable */
		const string	name;
		int				grade;
		/* Orthodox Canonical Form(private part) */
		Bureaucrat	&operator=(const Bureaucrat &rhv);
	public	:
		/* exception handler class */
		class	GradeTooHighException : public std::exception
		{
			public	:
				virtual const char	*what() const throw();
		};
		class	GradeTooLowException : public std::exception
		{
			public	:
				virtual const char	*what() const throw();
		};
		/* Orthodox Canonical Form(public part) */
		Bureaucrat();
		Bureaucrat(const Bureaucrat &cp);
		~Bureaucrat();
		/* Constructor */
		Bureaucrat(int grade) throw(Bureaucrat::GradeTooHighException, Bureaucrat::GradeTooLowException);
		Bureaucrat(const string &name, int grade) throw(Bureaucrat::GradeTooHighException, Bureaucrat::GradeTooLowException);
		/* public member function */
		const string	&getName() const;
		int				getGrade() const;
		void			incrementGrade() throw(Bureaucrat::GradeTooHighException);
		void			decrementGrade() throw(Bureaucrat::GradeTooLowException);
		bool			signForm(int grade_to_sign, const string &form_name) const;
		void			executeForm(AForm const &form) const;
};

#include "AForm.hpp"

/* operator overloading */
std::ostream	&operator<<(std::ostream &c, const Bureaucrat &b);

#endif
