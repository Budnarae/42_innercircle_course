#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include "ref.hpp"

class Brain
{
	private	:
		/* orthodox canonical form(private part) */
		Brain(const Brain &cp);
	public	:
		string	ideas[100];
		/* orthodox canonical form */
		Brain();
		~Brain();
		Brain	&operator=(const Brain &rhv);
		/* public member function */
		void	showIdeas() const;
};

char	getRandomChar();

#endif
