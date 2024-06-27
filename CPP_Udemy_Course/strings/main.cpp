#include <iostream> //input and output library
#include <string>

int main()
{
    //task 1
    std::string unformatted_full_name = "StephenHawking";
    std::string first_name = unformatted_full_name.substr(0,7);
    std::string last_name = unformatted_full_name.substr(7,14);
    std::string formatted_full_name = first_name + last_name;
    formatted_full_name.insert(7, " ");
    std::cout << unformatted_full_name << std::endl;
    std::cout << first_name << std::endl;
    std::cout << last_name << std::endl;
    std::cout << formatted_full_name << std::endl;

    //task 2
    std::string journal_entry_1 = "Isaac Newton";
    std::string journal_entry_2 = "Leibniz";

    journal_entry_1.erase(0,6);
    std::cout << journal_entry_1 << std::endl;
    if (journal_entry_1 > journal_entry_2)
        journal_entry_1.swap(journal_entry_2);

    //use cifer
    std::string alphabet = "abcdefghiklmnopqrstvxyzABCDEFGHIKLMNOPQRSTVXYZ";
    std::string key = "ABCDEFGHIKLMNOPQRSTVXYZabcdefghiklmnopqrstvxyz";

    std::string read;
    std::cout << "Enter your message: ";
    getline(std::cin, read);
    std::cout << read << std::endl;
    for(int i = 0; i < (int)read.length(); i++)
    {
        if(isalpha(read[i]))
        {
            int pos = alphabet.find(read[i]);
            read[i] = key[pos];
        }
        std::cout << read[i];
    }
    std::cout << std::endl;

    //pyramid
    std::cout << "Enter letters: ";
    std::string let;
    std::cin >> let;
    for(int i = 0; i < (int)let.length(); i++)
    {
        for(int d = 0; d < ((int)let.length() - i - 1); d++)
            std::cout << "*";
        std::string set = let.substr(0,i+1);
        std::cout << set;
        for(int d = (set.length() - 2);d >= 0;d--)
            std::cout << set[d];
        for(int d = 0; d < ((int)let.length() - i - 1); d++)
            std::cout << "*";
        std::cout << std::endl;
    }
}
