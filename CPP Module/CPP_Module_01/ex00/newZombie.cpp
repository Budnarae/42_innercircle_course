#include "Zombie.hpp"

Zombie	*newZombie( string name )
{
	Zombie	*zomb = new Zombie(name);

	return (zomb);
}