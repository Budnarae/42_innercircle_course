#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"

/*
void	checkLeak()
{
	system("leaks rpg");
}
*/

int main()
{
	//atexit(checkLeak);
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");
	
	me->use(0, *bob);
	me->use(1, *bob);

	me->unequip(0);
	me->unequip(1);
	
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);

	tmp = src->createMateria("cure");
	bob->equip(tmp);
	tmp = src->createMateria("cure");
	bob->equip(tmp);

	bob->unequip(0);
	bob->unequip(1);
	
	tmp = src->createMateria("cure");
	bob->equip(tmp);
	tmp = src->createMateria("cure");
	bob->equip(tmp);

	me->use(0, *bob);
	me->use(1, *bob);
	bob->use(0, *me);
	bob->use(1, *me);
	
	delete bob;
	delete me;
	delete src;

	return 0;
}