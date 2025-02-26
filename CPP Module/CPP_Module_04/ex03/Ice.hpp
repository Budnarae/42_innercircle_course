#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
	public	:
		/* Orthodox Canonical Form */
		Ice();
		Ice(const Ice &cp);
		virtual ~Ice();
		Ice	&operator=(const Ice &rhv);
		/* public virtual function */
		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
};

#endif