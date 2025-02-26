#ifndef INPUTARRAYPARSER_HPP
#define INPUTARRAYPARSER_HPP

#include <vector>
#include <string>
#include <sstream>
#include <exception>

using std::vector;
using std::string;
using std::istringstream;
using std::exception;

class InputArrayParser
{
	private	:
		/* exceptions */
		class NegativeValueException : public exception
		{
			public	:
				virtual const char	*what() const throw();
		};

		class AdaptationFailedException : public exception
		{
			public	:
				virtual const char	*what() const throw();
		};
		/* private member variable */
		vector<int>	parsedArray;
		/* Orthodox Cannonical Form(private part) */
		InputArrayParser();
		InputArrayParser(const InputArrayParser &cp);
		InputArrayParser	&operator=(const InputArrayParser &rhv);
		/* private member function */
		// main logic
		void			parseLinesToArray(char **lines) \
			throw (NegativeValueException, AdaptationFailedException);
	public	:
		/* Orthodox Cannonical Form(public part) */
		~InputArrayParser();
		/* Constructor */
		InputArrayParser(char **lines)
			throw (NegativeValueException, AdaptationFailedException);
		/* public member function */
		// getter
		const vector<int>	&getParsedArray();
};

#endif