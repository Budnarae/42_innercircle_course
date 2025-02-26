#include "DiamondTrap.hpp"

int main()
{
	{
		cout << "Testing Constructor Msg and guardGate()" << endl << endl;

		DiamondTrap	a;
		a.highFivesGuys();

		DiamondTrap	b("Bob");
		b.highFivesGuys();
		b.highFivesGuys();

		DiamondTrap	c(b);
		DiamondTrap	d("Dummy for testing operator=");
		DiamondTrap	e("LazyTrap(never highfive)");

		d = a;
		
		cout << endl;

		a.showStatus();
		b.showStatus();
		c.showStatus();
		d.showStatus();
		e.showStatus();

		cout << endl;
	}
	
	cout << "Testing DiamondTrap member function" << endl << endl;

	{
		DiamondTrap	a("App");
		DiamondTrap	b("Bob");
		DiamondTrap	c("Carl");

		cout << endl;

		b.attack("nobody");
		b.attack("Carl_clap_name");
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