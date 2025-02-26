#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ref.hpp"
#include "ICharacter.hpp"

class AMateria
{
	protected	:
		string	type;
	public		:
		/* Orthodox Canonical Form */
		AMateria();
		AMateria(const AMateria &cp);
		virtual	~AMateria();
		AMateria	&operator=(const AMateria &rhv);
		/* Constructor */
		AMateria(string const & type);
		/* public member function */
		string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		/* public virtual function */
		virtual void use(ICharacter& target);
};

#endif