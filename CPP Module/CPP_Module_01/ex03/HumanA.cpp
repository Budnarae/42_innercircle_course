#include "HumanA.hpp"

/*constructor*/

HumanA::HumanA(const string &name, Weapon &wp) : wp(wp), name(name)
{
}

/*public general function*/

void	HumanA::attack()
{
	if (wp.getType().empty())
		cout<<name<<" attacks with his default weapon"<<endl;
	else
		cout<<name<<" attacks with their "<<wp.getType()<<endl;
}
