#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	private :
		Weapon	&wp;
		string	name;
	public :
		HumanA(const string &name, Weapon &wp);
		void	attack();
};

#endif