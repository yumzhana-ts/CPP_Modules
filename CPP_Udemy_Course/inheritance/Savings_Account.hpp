#ifndef SAV_ACCOUNT
#define SAV_ACCOUNT
#include <iostream>
#include <string>
#include "Account.hpp"

class Savings_Account: public Account
{
public:
    double rate;
    Savings_Account();
    ~Savings_Account();
    void deposit(double amount);
    void withdraw(double amount);
};
#endif

