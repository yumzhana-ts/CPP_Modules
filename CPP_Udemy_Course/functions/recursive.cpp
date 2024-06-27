#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int sum_of_digits(int n) 
{
    if(n == 0)
        return 0;
    return(sum_of_digits (n/10) + (n % 10));
}

