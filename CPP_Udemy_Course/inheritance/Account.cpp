#include "Account.hpp"

Account::~Account()
{
    std::cout << "Account destroyed." << std::endl;
}

Account::Account(std::string name, double balance) : name(name), balance(balance) 
{
    std::cout << "Account created." << std::endl;
}

void Account::deposit(double amount) {
    std::cout << "Account deposit called with " << amount  << std::endl;
}

void Account::withdraw(double amount) {
    std::cout << "Account withdraw called with " << amount << std::endl;
}

double Account::get_balance() const
{
    return balance;
}
