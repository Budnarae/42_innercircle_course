#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private	:
		AMateria	*source[4];
	public	:
		/* Orthodox Canonical Form */
		MateriaSource();
		MateriaSource(const MateriaSource &cp);
		virtual ~MateriaSource();
		MateriaSource	&operator=(const MateriaSource &rhv);
		/* public member function */
		void	setSourceZero();
		/* public virtual function */
		virtual void learnMateria(AMateria* m);
		virtual AMateria* createMateria(string const & type);
};

#endif