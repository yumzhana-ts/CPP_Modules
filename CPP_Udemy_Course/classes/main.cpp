#include <iostream>
#include <string>
#include <typeinfo>
#include "account.hpp"
using namespace std;

void display_active_accounts()
{
    cout << "Active accounts" << Account::get_num_accounts() << endl;
}

int main()
{
    Account frank_account;
    frank_account.set_name("Frank's account");
    frank_account.set_balance(1000.0);
    display_active_accounts();
    {
        Account test;
        display_active_accounts();
    }
    display_active_accounts();
    if (frank_account.deposit(200.0))
        cout << "Deposit OK" << endl;
    else 
        cout << "Deposit Not Allowed" << endl;

    if (frank_account.withdraw(500.0))
        cout << "Withdrawal OK" << endl;
    else 
        cout << "Withdrawal Not Allowed" << endl;
    
    if (frank_account.withdraw(1500.0))
        cout << "Withdrawal OK" << endl;
    else 
        cout << "Not sufficient funds" << endl;

    return (0);
}
