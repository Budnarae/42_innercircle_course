#include "FragTrap.hpp"

/* Orthodox Canonical Form */
FragTrap::FragTrap() : ClapTrap("PolarBear", 100, 100, 30), numHighFive(0)
{
	printFragConstructorMsg();
}
FragTrap::FragTrap(const FragTrap &cp) : ClapTrap(cp), numHighFive(cp.numHighFive)
{
	printFragConstructorMsg();
}

FragTrap::~FragTrap()
{
	cout << "FragTrap is gone first." << endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &rhv)
{
	ClapTrap::operator=(rhv);
	numHighFive = rhv.numHighFive;
	return (*this);
}

/* Constructor */
FragTrap::FragTrap(const string &name) : ClapTrap(name, 100, 100, 30), numHighFive(0)
{
	printFragConstructorMsg();
}

/* public member function */
void	FragTrap::highFivesGuys(void)
{
	numHighFive++;
	cout << "FragTrap high fived with you joyfully." << endl;
}

void	FragTrap::showStatus()
{
	cout << "++++++++++++++++++++++++++++++++++" << endl;
	cout << "Attributes of FragTrap" << endl;
	cout << "Number of times FragTrap high fived : " << numHighFive << endl;
	ClapTrap::showStatus();
	cout << "++++++++++++++++++++++++++++++++++" << endl;
}

/* protected member function */
void	FragTrap::printFragConstructorMsg()
{
	cout << "And FragTrap inherited it." << endl;
}