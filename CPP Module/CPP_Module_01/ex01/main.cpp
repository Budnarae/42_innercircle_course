#include "Zombie.hpp"

int main()
{
	int		N = 8;
	Zombie	*horde = zombieHorde(N, "FOO");

	for(int i = 0; i < N; i++)
		horde[i].announce();

	delete[] horde;
	return (0);
}