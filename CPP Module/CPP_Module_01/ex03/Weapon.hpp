#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;

class Weapon
{
	private :
		string	type;
	public :
		Weapon(const string &type);
		const string	&getType() const;
		void			setType(string type);
};

#endif