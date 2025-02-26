#include "FragTrap.hpp"

int main()
{
	{
		cout << "Testing Constructor Msg and guardGate()" << endl << endl;

		FragTrap	a;
		a.highFivesGuys();

		FragTrap	b("Bob");
		b.highFivesGuys();
		b.highFivesGuys();

		FragTrap	c(b);
		FragTrap	d("Dummy for testing operator=");
		FragTrap	e("LazyTrap(never highfive)");

		d = a;
		
		cout << endl;

		a.showStatus();
		b.showStatus();
		c.showStatus();
		d.showStatus();
		e.showStatus();

		cout << endl;
	}
	
	cout << "Testing ClapTrap member function" << endl << endl;

	{
		FragTrap	a("App");
		FragTrap	b("Bob");
		FragTrap	c("Carl");

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
