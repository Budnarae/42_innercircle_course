#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private	:
		string	name;
		int		hit_point;
		int		energy_point;
		int		attack_damage;
	public	:
		/* Orthodox Canonical Form */
		DiamondTrap();
		DiamondTrap(const DiamondTrap &cp);
		~DiamondTrap();
		DiamondTrap	&operator=(const DiamondTrap &rhv);
		/* Constructor*/
		DiamondTrap(const string &name);
		/* public member function */
		void	attack(const string &target);
		void	whoAmI();
		void	showStatus();
	private	:
		/* private member function */
		void	printDiamondConstructorMsg();
};

#endif