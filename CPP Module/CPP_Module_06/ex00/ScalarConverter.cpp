#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &cp) {(void)cp;}
ScalarConverter::~ScalarConverter() {}
ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &rhv)
{
	(void)rhv;
	return (*this);
}

/* public static function */
void	ScalarConverter::convert(char *str)
{
	string	s(str);
	if (s.length() == 1 && !isdigit(s[0]))
	{
		char	tmp[4];
		tmp[0] = s[0] / 100 + '0';
		tmp[1] = (s[0] - s[0] / 100 * 100) / 10 + '0';
		tmp[2] = (s[0] - s[0] / 100 * 100) % 10 + '0';
		tmp[3] = '\0';
		s = string(tmp);
	}
	if (s[s.length() - 1] == 'f')
		s.erase(s.length() - 1, 1);
	
	int	howManyDot = 0;

	if (s != "nan")
	{
		for (size_t i = 0; i < s.length(); i++)
		{
			if (i == 0 && s[i] == '-')
				continue;
			if (s[i] == '.')
			{
				howManyDot++;
				if (howManyDot == 1)
					continue;
			}
			if (!isdigit(s[i]))
			{
				cout << "char: " << "impossible" << endl;
				cout << "int: " << "impossible" << endl;
				cout << "float: " << "impossible" << endl;
				cout << "double: " << "impossible" << endl;
				return ;
			}
		}
	}

	std::istringstream	iss(s);
	double				d = 0;

	iss >> d;

	if (iss.fail() && \
		!(d == numeric_limits<double>::infinity() \
		|| d == -numeric_limits<double>::infinity()))
	{
		cout << "char: " << "impossible" << endl;
		cout << "int: " << "impossible" << endl;
		cout << "float: " << "impossible" << endl;
		cout << "double: " << "impossible" << endl;
	}
	else if (d != d)
	{
		cout << "char: " << "impossible" << endl;
		cout << "int: " << "impossible" << endl;
		cout << "float: " << static_cast<float>(d) << "f" << endl;
		cout << "double: " << d << endl;
	}
	else
	{
		cout << std::fixed;
		cout.precision(1);

		cout << "char: ";
		if (d < numeric_limits<char>::min() \
			|| d > numeric_limits<char>::max())
			cout << "Out of valid range" << endl;
		else if (d <= 32 || d == 127)
			cout << "Non displayable" << endl;
		else
			cout << "'" << static_cast<char>(d) << "'" << endl;
		
		cout << "int: ";
		if (d < numeric_limits<int>::min() \
			|| d > numeric_limits<int>::max())
			cout << "Out of valid range" << endl;
		else
			cout << static_cast<int>(d) << endl;
		
		cout << "float: " << static_cast<float>(d) << "f" << endl;
		cout << "double: " << d << endl;
	}
}
