#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "ref.hpp"

class Animal
{
	protected	:
		string	type;
	public		:
		/* Orthodox Cannonical Form*/
		Animal();
		Animal(const Animal &cp);
		virtual ~Animal();
		Animal	&operator=(const Animal &rhv);
		/* Constructor */
		Animal(const string &type);
		/* public member function */
		string	getType() const;
		/* public virtual function */
		virtual void	makeSound() const;
};

#endif