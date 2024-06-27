# ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <string>
#include <iostream>

class Account
{
private:
    static int num_accounts;
    std::string name;
    double balance;

public:

    Account(std::string n = "None", double bal= 0): name(n), balance(bal)
    {++num_accounts;}

    void set_balance(double bal){balance = bal;}
    double get_balance(){return balance;}

    void set_name(std::string n);
    std::string get_name();

    bool deposit(double amount);
    bool withdraw(double amount);

    ~Account()
    {
        --num_accounts;
    }

    
    static int get_num_accounts();
};
#endif
