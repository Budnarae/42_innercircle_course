#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

struct s_floor
{
	AMateria	*m;
	s_floor		*next;
};

class Character : public ICharacter
{
	private	:
		string		name;
		AMateria	*inventory[4];
	public :
		/* Orthodox Canonical Form */
		Character();
		Character(const Character &cp);
		virtual	~Character();
		Character	&operator=(const Character &rhv);
		/* Constructor */
		Character(const string &name);
		/* public member function */
		bool	checkIndexRange(int idx);
		void	setInventoryZero();
		/* public virtual function */
		virtual string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
	private	:
		/* private member variable */
		static s_floor	*floor;
		/* private member function */
		static void	dropEquipmentOnFloor(AMateria *m);
		static void	clearFloor();
};

#endif