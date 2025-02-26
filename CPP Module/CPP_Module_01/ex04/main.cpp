#include "Copier.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		cout<<"Error : You must input 3 paramaters."<<endl;
		exit(1);
	}
	if (argv[2][0] == 0)
	{
		cout<<"Error : s1 must not be null."<<endl;
		exit(1);
	}

	Copier	cp(argv[1], argv[2], argv[3]);
	cp.copyFile();

	return (0);
}