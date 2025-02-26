#ifndef	CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <cstring>

using	std::string;
using	std::cout;
using	std::endl;

class ClapTrap;

struct trapList
{
	ClapTrap	*trap;
	trapList	*next;
};

class ClapTrap
{
	protected	:
		/* protected member variable */
		string	name;
		int		hit_point;
		int		energy_point;
		int		attack_damage;
	public		:
		/* Orthodox Canonical Form */
		ClapTrap();
		ClapTrap(const ClapTrap &cp);
		~ClapTrap();
		ClapTrap	&operator=(const ClapTrap &rhv);
		/* Constructor */
		ClapTrap(const string &name);
		ClapTrap(const string &name, int hp, int ep, int ad);
		/* public member function */
		void	attack(const string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	showStatus();
	protected		:
		/* protected member function */
		void	printClapConstructorMsg(string s);
		bool	checkTrapVitality();
		/* protected static member variable */
		static trapList	*allTrap;
		/* protected static member function */
		static void		addTrapToList(ClapTrap *trap);
		static void		deleteTrapList();
		static ClapTrap	*findTrapByName(const string &name);
};

#endif
