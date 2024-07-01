#include <iostream>

int main()
{
    std::string s = "HI THIS IS BRAIN";
    std::string* stringPTR = &s;
    std::string& stringREF = s;

    std::cout << "Memory address of the string variable: " << &s << std::endl; 
    std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
    std::cout << "Memory address held by stringREF: " << &stringREF << std::endl; 

    std::cout << "The value of the string variable: " << s << std::endl;
    std::cout << "The value pointed to by stringPTR: " << *stringPTR << std::endl; 
    std::cout << "The value pointed to by stringREF: " << stringREF << std::endl; 
}
