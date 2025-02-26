#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	protected	:
		bool	gateKeeperMode;
	public		:
		/* Orthodox Canonical Form */
		ScavTrap();
		ScavTrap(const ScavTrap &cp);
		~ScavTrap();
		ScavTrap	&operator=(const ScavTrap &rhv);
		/* Constructor */
		ScavTrap(const string &name);
		/* public member function */
		void	guardGate();
		void	showStatus();
		void	attack(const string &target);
	protected	:
		/* protected member function */
		void	printScavConstructorMsg();
};

#endif