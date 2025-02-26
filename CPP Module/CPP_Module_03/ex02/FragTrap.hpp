#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	protected	:
		int	numHighFive;
	public		:
		/* Orthodox Canonical Form */
		FragTrap();
		FragTrap(const FragTrap &cp);
		~FragTrap();
		FragTrap	&operator=(const FragTrap &rhv);
		/* Constructor */
		FragTrap(const string &name);
		/* public member function */
		void	highFivesGuys(void);
		void	showStatus();
	protected	:
		/* protected member function */
		void	printFragConstructorMsg();
};

#endif