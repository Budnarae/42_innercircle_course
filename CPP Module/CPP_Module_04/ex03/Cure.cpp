#include "Cure.hpp"

/* Orthodox Canonical Form */
Cure::Cure() : AMateria(string("cure")) {}
Cure::Cure(const Cure &cp) : AMateria(cp) {}
Cure::~Cure() {}

Cure	&Cure::operator=(const Cure &rhv)
{
	AMateria::operator=(rhv);
	return (*this);
}

/* public virtual function */
AMateria* Cure::clone() const
{
	AMateria	*clonedOne = new Cure;
	*clonedOne = *this;
	
	return (clonedOne);
}

void Cure::use(ICharacter& target)
{
	cout << "* heals " << target.getName() << "'s wounds *" << endl;
}