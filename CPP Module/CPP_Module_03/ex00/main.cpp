#include "ClapTrap.hpp"

int main()
{
	{
		cout << "Testing Constructor Msg" << endl << endl;

		ClapTrap	a;
		ClapTrap	b("Bob");
		ClapTrap	c(b);
		ClapTrap	d("Dummy for testing operator=");

		d = a;
		
		cout << endl;

		a.showStatus();
		b.showStatus();
		c.showStatus();
		d.showStatus();
	}
	
	cout << endl;
	
	{
		cout << "Testing ClapTrap member function" << endl << endl;

		ClapTrap	a("App");
		ClapTrap	b("Bob");
		ClapTrap	c("Carl");

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
