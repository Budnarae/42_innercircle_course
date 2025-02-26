#include <iostream>
#include <ctime>

#include "Account.hpp"

using std::cout;
using std::endl;

/*external function*/

void	printNumInBlue(int num)
{
	cout << "\033[34m" << num << "\033[0m";
}

/*initialization of static member variable*/

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/*constructor - public*/

Account::Account( int initial_deposit )
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	_nbAccounts += 1;
	_totalAmount += _amount;

	_displayTimestamp();
	cout<<"index:";
	printNumInBlue(_accountIndex);
	cout<<";amount:";
	printNumInBlue(_amount);
	cout<<";created"<<endl;
}

/*constructor - private*/

Account::Account( void )
{
}

/*destructor*/

Account::~Account( void )
{
	_displayTimestamp();
	cout<<"index:";
	printNumInBlue(_accountIndex);
	cout<<";amount:";
	printNumInBlue(_amount);
	cout<<";closed"<<endl;
}

/*static member function - public*/

int	Account::getNbAccounts( void )
{
	return _nbAccounts;
}

int	Account::getTotalAmount( void )
{
	return _totalAmount;
}

int	Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	cout<<"accounts:";
	printNumInBlue(_nbAccounts);
	cout<<";total:";
	printNumInBlue(_totalAmount);
	cout<<";deposits:";
	printNumInBlue(getNbDeposits());
	cout<<";withdrawals:";
	printNumInBlue(getNbWithdrawals());
	cout<<endl;
}

void	Account::_displayTimestamp( void )
{
	std::time_t current_time;
    std::time(&current_time);

	char	s[80];
	std::strftime(s, sizeof(s), "[%Y%m%d_%H%M%S] ", std::localtime(&current_time));

	cout<<s;
}

//general function

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	cout<<"index:";
	printNumInBlue(_accountIndex);
	cout<<";p_amount:";
	printNumInBlue(_amount);
	cout<<";deposit:";
	printNumInBlue(deposit);

	_amount += deposit;
	_nbDeposits += 1;

	_totalAmount += deposit;
	_totalNbDeposits += 1;

	cout<<";amount:";
	printNumInBlue(_amount);
	cout<<";nb_deposits:";
	printNumInBlue(_nbDeposits);
	cout<<endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	cout<<"index:";
	printNumInBlue(_accountIndex);
	cout<<";p_amount:";
	printNumInBlue(_amount);
	cout<<";withdrawals:";

	if (_amount < withdrawal)
	{
		cout<<"refused"<<endl;
		return false;
	}

	else
	{
		_amount -= withdrawal;
		_nbWithdrawals += 1;

		_totalAmount -= withdrawal;
		_totalNbWithdrawals += 1;

		printNumInBlue(withdrawal);
		cout<<";amount:";
		printNumInBlue(_amount);
		cout<<";nb_withdrawals:";
		printNumInBlue(_nbWithdrawals);
		cout<<endl;

		return true;
	}
}

int	Account::checkAmount( void ) const
{
	return (0);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	cout<<"index:";
	printNumInBlue(_accountIndex);
	cout<<";amount:";
	printNumInBlue(_amount);
	cout<<";deposit:";
	printNumInBlue(_nbDeposits);
	cout<<";withdrawals:";
	printNumInBlue(_nbWithdrawals);
	cout<<endl;
}