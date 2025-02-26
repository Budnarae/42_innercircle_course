#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include "ref.hpp"

class WrongAnimal
{
	protected	:
		string	type;
	public		:
		/* Orthodox Cannonical Form*/
		WrongAnimal();
		WrongAnimal(const WrongAnimal &cp);
		~WrongAnimal();
		WrongAnimal	&operator=(const WrongAnimal &rhv);
		/* Constructor */
		WrongAnimal(const string &type);
		/* public member function */
		string	getType() const;
		void	makeSound() const;
};

#endif