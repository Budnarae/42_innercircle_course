#include "Cat.hpp"

/* Orthodox Canonical Form */
Cat::Cat() : Animal("Cat")
{
	cout << "Constructor of Cat Called." << endl;
}

Cat::Cat(const Cat &cp) : Animal(cp)
{
	cout << "Copy Constructor of Cat Called." << endl;
}

Cat::~Cat()
{
	cout << "Destructor of Cat Called." << endl;
}

Cat	&Cat::operator=(const Cat &rhv)
{
	Animal::operator=(rhv);
	return (*this);
}
/* public member function */
void	Cat::makeSound() const
{
	cout << "Meow." << endl;
}
