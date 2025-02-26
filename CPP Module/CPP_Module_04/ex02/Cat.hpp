#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private	:
		Brain	*brain;
	public	:
		/* Orthodox Canonical Form */
		Cat();
		Cat(const Cat &cp);
		virtual ~Cat();
		Cat	&operator=(const Cat &rhv);
		/* public member function */
		virtual void	makeSound() const;
		void			showBrain() const;
};

#endif
