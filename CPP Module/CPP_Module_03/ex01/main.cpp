#include "ScavTrap.hpp"

int main()
{
	{
		cout << "Testing Constructor Msg and guardGate()" << endl << endl;

		ScavTrap	a;
		a.guardGate();

		ScavTrap	b("Bob");
		b.guardGate();

		ScavTrap	c(b);
		ScavTrap	d("Dummy for testing operator=");
		ScavTrap	e("LazyTrap(not guarding)");

		d = a;
		
		cout << endl;

		a.showStatus();
		b.showStatus();
		c.showStatus();
		d.showStatus();
		e.showStatus();
	}

	cout << endl;
	
	{
		cout << "Testing ClapTrap member function" << endl << endl;

		ScavTrap	a("App");
		ScavTrap	b("Bob");
		ScavTrap	c("Carl");

		cout << endl;

		b.attack("nobody");
		b.attack("Carl");
		c.beRepaired(10);
		c.attack("App");

		cout << endl;

		a.showStatus();
		b.showStatus();
		c.showStatus();

		cout << endl;
	}

	return (0);
}
