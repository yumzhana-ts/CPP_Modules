#include <iostream> //input and output library

int main()
{
    int cent;
    std::cout << "Enter an amount in cents: " << std::endl;
    std::cin >> cent;
    std::cout << "You can provide the change as follows: " << std::endl;
    int dollar = cent/100;
    cent %= 100;
    std::cout << "dollars: " << dollar << std::endl;
    int quarter = cent/25;
    cent %= 25;
    std::cout << "quarter: " << quarter << std::endl;
    int dime = cent/10;
    cent %= 10;
    std::cout << "dime: " << dime << std::endl;
    int nickel = cent/5;
    cent %= 5;
    std::cout << "nickel: " << nickel << std::endl;
    int penny = cent/1;
    cent %= 1;
    std::cout << "penny: " << penny << std::endl;
}
