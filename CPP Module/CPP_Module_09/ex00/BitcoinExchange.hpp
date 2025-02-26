#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <exception>
#include <map>

// using namespace std;

using	std::cout;
using	std::cerr;
using	std::endl;
using	std::ifstream;
using	std::istringstream;
using	std::string;
using	std::getline;
using	std::pair;
using	std::map;

class BitcoinExchange
{
	private	:
		/* private member variable */
		const string		inputFileName;
		map<string, double>	priceByDate;

		/* Exceptions */
		// about file
		class DatabaseOpenFailedException : public std::exception
		{
			public	:
				virtual const char *what() const throw();
		};
		class InputFileOpenFailedException : public std::exception
		{
			public	:
				virtual const char *what() const throw();
		};
		class FileEmptyException : public std::exception
		{
			public	:
				virtual const char *what() const throw();
		};
		// about syntax
		class WrongHeaderException : public std::exception
		{
			public	:
				virtual const char *what() const throw();
		};
		class NoDelimeterInLineException : public std::exception
		{
			public	:
				virtual const char *what() const throw();
		};
		class WrongDateFormatException : public std::exception
		{
			public	:
				virtual const char *what() const throw();
		};
		class WrongValueFormatException : public std::exception
		{
			public	:
				virtual const char *what() const throw();
		};
		class NotAPositiveValueException : public std::exception
		{
			public	:
				virtual const char *what() const throw();
		};
		class TooLargeValueException : public std::exception
		{
			public	:
				virtual const char *what() const throw();
		};

		/* Orthodox Cannonical Form(private part) */
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &cp);
		BitcoinExchange	&operator=(const BitcoinExchange &rhv);

		/* private member function */
		// check format
		void	checkFileEmpty(ifstream &database) throw (FileEmptyException);
		void	checkHeaderFormat(ifstream &database, const string &headerLine) \
			throw (WrongHeaderException);
		void	checkDateFormat(const string &date) throw (WrongDateFormatException);
		// parse function
		void					eraseSpaceAtFrontAndBack(string &s);
		pair<string, double>	parseDateAndValueWithDelimeter(const string &line, char delim) \
			throw (NoDelimeterInLineException, WrongDateFormatException, \
			WrongValueFormatException, NotAPositiveValueException);
		void					retrieveBitcoinPriceByDate() \
			throw (DatabaseOpenFailedException);
	public	:
		/* Orthodox Cannonical Form(public part) */
		~BitcoinExchange();
		/* constructor */
		BitcoinExchange(const string &inputFileName) \
			throw(BitcoinExchange::DatabaseOpenFailedException);

		/* key function */
		void					printBitcoinTotalByDate() \
			throw (InputFileOpenFailedException);
};

#endif
