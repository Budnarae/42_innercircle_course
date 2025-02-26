#include "Dog.hpp"

/* Orthodox Canonical Form */
Dog::Dog() : Animal("Dog")
{
	brain = new Brain;
	cout << "Constructor of Dog Called." << endl;
}

Dog::Dog(const Dog &cp) : Animal(cp)
{
	brain = new Brain;
	*brain = *cp.brain;
	cout << "Copy Constructor of Dog Called." << endl;
}

Dog::~Dog()
{
	delete brain;
	cout << "Destructor of Dog Called." << endl;
}

Dog	&Dog::operator=(const Dog &rhv)
{
	Animal::operator=(rhv);
	*brain = *rhv.brain;
	return (*this);
}
/* public member function */
void	Dog::makeSound() const
{
	cout << "Woof." << endl;
}

void	Dog::showBrain() const
{
	brain->showIdeas();
}
