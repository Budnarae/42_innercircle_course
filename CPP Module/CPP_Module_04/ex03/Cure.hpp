#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
	public	:
		/* Orthodox Canonical Form */
		Cure();
		Cure(const Cure &cp);
		virtual	~Cure();
		Cure	&operator=(const Cure &rhv);
		/* public virtual function */
		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
};

#endif