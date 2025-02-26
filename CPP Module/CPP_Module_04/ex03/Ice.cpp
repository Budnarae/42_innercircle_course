#include "Ice.hpp"

/* Orthodox Canonical Form */
Ice::Ice() : AMateria(string("ice")) {}
Ice::Ice(const Ice &cp) : AMateria(cp) {}
Ice::~Ice() {}

Ice	&Ice::operator=(const Ice &rhv)
{
	AMateria::operator=(rhv);
	return (*this);
}

/* public virtual function */
AMateria* Ice::clone() const
{
	AMateria	*clonedOne = new Ice;
	*clonedOne = *this;

	return (clonedOne);
}

void Ice::use(ICharacter& target)
{
	cout << "* shoots an ice bolt at " << target.getName() << endl;
}