#ifndef WRONGCat_HPP
#define WRONGCat_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public :
		/* Orthodox Canonical Form */
		WrongCat();
		WrongCat(const WrongCat &cp);
		~WrongCat();
		WrongCat	&operator=(const WrongCat &rhv);
		/* public member function */
		void	makeSound() const;
};

#endif