#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* i = new Cat();
	const Animal* j = new Dog();
	
	cout << meta->getType() << " " << endl;
	cout << i->getType() << " " << endl;
	cout << j->getType() << " " << endl;
	
	meta->makeSound();
	i->makeSound(); // will output the cat sound!
	j->makeSound();
	
	delete meta;
	delete i;
	delete j;

	cout << endl << "Testing Wrong Animal" << endl << endl;

	const WrongAnimal	_meta;
	const WrongCat		k;
	const WrongAnimal	&l = k;
	
	cout << _meta.getType() << " " << endl;
	cout << l.getType() << " " << endl;
	
	_meta.makeSound();
	l.makeSound(); // will output the Animal sound!

	return (0);
}
