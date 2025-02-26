#include "ScavTrap.hpp"

/* Orthodox Canonical Form */
ScavTrap::ScavTrap() : ClapTrap("PolarBear", 100, 50, 20), gateKeeperMode(false)
{
	printScavConstructorMsg();
}
ScavTrap::ScavTrap(const ScavTrap &cp) : ClapTrap(cp), gateKeeperMode(cp.gateKeeperMode)
{
	printScavConstructorMsg();
}

ScavTrap::~ScavTrap()
{
	cout << "ScavTrap is gone first." << endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &rhv)
{
	ClapTrap::operator=(rhv);
	gateKeeperMode = rhv.gateKeeperMode;
	return (*this);
}

/* Constructor */
ScavTrap::ScavTrap(const string &name) : ClapTrap(name, 100, 50, 20), gateKeeperMode(false)
{
	printScavConstructorMsg();
}

/* public member function */
void	ScavTrap::guardGate()
{
	if (gateKeeperMode)
		cout << "ScavTrap is already on Gate Keeper Mode." << endl;
	else
	{
		gateKeeperMode = true;
		cout << "ScavTrap is now on Gate Keeper Mode." << endl;
	}	
}

void	ScavTrap::showStatus()
{
	cout << "++++++++++++++++++++++++++++++++++" << endl;
	cout << "Attributes of ScavTrap" << endl;
	if (gateKeeperMode)
		cout << "gateKeeperMode : ON" << endl;
	else
		cout << "gateKeeperMode : OFF" << endl;
	ClapTrap::showStatus();
	cout << "++++++++++++++++++++++++++++++++++" << endl;
}

void	ScavTrap::attack(const string &target)
{
	cout << "ScavTrap::";
	ClapTrap::attack(target);
}

/* protected member function */
void	ScavTrap::printScavConstructorMsg()
{
	cout << "And ScavTrap inherited it." << endl;
}