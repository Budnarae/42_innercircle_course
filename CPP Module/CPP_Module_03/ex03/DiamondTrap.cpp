#include "DiamondTrap.hpp"

/* Orthodox Canonical Form */
DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
	name = "PolarBear";
	ClapTrap::name = ClapTrap::name + "_clap_name";
	hit_point = FragTrap::hit_point;
	energy_point = ScavTrap::energy_point;
	attack_damage = FragTrap::attack_damage;

	printDiamondConstructorMsg();
}

DiamondTrap::DiamondTrap(const DiamondTrap &cp) : ClapTrap(cp), ScavTrap(cp), FragTrap(cp)
{
	name = cp.name;
	hit_point = cp.hit_point;
	energy_point = cp.energy_point;
	attack_damage = cp.attack_damage;

	printDiamondConstructorMsg();
}

DiamondTrap::~DiamondTrap()
{
	cout << "DiamondTrap is gone first." << endl;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &rhv)
{
	name = rhv.name;
	hit_point = rhv.hit_point;
	energy_point = rhv.energy_point;
	attack_damage = rhv.attack_damage;

	ClapTrap::operator=(rhv);
	gateKeeperMode = rhv.gateKeeperMode;
	numHighFive = rhv.numHighFive;

	return (*this);
}

/* Constructor */
DiamondTrap::DiamondTrap(const string &name) : ClapTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name")
{
	this->name = name;
	hit_point = FragTrap::hit_point;
	energy_point = ScavTrap::energy_point;
	attack_damage = FragTrap::attack_damage;

	printDiamondConstructorMsg();
}

/* public member function */
void	DiamondTrap::attack(const string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	cout << "Name of DiamondTrap : " << name << endl;
	cout << "Name of ClapTrap : " << ClapTrap::name << endl;
}

void	DiamondTrap::showStatus()
{
	cout << "++++++++++++++++++++++++++++++++++" << endl;
	cout << "Attributes of ScavTrap" << endl;
	if (gateKeeperMode)
		cout << "gateKeeperMode : ON" << endl;
	else
		cout << "gateKeeperMode : OFF" << endl;
	cout << "----------------------------------" << endl;
	cout << "Attributes of FragTrap" << endl;
	cout << "Number of times FragTrap high fived : " << numHighFive << endl;
	cout << "----------------------------------" << endl;
	cout << "Attributes of DiamondTrap" << endl;
	cout << "name : " << name << endl;
	cout << "hit point : " << hit_point << endl;
	cout << "energy point : " << energy_point << endl;
	cout << "attack damage : " << attack_damage << endl;
	ClapTrap::showStatus();
	cout << "++++++++++++++++++++++++++++++++++" << endl;
}

/* private member function */
void	DiamondTrap::printDiamondConstructorMsg()
{
	cout << "And DiamondTrap inherited it." << endl;
}