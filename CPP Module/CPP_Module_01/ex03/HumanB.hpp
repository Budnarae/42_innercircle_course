#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	private :
		Weapon	*wp;
		string	name;
	public :
		HumanB(const string &name);
		void	setWeapon(Weapon &wp);
		void	attack();
};

#endif