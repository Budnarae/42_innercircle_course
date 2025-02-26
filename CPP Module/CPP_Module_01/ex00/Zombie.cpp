#include "Zombie.hpp"

/*public constructor*/

//default constructor
Zombie::Zombie( void ) {};

//constructor with string
Zombie::Zombie(string name)
{
	this->name = name;
}

/*destructor*/

Zombie::~Zombie()
{
	cout<<name<<" destroyed"<<endl;
}

/*public member function*/

void	Zombie::announce( void ) const
{
	cout<<name<<": BraiiiiiiinnnzzzZ..."<<endl;
}
