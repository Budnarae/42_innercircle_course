#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::vector;

class Span
{
	private	:
		vector<int>	vec;

		/* Orthodox Canonical Form(private part) */
		Span();
		Span(const Span &cp);
		Span	&operator=(const Span &rhv);
	public	:
		/* Orthodox Canonical Form(public part) */
		~Span();
		/* Constructor */
		Span(const unsigned int N);
		/* public member function */
		void	addNumber(int i) throw (std::length_error);
		void	addNumber(vector<int>::iterator from, \
						vector<int>::iterator to) \
						throw(std::length_error);
		int		shortestSpan() throw (std::invalid_argument);
		int		longestSpan() throw (std::invalid_argument);
};

#endif