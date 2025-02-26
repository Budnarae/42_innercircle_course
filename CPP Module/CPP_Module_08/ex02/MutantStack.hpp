#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <algorithm>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public	:
		/* public member type */
		typedef typename std::deque<T>::iterator		iterator;
		typedef typename std::deque<T>::iterator		reverse_iterator;
		/* Orthodox Cannonical Form */
		MutantStack();
		MutantStack(const MutantStack &cp);
		~MutantStack();
		MutantStack	&operator=(const MutantStack &rhv);
		/* public member function */
		iterator			begin();
		iterator			end();
		reverse_iterator	rbegin();
		reverse_iterator	rend();
};

#endif
