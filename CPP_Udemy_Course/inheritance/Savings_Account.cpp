#include "Savings_Account.hpp"

Savings_Account::Savings_Account(): rate(3.0)
{
    std::cout << "Savings_Account created." << std::endl;
}

Savings_Account::~Savings_Account()
{
    std::cout << "Savings_Account destroyed." << std::endl;
}

void Savings_Account::deposit(double amount) {
    std::cout << "Savings Account deposit called with " << amount << std::endl;
}

void Savings_Account::withdraw(double amount) {
    std::cout << "Savings Account withdraw called with " << amount << std::endl;
}
