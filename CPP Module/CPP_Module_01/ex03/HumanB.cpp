#include "HumanB.hpp"

/*constructor*/

HumanB::HumanB(const string &name) : name(name)
{
	wp = 0;
}

/*public member function*/

void	HumanB::setWeapon(Weapon &wp)
{
	this->wp = &wp;
}

void	HumanB::attack()
{
	if (wp == 0 || wp->getType().empty())
		cout<<name<<" is unarmed"<<endl;
	else
		cout<<name<<" attacks with their "<<wp->getType()<<endl;
}
