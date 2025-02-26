#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Zombie
{
	private :
		string	name;
	public :
		Zombie( void );
		Zombie(string name);
		Zombie(const Zombie &cp);
		~Zombie();

		void	announce( void ) const;
};

void	randomChump( string name );
Zombie	*newZombie( string name );

#endif
