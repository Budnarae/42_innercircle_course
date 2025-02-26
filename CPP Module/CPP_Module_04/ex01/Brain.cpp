#include "Brain.hpp"

char	getRandomChar()
{
	char	c;

	std::srand(std::time(NULL));
	c = std::rand() % 26 + 65;
	usleep(5000);
	return (c);
}

/* orthodox canonical form(private part) */
Brain::Brain(const Brain &cp)
{
	*this = cp;
}

/* orthodox canonical form */
Brain::Brain()
{
	for (int i = 0; i < 100; i++)
		ideas[i] = getRandomChar();
	
	cout << "Constructor of brain called." << endl;
}

Brain::~Brain()
{
	cout << "Destructor of brain called." << endl;
}

Brain	&Brain::operator=(const Brain &rhv)
{
	for (int i = 0; i < 100; i++)
		ideas[i] = rhv.ideas[i];
	return (*this);
}

/* public member function */
void	Brain::showIdeas() const
{
	for (int i = 0; i < 100; i++)
		cout << ideas[i];
	cout << endl;
}
