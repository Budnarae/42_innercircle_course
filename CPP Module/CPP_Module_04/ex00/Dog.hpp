#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
	public :
		/* Orthodox Canonical Form */
		Dog();
		Dog(const Dog &cp);
		virtual ~Dog();
		Dog	&operator=(const Dog &rhv);
		/* public member function */
		virtual void	makeSound() const;
};

#endif