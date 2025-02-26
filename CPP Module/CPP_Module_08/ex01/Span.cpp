#include "Span.hpp"

/* Orthodox Canonical Form(private part) */
Span::Span() : vec() {}
Span::Span(const Span &cp) : vec(cp.vec) {}

Span	&Span::operator=(const Span &rhv)
{
	vec = rhv.vec;
	return (*this);
}

/* Orthodox Cannonical Form(public part) */
Span::~Span() {}

/* Constructor */
Span::Span(const unsigned int N) : vec() { vec.reserve(N); }

/* public member function */
void	Span::addNumber(int i) throw (std::length_error)
{
	if (vec.size() >= vec.capacity())
		throw (std::length_error("Error : Vector exceeded."));
	vec.push_back(i);
}

void	Span::addNumber(vector<int>::iterator from, \
						vector<int>::iterator to) \
						throw (std::length_error)
{
	if (vec.size() + (to - from) > vec.capacity())
		throw (std::length_error("Error : Vector exceeded."));
	vec.insert(vec.end(), from, to);
}

int		Span::shortestSpan() throw (std::invalid_argument)
{
	if (vec.size() == 0 || vec.size() == 1)
		throw (std::invalid_argument("Error : Too less values in vector."));
	
	vector<int>	tmp(vec);
	std::sort(tmp.begin(), tmp.end());
	
	int	shortestSpan = *(tmp.begin() + 1) - *tmp.begin();
	for (vector<int>::iterator iter = tmp.begin(); iter != tmp.end() - 1; iter++)
	{
		int	span = *(iter + 1) - *iter;
		if (span < shortestSpan)
			shortestSpan = span;
	}
	return (shortestSpan);
}

int		Span::longestSpan() throw (std::invalid_argument)
{
	if (vec.size() == 0 || vec.size() == 1)
		throw (std::invalid_argument("Error : Too less values in vector."));
	return (*std::max_element(vec.begin(), vec.end()) - \
			*std::min_element(vec.begin(), vec.end()));
}
