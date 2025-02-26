#include "Zombie.hpp"

int main()
{
	Zombie	koo("KOO");
	koo.announce();
	
	randomChump("FOO");
	
	Zombie	*hoo = newZombie("HOO");
	hoo->announce();
	delete hoo;
	
	return (0);
}