#include "ClapTrap.hpp"

/* static member variable initialization */
trapList	*ClapTrap::allTrap = 0;

/* Orthodox Canonical Form */
ClapTrap::ClapTrap() : name("PolarBear"), hit_point(10), energy_point(10), attack_damage(0)
{
	addTrapToList(this);
	printClapConstructorMsg("default");
}

ClapTrap::ClapTrap(const ClapTrap &cp) : name(cp.name), hit_point(cp.hit_point), \
	energy_point(cp.energy_point), attack_damage(cp.attack_damage)
{
	addTrapToList(this);
	printClapConstructorMsg("copy");
}

ClapTrap::~ClapTrap()
{
	deleteTrapList();
	cout << "ClapTrap " << name << " is destroyed." << endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &rhv)
{
	name			= rhv.name;
	hit_point		= rhv.hit_point;
	energy_point	= rhv.energy_point;
	attack_damage	= rhv.attack_damage;

	return (*this);
}

/* Constructor */
ClapTrap::ClapTrap(const string &name) : name(name), hit_point(10), \
	energy_point(10), attack_damage(0)
{
	addTrapToList(this);
	printClapConstructorMsg("with name");
}

ClapTrap::ClapTrap(const string &name, int hp, int ep, int ad) : name(name), \
	hit_point(hp), energy_point(ep), attack_damage(ad)
{
	addTrapToList(this);
	printClapConstructorMsg("with all parameter");
}

/* public member function */
void	ClapTrap::attack(const string &target)
{
	ClapTrap	*ct = findTrapByName(target);

	if (ct == NULL)
		cout << name << " : there's no such trap" << endl;
	else
	{
		if (checkTrapVitality())
		{
			energy_point--;
			cout << "ClapTrap " << name << " attacks " << target \
				<< ", causing " << attack_damage << " points of damage!" << endl;
			ct->takeDamage(attack_damage);
		}
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (hit_point <= 0)
	{
		cout << "ClapTrap " << name << " is already destroyed." << endl;
		return ;
	}

	if (hit_point - amount <= 0)
	{
		hit_point = 0;
		cout << "ClapTrap " << name << " is completely destroyed by this attack." << endl;
	}
	else
	{
		hit_point -= amount;
		cout << "ClapTrap " << name << " got " << amount \
			<< " points of damage by this attack!" << endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (checkTrapVitality())
	{
		energy_point--;
		hit_point += amount;
		cout << "ClapTrap " << name << " repaired itself and regained " \
			<< amount << " of hit point." << endl;
	}
}

void	ClapTrap::showStatus()
{
	cout << "==================================" << endl;
	cout << "Attributes of ClapTrap" << endl;
	cout << "name : " << name << endl;
	cout << "hit point : " << hit_point << endl;
	cout << "energy point : " << energy_point << endl;
	cout << "attack damage : " << attack_damage << endl;
	cout << "==================================" << endl;
}

/* private member function */
void	ClapTrap::printClapConstructorMsg(string s)
{
	cout << "Constructor(" << s << ") of ClapTrap " << name << " is called." << endl;
}

bool	ClapTrap::checkTrapVitality()
{
	if (hit_point <= 0 || energy_point <= 0)
	{
		cout << "ClapTrap " << name << " stopped moving." << endl;
		return (false);
	}
	else
		return (true);
}

/* private static member function */
void	ClapTrap::addTrapToList(ClapTrap *trap)
{
	trapList	*tmp;

	if (allTrap)
	{
		tmp = allTrap;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new trapList;
		tmp = tmp->next;
	}
	else
	{
		allTrap = new trapList;
		tmp = allTrap;
	}
	
	tmp->trap = trap;
	tmp->next = 0;
}

void	ClapTrap::deleteTrapList()
{
	if (allTrap == 0)
		return ;

	trapList	*tmp;
	while (allTrap)
	{
		tmp = allTrap;
		allTrap = allTrap->next;
		delete tmp;
	}
}

ClapTrap	*ClapTrap::findTrapByName(const string &name)
{
	trapList	*tmp = allTrap;

	while (tmp)
	{
		if (tmp->trap->name == name)
			break ;
		tmp = tmp->next;
	}
	
	if (tmp == 0)
		return (NULL);
	else
		return (tmp->trap);
}
