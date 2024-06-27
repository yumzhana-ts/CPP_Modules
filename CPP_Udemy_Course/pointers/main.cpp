#include <iostream> //input and output library
#include <vector>
#include <string>
#include <array>

std::string reverse_string(const std::string &str) 
{
    std::string reversed;
    int size = str.length();
    int i = 0;
    while(size > i)
    {
        reversed.push_back(str.at(size -1));
        size--;
    }
    return reversed;
}

int main()
{
    std::cout << reverse_string("Hello!") << std:: endl;
    int scores[] = {100,95,89};
    

    std::cout << scores << std:: endl;
    std::cout << *scores << std::endl;

    int *score_ptr = scores;
    std::cout << score_ptr << std::endl;
    std::cout << *score_ptr << std::endl;

    int *ptr;

    ptr = new int;
    *ptr = 100;
    std::cout << *ptr << std::endl;
    delete ptr;

    while(*score_ptr != 89)
        std::cout << *score_ptr++ << std::endl;
    
    int arr_1[] = {100,95,89};
    //int arr_2[] = {100,95,89};

    int length = sizeof(arr_1) / sizeof(arr_1[0]);
    for(int i = 0; i < length; i++)
    {
        std::cout << arr_1[i] <<" ";
    }
    std::cout << std::endl;
    for(int i = 0; i < length; i++)
    {
        std::cout << arr_1[i] << " ";
    }
    
}
