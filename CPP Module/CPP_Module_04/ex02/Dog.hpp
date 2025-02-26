#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private	:
		Brain	*brain;
	public	:
		/* Orthodox Canonical Form */
		Dog();
		Dog(const Dog &cp);
		virtual ~Dog();
		Dog	&operator=(const Dog &rhv);
		/* public member function */
		virtual void	makeSound() const;
		void			showBrain() const;
};

#endif
