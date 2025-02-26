#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		cout<<"Error : You must input 1 level."<<endl;
		exit(1);
	}
	
	Harl	harl;
	
	harl.complain(argv[1]);

	return (0);
}