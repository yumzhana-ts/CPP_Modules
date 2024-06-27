#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
    return _nbAccounts;
}

int	Account::getTotalAmount( void )
{
    return _totalAmount;
}

int	Account::getNbDeposits(void)
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
    std::cout << "accounts:" << _nbAccounts << ";";
    std::cout << "total:"<< _totalAmount << ";";
    std::cout << "deposits:"<< _totalNbDeposits << ";";
    std::cout << "withdrawals:"<< _totalNbWithdrawals << std::endl;
}

Account::Account(int initial_deposit): _accountIndex(_nbAccounts++), _amount(initial_deposit)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount<< ";";
    std::cout << "created" << std::endl;
    _totalAmount += _amount;
}

Account::~Account( void )
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount<< ";";
    std::cout << "closed" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
    _nbDeposits++;
    _totalNbDeposits++;
    _totalAmount += deposit;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << _amount<< ";";
    std::cout << "deposit:"<< deposit << ";";
    _amount = deposit +_amount;
    std::cout << "amount:"<< _amount << ";";
    std::cout << "nb_deposits:"<< _nbDeposits << std::endl;
}

//no idea
bool	Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << _amount<< ";";
    if((_amount - withdrawal) > 0)
    {
        _amount = _amount - withdrawal;
        std::cout << "withdrawal:"<< withdrawal << ";";
        std::cout << "amount:"<< _amount << ";";
        std::cout << "nb_withdrawals:"<< _nbDeposits << std::endl;
        _totalNbWithdrawals++;
        _nbWithdrawals++;
        _totalAmount -=withdrawal;
    }
    else 
        std::cout << "withdrawal:refused" << std::endl;
    return (true);
}
int		Account::checkAmount( void ) const
{
    return _amount;
}
void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount<< ";";
    std::cout << "deposits:"<< _nbDeposits << ";";
    std::cout << "withdrawals:"<< _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp(void)
{
	std::time_t time_now;
	time_now = std::time(NULL);
	tm tm = *(std::localtime(&time_now));
	std::cout << "["
	<< tm.tm_year + 1900
	<< std::setfill('0') << std::setw(2) << tm.tm_mon + 1
	<< std::setfill('0') << std::setw(2) << tm.tm_mday
	<< "_"
	<< std::setfill('0') << std::setw(2) << tm.tm_hour
	<< std::setfill('0') << std::setw(2) << tm.tm_min
	<< std::setfill('0') << std::setw(2) << tm.tm_sec
	<< "] ";
}



Account::Account( void ){}

