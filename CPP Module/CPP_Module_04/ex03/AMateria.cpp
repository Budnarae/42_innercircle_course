#include "AMateria.hpp"

/* Orthodox Canonical Form */
AMateria::AMateria() {}
AMateria::AMateria(const AMateria &cp) : type(cp.type) {}
AMateria::~AMateria() {}

AMateria	&AMateria::operator=(const AMateria &rhv)
{
	type = rhv.type;
	return (*this);
}

/* Constructor */
AMateria::AMateria(string const & type)
{
	this->type = type;
}

/* public member function */
string const & AMateria::getType() const
{
	return (type);
}

/* public virtual function */
void AMateria::use(ICharacter& target)
{
	(void)target;
	cout << "Instance isn't completely defined yet." << endl;
}