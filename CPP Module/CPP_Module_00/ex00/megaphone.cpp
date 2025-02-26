#include <iostream>

int main(int argc, char **argv)
{
	std::string	buf;

	if (argc == 1)
		std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < argc; i++)
			buf += argv[i];
		for (int i = 0; i < (int)buf.length(); i++)
			buf[i] = std::toupper(buf[i]);
		std::cout<<buf<<std::endl;
	}
}