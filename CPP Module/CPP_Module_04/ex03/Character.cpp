#include "Character.hpp"

/* Orthodox Canonical Form */
Character::Character()
{
	setInventoryZero();
}

Character::Character(const Character &cp)
{
	setInventoryZero();
	*this = cp;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i])
			delete inventory[i];
	}

	clearFloor();
}

Character	&Character::operator=(const Character &rhv)
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i])
		{
			delete inventory[i];
			inventory[i] = NULL;
		}
		if (rhv.inventory[i])
			inventory[i] = rhv.inventory[i]->clone();
	}
	return (*this);
}

/* Constructor */
Character::Character(const string &name) : name(name)
{
	setInventoryZero();
}

/* public member function */
bool	Character::checkIndexRange(int idx)
{
	if (idx < 0 || idx > 4)
	{
		cout << "error : idx must be in [0, 3]" << endl;
		return (false);
	}
	return (true);	
}

void	Character::setInventoryZero()
{
	for (int i = 0; i < 4; i++)
		inventory[i] = 0;
}

/* public virtual function */
string const & Character::getName() const
{
	return (name);
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] == 0)
		{
			inventory[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx)
{
	if (!checkIndexRange(idx))
		return ;
	
	dropEquipmentOnFloor(inventory[idx]);
	inventory[idx] = 0;
}

void Character::use(int idx, ICharacter& target)
{
	if (!checkIndexRange(idx))
		return ;
	if (inventory[idx])
		inventory[idx]->use(target);
	else
		cout << "There's nothing in that slot." << endl;
}

/* private member variable */
s_floor	*Character::floor = 0;

/* private member function */
void	Character::dropEquipmentOnFloor(AMateria *m)
{
	if (floor == 0)
	{
		floor = new s_floor;
		floor->m = m;
		floor->next = 0;
	}
	else
	{
		s_floor	*tmp = floor;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new s_floor;
		tmp = tmp->next;
		tmp->m = m;
		tmp->next = 0;
	}
}

void	Character::clearFloor()
{
	s_floor	*tmp;

	if (floor == 0)
		return ;

	while (floor)
	{
		tmp = floor;
		floor = floor->next;
		delete tmp->m;
		delete tmp;
	}
}