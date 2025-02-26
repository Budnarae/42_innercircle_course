#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		cout << "Error : There must be 1 expression." << endl;
		return (1);
	}

	try
	{
		RPN	rpn(argv[1]);
		rpn.calculate();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
