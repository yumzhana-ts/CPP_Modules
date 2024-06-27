#include "account.hpp"

int Account::num_accounts = 0;


void Account::set_name(std::string n)
{
    name = n;
}

std::string Account::get_name()
{
    return name;
}

bool Account::deposit(double amount)
{
    balance += amount;
    return true;
}

bool Account::withdraw(double amount)
{
    if (balance-amount >= 0)
    {
        balance -= amount;
        return (true);
    }
    else
        return (false);
}

int Account::get_num_accounts()
{
    return num_accounts;
}
