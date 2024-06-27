#include "Account.hpp"

int Account::_totalAmount = 0;

int	Account::getTotalAmount( void )
{
    return _totalAmount;
}

void Account::setTotalAmount(int amount)
{
    _totalAmount += amount; 
}


