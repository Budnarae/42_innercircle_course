#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <limits>

using	std::cout;
using	std::endl;
using	std::string;
using	std::numeric_limits;
using	std::isdigit;

class ScalarConverter
{
	private	:
		/* Orthodox Canonical Form(private part) */
		ScalarConverter();
		ScalarConverter(const ScalarConverter &cp);
		~ScalarConverter();
		ScalarConverter	&operator=(const ScalarConverter &rhv);
	public	:
		/* public static function */
		static void	convert(char *str);
};

#endif