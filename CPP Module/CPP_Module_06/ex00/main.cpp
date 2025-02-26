#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc !=2)
	{
		cout << "Error : You should input must 1 parameter." << endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);

	return (0);
}
