#include "Account.hpp"
#include <iostream>

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
    std::cout << "accounts:" << _nbAccounts << ";";
    std::cout << "total:"<< _totalAmount << ";";
    std::cout << "deposits:"<< _totalNbDeposits << ";";
    std::cout << "withdrawals:"<< _totalNbWithdrawals << std::endl;
}

Account::Account(int initial_deposit): _accountIndex(_nbAccounts++), _amount(initial_deposit)
{
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount<< ";";
    std::cout << "created" << std::endl;
    _totalAmount += _amount;
}

Account::~Account( void )
{
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount<< ";";
    std::cout << "closed" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
    _nbDeposits++;
    _totalNbDeposits++;
    _totalAmount += deposit;
    
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
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount<< ";";
    std::cout << "deposits:"<< _nbDeposits << ";";
    std::cout << "withdrawals:"<< _nbWithdrawals << std::endl;
}
void	Account::_displayTimestamp( void ){}
Account::Account( void ){}

