#include "NoneInputException.hpp"

const char	*NoneInputException::what() const throw()
{
	return ("Error : there must be an array input.");	
}
