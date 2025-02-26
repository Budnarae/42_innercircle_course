#include "Cat.hpp"

/* Orthodox Canonical Form */
Cat::Cat() : Animal("Cat")
{
	brain = new Brain;
	cout << "Constructor of Cat Called." << endl;
}

Cat::Cat(const Cat &cp) : Animal(cp)
{
	brain = new Brain;
	*brain = *cp.brain;
	cout << "Copy Constructor of Cat Called." << endl;
}

Cat::~Cat()
{
	delete brain;
	cout << "Destructor of Cat Called." << endl;
}

Cat	&Cat::operator=(const Cat &rhv)
{
	Animal::operator=(rhv);
	*brain = *rhv.brain;
	return (*this);
}
/* public member function */
void	Cat::makeSound() const
{
	cout << "Meow." << endl;
}

void	Cat::showBrain() const
{
	brain->showIdeas();
}
