#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

using	std::cout;
using	std::endl;
using	std::string;

class Form
{
	private	:
		const string	name;
		bool			sign;
		const int		grade_to_sign;
		const int		grade_to_execute;
		/* Orthodox Canonical Form(private part) */
		Form	&operator=(const Form &rhv);
	public	:
		/* Orthodox Canonical Form(public part) */
		Form();
		Form(const Form &cp);
		~Form();
		/* Constructor */
		Form(const string &name, int gs, int ge) \
			throw(GradeTooHighException, GradeTooLowException);
		/* public member function */
		const string	&getName() const;
		bool			getSign() const;
		int				getGradeToSign() const;
		int				getGradeToExecute() const;
		void			beSigned(const Bureaucrat &b) throw(GradeTooLowException);
		/* exception handler class */
		class GradeTooHighException : public std::exception
		{
			public	:
				virtual const char	*what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public	:
				virtual const char	*what() const throw();
		};
};

/* operator overloading */
std::ostream	&operator<<(std::ostream &c, const Form &f);

#endif