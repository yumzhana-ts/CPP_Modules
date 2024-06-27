#ifndef ACCOUNT
#define ACCOUNT
#include <iostream>
#include <string>

class Account 
{
protected:
    std::string name;
    double balance;
public:
    ~Account();
    Account(std::string name = "Unamed Account", double balance = 0.0);
    void deposit(double amount);
    void withdraw(double amount);
    double get_balance() const;
    std::string get_name(){return(name);}
};
#endif
