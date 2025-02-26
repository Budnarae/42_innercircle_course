#include "MutantStack.hpp"

/* Orthodox Cannonical Form */
template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &cp) : std::stack<T>(cp) {}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
MutantStack<T>	&MutantStack<T>::operator=(const MutantStack &rhv)
{
	std::stack<T>::operator=(rhv);
	return (*this);
}

/* public member function */
template <typename T>
typename MutantStack<T>::iterator			MutantStack<T>::begin()
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator			MutantStack<T>::end()
{
	return (this->c.end());
}

template <typename T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rbegin()
{
	return (this->c.rbegin());
}

template <typename T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rend()
{
	return (this->c.rend());
}
