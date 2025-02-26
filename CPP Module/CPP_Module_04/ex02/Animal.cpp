#include "Animal.hpp"

/* Orthodox Cannonical Form*/
Animal::Animal() : type("Strange Animal")
{
	cout << "Constructor of Animal Called." << endl;
}
Animal::Animal(const Animal &cp) : type(cp.type)
{
	cout << "Copy Constructor of Animal Called." << endl;
}

Animal::~Animal()
{
	cout << "Destructor of Animal Called." << endl;
}

Animal	&Animal::operator=(const Animal &rhv)
{
	type = rhv.type;
	return (*this);
}

/* Constructor */
Animal::Animal(const string &type) : type(type)
{
	cout << "Constructor(with type) of Animal Called" << endl;
}

/* public member function */
string	Animal::getType() const
{
	return (type);
}
