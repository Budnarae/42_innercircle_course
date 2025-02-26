#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

using	std::cout;
using	std::endl;

template <typename T>
class Array
{
	private	:
		T				*arr;
		unsigned int	arr_size;
	public	:
		/* Orthodox Canonical Form */
		Array();
		Array(const Array<T> &cp);
		~Array();
		Array	&operator=(const Array &rhv);
		/* constructor */
		Array(unsigned int n);
		/* [] operator overloading */
		T	&operator[](unsigned int idx) throw(std::exception);
		T	operator[](unsigned int idx) const throw(std::exception);
		/* public member function */
		unsigned int	size() const;
};

#include "Array.tpp"

#endif