#include "Dog.hpp"

/* Orthodox Canonical Form */
Dog::Dog() : Animal("Dog")
{
	cout << "Constructor of Dog Called." << endl;
}

Dog::Dog(const Dog &cp) : Animal(cp)
{
	cout << "Copy Constructor of Dog Called." << endl;
}

Dog::~Dog()
{
	cout << "Destructor of Dog Called." << endl;
}

Dog	&Dog::operator=(const Dog &rhv)
{
	Animal::operator=(rhv);
	return (*this);
}
/* public member function */
void	Dog::makeSound() const
{
	cout << "Woof." << endl;
}