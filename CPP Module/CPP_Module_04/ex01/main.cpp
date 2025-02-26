#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	Animal	*zoo[10];

	for (int i = 0; i < 5; i++)
		zoo[i] = new Dog;
	for (int i = 5; i < 10; i++)
		zoo[i] = new Cat;
	for (int i = 0; i < 10; i++)
		zoo[i]->makeSound();
	for (int i = 0; i < 10; i++)
		delete zoo[i];
	
	Cat	a;
	Cat	b(a);
	Cat *c = new Cat;
	Cat *d = new Cat;

	*c = *d;

	a.showBrain();
	b.showBrain();
	c->showBrain();
	d->showBrain();

	delete d;

	c->showBrain();
	delete c;

	return (0);
}
