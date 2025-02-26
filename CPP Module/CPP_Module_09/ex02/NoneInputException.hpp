#ifndef NONEINPUTEXCEPTION
#define NONEINPUTEXCEPTION

#include <exception>

using std::exception;

class NoneInputException : public exception
{
	public	:
		virtual const char	*what() const throw();	
};

#endif