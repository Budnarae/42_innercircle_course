#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <exception>

using	std::cout;
using	std::cerr;
using	std::endl;
using	std::string;
using	std::istringstream;
using	std::stack;
using	std::exception;

class RPN
{
	private	:
		/* private member variable */
		const string	expression;
		/* Exceptions */
		class NotAOperatorException : public exception
		{
			public :
				virtual const char *what() const throw();
		};
		class NoEnoughNumberException : public exception
		{
			public :
				virtual const char *what() const throw();
		};
		class TooMuchNumberException : public exception
		{
			public :
				virtual const char *what() const throw();
		};
		class NoDelimeterInExpressionException : public exception
		{
			public :
				virtual const char *what() const throw();
		};
		class DivideWithZeroException : public exception
		{
			public :
				virtual const char *what() const throw();
		};
		/* orthdox cannonical form : private part */
		RPN();
		RPN(const RPN &cp);
		RPN	&operator=(const RPN &rhv);
	public	:
		/* orthodox cannonical form : public part */
		~RPN();
		/* constructor */
		RPN(const string &_expression);
		/* public member function */
		void	checkOperator(char c) const throw (NotAOperatorException);
		void	applyOperator(stack<int> &numberHolder, char op) const \
			throw (DivideWithZeroException);
		void	checkDelimeter(istringstream &expressionParser) const \
			throw (NoDelimeterInExpressionException);
		void	calculate() const;
};

#endif
