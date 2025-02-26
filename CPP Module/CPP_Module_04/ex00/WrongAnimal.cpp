#include "WrongAnimal.hpp"

/* Orthodox Cannonical Form*/
WrongAnimal::WrongAnimal() : type("Strange WrongAnimal")
{
	cout << "Constructor of WrongAnimal Called." << endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal &cp) : type(cp.type)
{
	cout << "Copy Constructor of WrongAnimal Called." << endl;
}

WrongAnimal::~WrongAnimal()
{
	cout << "Destructor of WrongAnimal Called." << endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &rhv)
{
	type = rhv.type;
	return (*this);
}

/* Constructor */
WrongAnimal::WrongAnimal(const string &type) : type(type)
{
	cout << "Constructor(with type) of WrongAnimal Called" << endl;
}

/* public member function */
string	WrongAnimal::getType() const
{
	return (type);
}

void	WrongAnimal::makeSound() const
{
	cout << "Hi there." << endl;
}
