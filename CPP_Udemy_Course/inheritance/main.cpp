#include <iostream> //input and output library
#include <vector>
#include "Account.hpp"
#include "Savings_Account.hpp"

int main()
{
    Account account("Yuma", 200);

    Savings_Account sav_acc;
    sav_acc.deposit(2000.0);               
    sav_acc.withdraw(500.0);
    std::cout << sav_acc.get_balance() << std::endl;

    std::cout << "Account:" << account.get_name() << " Balance:" << account.get_balance() << std::endl;
    std::cout << "Saving account:" << sav_acc.get_name() << " Balance:" << sav_acc.get_balance() << std::endl;
    
}
