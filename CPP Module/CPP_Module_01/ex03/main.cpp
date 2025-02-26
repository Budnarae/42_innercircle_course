#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	cout << endl;
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	cout << endl;
	{
		Weapon club = Weapon("");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	cout << endl;
	{
		Weapon club = Weapon("");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	cout << endl;
	{
		Weapon club = Weapon("Late Weapon");
		HumanB jim("Jim");
		jim.attack();
		jim.setWeapon(club);
		jim.attack();
	}
	return 0;
}