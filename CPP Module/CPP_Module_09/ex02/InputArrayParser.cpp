#include "InputArrayParser.hpp"

/* exceptions */

const char	*InputArrayParser::NegativeValueException::what() const throw()
{
	return ("Error : Negative Value Exception");
}

const char	*InputArrayParser::AdaptationFailedException::what() const throw()
{
	return ("Error : Adaption Failed Exception");
}


/* Orthodox Cannonical Form(private part) */
InputArrayParser::InputArrayParser() : parsedArray() {}
InputArrayParser::InputArrayParser(const InputArrayParser &cp) : parsedArray() { (void)cp; }

InputArrayParser	&InputArrayParser::operator=(const InputArrayParser &rhv)
{
	(void)rhv;
	return (*this);
}

/* private member function */
// main logic
void			InputArrayParser::parseLinesToArray(char **lines) \
	throw (NegativeValueException, AdaptationFailedException)
{
	int	i = 1;

	while (lines[i])
	{
		istringstream	lineParser(lines[i]);
		int				buffer;

		while (!lineParser.eof() && lineParser >> buffer)
		{
			if (buffer < 0)
				throw (NegativeValueException());
			parsedArray.push_back(buffer);
		}

		if (lineParser.fail())
			throw (AdaptationFailedException());
		
		i += 1;
	}	
}

/* Orthodox Cannonical Form(public part) */
InputArrayParser::~InputArrayParser() {}

/* Constructor */
InputArrayParser::InputArrayParser(char **lines) \
	throw (NegativeValueException, AdaptationFailedException) : parsedArray()
{
	parseLinesToArray(lines);
}

/* public member function */
// getter
const vector<int>	&InputArrayParser::getParsedArray()
{
	return (parsedArray);
}