#include "RPN.hpp"

/* Exceptions */
const char	*RPN::NotAOperatorException::what() const throw()
{
	return ("Error : character which isn't operator is in expression.");
}

const char	*RPN::NoEnoughNumberException::what() const throw()
{
	return ("Error : there's no enough numbers in stack for operaton.");
}

const char	*RPN::TooMuchNumberException::what() const throw()
{
	return ("Error : there's too much numbers in stack for operaton.");
}

const char	*RPN::NoDelimeterInExpressionException::what() const throw()
{
	return ("Error : there must be space between elements.");
}

const char	*RPN::DivideWithZeroException::what() const throw()
{
	return ("Error : trying to divide with zero.");
}

/* orthdox cannonical form : private part */
RPN::RPN() {}
RPN::RPN(const RPN &cp) { (void)cp; }

RPN	&RPN::operator=(const RPN &rhv)
{
	(void)rhv;
	return (*this);
}

/* orthodox cannonical form : public part */
RPN::~RPN() {}

/* constructor */
RPN::RPN(const string &_expression) : expression(_expression) {}

/* public member function */
void	RPN::checkOperator(char c) const throw (NotAOperatorException)
{
	if (c != '*' && c != '/' && c != '+' && c != '-')
		throw (NotAOperatorException());
}

void	RPN::applyOperator(stack<int> &numberHolder, char op) const throw (DivideWithZeroException)
{
	int	num2 = numberHolder.top();
	numberHolder.pop();

	int	num1 = numberHolder.top();
	numberHolder.pop();

	int	result;

	switch (op)
	{
		case '*':
			result = num1 * num2;
			break;
		case '/':
			if (num2 == 0)
				throw (DivideWithZeroException());
			result = num1 / num2;
			break;
		case '+':
			result = num1 + num2;
			break;
		case '-':
			result = num1 - num2;
			break;
		default:
			break;
	}

	numberHolder.push(result);
}

void	RPN::checkDelimeter(istringstream &expressionParser) const \
	throw (NoDelimeterInExpressionException)
{
	char	buffer;
	expressionParser >> buffer;

	if (expressionParser.eof())
		return ;

	if (buffer != ' ')
		throw (NoDelimeterInExpressionException());
	
	while (expressionParser >> buffer)
	{
		if (buffer != ' ')
		{
			expressionParser.unget();
			break;
		}
	}
}

void	RPN::calculate() const
{
	istringstream	expressionParser(expression);
	stack<int>		numberHolder;
	char			buffer;

	expressionParser >> std::noskipws;

	try
	{
		while (expressionParser >> buffer)
		{
			if (isdigit(buffer))
				numberHolder.push(buffer - '0');
			else
			{
				checkOperator(buffer);
				if (numberHolder.size() < 2)
					throw (NoEnoughNumberException());
				applyOperator(numberHolder, buffer);
			}
			checkDelimeter(expressionParser);
		}
		if (numberHolder.size() != 1)
			throw (TooMuchNumberException());
		cout << numberHolder.top() << endl;
	}
	catch(const exception& e)
	{
		cout << e.what() << endl;
	}
}
