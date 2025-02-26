#include "BitcoinExchange.hpp"

/* Exceptions */
// about file
const char	*BitcoinExchange::DatabaseOpenFailedException::what() const throw()
{
	return ("Error : database open failed.");
}

const char	*BitcoinExchange::InputFileOpenFailedException::what() const throw()
{
	return ("Error : input file open failed.");
}

const char	*BitcoinExchange::FileEmptyException::what() const throw()
{
	return ("Error : file is empty.");
}

// about syntax
const char	*BitcoinExchange::WrongHeaderException::what() const throw()
{
	return ("Error : wrong header format.");
}

const char	*BitcoinExchange::NoDelimeterInLineException::what() const throw()
{
	return ("Error : There's no delimeter in line.");
}

const char	*BitcoinExchange::WrongDateFormatException::what() const throw()
{
	return ("Error : wrong date format.");
}

const char	*BitcoinExchange::WrongValueFormatException::what() const throw()
{
	return ("Error : wrong value format.");
}

const char	*BitcoinExchange::NotAPositiveValueException::what() const throw()
{
	return ("Error : not a positive number.");
}

const char	*BitcoinExchange::TooLargeValueException::what() const throw()
{
	return ("Error : too large a number.");
}

/* Orthodox Cannonical Form(private part) */
BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &cp) { (void)cp; }

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &rhv)
{
	(void)rhv;
	return (*this);
}

/* private member function */
// check format
void	BitcoinExchange::checkFileEmpty(ifstream &database) \
	throw (FileEmptyException)
{
	if (database.eof())
		throw (FileEmptyException());
}

void	BitcoinExchange::checkHeaderFormat(ifstream &database, const string &headerLine) \
	throw (WrongHeaderException)
{
	string	line;
	getline(database, line);

	if (line != headerLine)
		throw (WrongHeaderException());
}

void	BitcoinExchange::checkDateFormat(const string &date) \
	throw (WrongDateFormatException)
{
	istringstream	dateParser(date);
	int				year;
	int				month;
	int				day;
	int				dayArr[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	char			buf;

	// 년 월 일에 숫자가 아닌 문자가 있으면 throw
	// '-' 기호가 올바른 위치에 없으면 throw
	// 년 월 일이 일반적인 범위를 넘으면 (ex : -3년, 13월, 57일 등등) throw
	dateParser >> year;
	if (dateParser.fail() || year < 0)
		throw (WrongDateFormatException());
	// 윤년 처리
	if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
		dayArr[1] += 1;
	dateParser >> buf;
	if (dateParser.fail() || buf != '-')
		throw (WrongDateFormatException());
	dateParser >> month;
	if (dateParser.fail() || (month < 1 || month > 12))
		throw (WrongDateFormatException());
	dateParser >> buf;
	if (dateParser.fail() || buf != '-')
		throw (WrongDateFormatException());
	dateParser >> day;
	if (dateParser.fail() || (day < 1 || day > dayArr[month - 1]))
		throw (WrongDateFormatException());
	if (!dateParser.eof())
		throw (WrongDateFormatException());
}

// parse function
void					BitcoinExchange::eraseSpaceAtFrontAndBack(string &s)
{
	while (s[0] == ' ')
		s.erase(0, 1);
	while (s[s.length() - 1] == ' ')
		s.erase(s.length() - 1, 1);
}

pair<string, double>	BitcoinExchange::parseDateAndValueWithDelimeter(const string &line, char delim) \
	throw (NoDelimeterInLineException, WrongDateFormatException, \
	WrongValueFormatException, NotAPositiveValueException)
{
	pair<string, double>	dateValue;
	istringstream	lineParser(line);

	// 문자열에 구분자가 포함되어 있지 않으면 throw
	if (getline(lineParser, dateValue.first, delim).eof())
		throw (NoDelimeterInLineException());
	
	// 날짜 형식을 지키지 않았으면 throw
	eraseSpaceAtFrontAndBack(dateValue.first);
	checkDateFormat(dateValue.first);

	lineParser >> dateValue.second;
	// 값 부분에 숫자가 아닌 문자가 섞여있으면 throw
	// 값이 [0, 1000] 범위를 넘어가면 throw
	if (lineParser.fail() || !lineParser.eof())
		throw (WrongValueFormatException());
	if (dateValue.second < 0)
		throw (NotAPositiveValueException());

	return (dateValue);
}

void	BitcoinExchange::retrieveBitcoinPriceByDate() \
	throw (DatabaseOpenFailedException)
{
	ifstream	database("data.csv");
	if (database.fail())
		throw (DatabaseOpenFailedException());

	try
	{
		// 파일이 빈 파일인지 검사한다. 빈 파일이면 리턴한다.
		checkFileEmpty(database);
		// 헤더 라인이 올바른지 검사한다. 올바르지 않으면 에러 메세지를 출력하고 다음 절차를 진행한다.
		checkHeaderFormat(database, "date,exchange_rate");
	}
	catch(const FileEmptyException& e)
	{
		cerr << e.what() << '\n';
		return ;
	}
	catch(const WrongHeaderException& e)
	{
		cerr << e.what() << '\n';
	}

	string	line;
	while (getline(database, line))
	{
		pair<string, double>	datePrice;
		
		try
		{
			datePrice = parseDateAndValueWithDelimeter(line, ',');
		}
		catch(const std::exception& e)
		{
			cerr << e.what() << '\n';
			continue;
		}
		
		priceByDate.insert(datePrice);
	}
}

/* Orthodox Cannonical Form(public part) */
BitcoinExchange::~BitcoinExchange() {}

/* constructor */
BitcoinExchange::BitcoinExchange(const string &inputFileName) \
	throw (BitcoinExchange::DatabaseOpenFailedException)
	: inputFileName(inputFileName) \
{
	retrieveBitcoinPriceByDate();
}

void	BitcoinExchange::printBitcoinTotalByDate() \
	throw (InputFileOpenFailedException)
{
	std::ifstream	inputFile(inputFileName);
	if (inputFile.fail())
		throw (BitcoinExchange::InputFileOpenFailedException());
	
	try
	{
		// 파일이 빈 파일인지 검사한다. 빈 파일이면 리턴한다.
		checkFileEmpty(inputFile);
		// 헤더 라인이 올바른지 검사한다. 올바르지 않으면 에러 메세지를 출력하고 다음 절차를 진행한다.
		checkHeaderFormat(inputFile, "date | value");
	}
	catch(const FileEmptyException& e)
	{
		cerr << e.what() << '\n';
		return ;
	}
	catch(const WrongHeaderException& e)
	{
		cerr << e.what() << '\n';
	}

	string	line;
	while (getline(inputFile, line))
	{
		pair<string, double>	dateAmount;
		
		try
		{
			dateAmount = parseDateAndValueWithDelimeter(line, '|');
			if (dateAmount.second > 1000)
				throw (TooLargeValueException());
		}
		catch(const std::exception& e)
		{
			cerr << e.what() << '\n';
			continue;
		}
		
		pair<string, double>	closestLowerDate;
		for (map<string, double>::iterator	iter = priceByDate.begin(); \
			iter != priceByDate.end(); iter++)
		{
			if (dateAmount.first == iter->first)
			{
				cout << dateAmount.first << " => " << dateAmount.second << " = " \
					 << iter->second * dateAmount.second << endl;
				break ;
			}
			if (dateAmount.first < iter->first)
			{
				cout << dateAmount.first << " => " << dateAmount.second << " = " \
					 << closestLowerDate.second * dateAmount.second << endl;
				break ;
			}
			closestLowerDate = *iter;
		}
	}
}
