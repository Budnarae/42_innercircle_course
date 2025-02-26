#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

using	std::cout;
using	std::endl;
using	std::string;

class AForm
{
	private	:
		const string	name;
		const string	target;
		bool			sign;
		const int		grade_to_sign;
		const int		grade_to_execute;
		/* Orthodox Canonical Form(private part) */
		AForm	&operator=(const AForm &rhv);
	public	:
		/* Orthodox Canonical Form(public part) */
		AForm();
		AForm(const AForm &cp);
		virtual ~AForm();
		/* Constructor */
		AForm(const string &name, const string &target, int gs, int ge) \
			throw(GradeTooHighException, GradeTooLowException);
		/* public member function */
		const string	&getName() const;
		const string	&getTarget() const;
		bool			getSign() const;
		int				getGradeToSign() const;
		int				getGradeToExecute() const;
		void			inspectGradeRange(int gs, int ge) \
			throw(GradeTooHighException, GradeTooLowException);
		bool			isExecutable(int bureaucratGrade) const \
			throw (GradeTooLowException);
		void			beSigned(const Bureaucrat &b) throw(GradeTooLowException);
		/* public pure virtual function */
		virtual void	execute(Bureaucrat const &executor) const = 0;
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
std::ostream	&operator<<(std::ostream &c, const AForm &f);

#endif