#include "WrongCat.hpp"

/* Orthodox Canonical Form */
WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	cout << "Constructor of WrongCat Called." << endl;
}

WrongCat::WrongCat(const WrongCat &cp) : WrongAnimal(cp)
{
	cout << "Copy Constructor of WrongCat Called." << endl;
}

WrongCat::~WrongCat()
{
	cout << "Destructor of WrongCat Called." << endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &rhv)
{
	WrongAnimal::operator=(rhv);
	return (*this);
}
/* public member function */
void	WrongCat::makeSound() const
{
	cout << "Meow." << endl;
}
