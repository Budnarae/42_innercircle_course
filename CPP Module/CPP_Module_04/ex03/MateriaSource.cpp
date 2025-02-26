#include "MateriaSource.hpp"

/* Orthodox Canonical Form */
MateriaSource::MateriaSource()
{
	setSourceZero();
}

MateriaSource::MateriaSource(const MateriaSource &cp)
{
	setSourceZero();
	*this = cp;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (source[i])
			delete source[i];
	}
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &rhv)
{
	for (int i = 0; i < 4; i++)
	{
		if (source[i])
		{
			delete source[i];
			source[i] = NULL;
		}
		if (rhv.source[i])
			source[i] = rhv.source[i]->clone();
	}
	return (*this);
}

/* public member function */
void	MateriaSource::setSourceZero()
{
	for (int i = 0; i < 4; i++)
		source[i] = 0;
}

/* public virtual function */
void MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (source[i] == 0)
		{
			source[i] = m;
			break;
		}
	}
}

AMateria* MateriaSource::createMateria(string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (source[i] && source[i]->getType() == type)
			return (source[i]->clone());
	}
	return (0);
}