#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	public :
		/* Orthodox Canonical Form */
		Cat();
		Cat(const Cat &cp);
		virtual ~Cat();
		Cat	&operator=(const Cat &rhv);
		/* public member function */
		virtual void	makeSound() const;
};

#endif