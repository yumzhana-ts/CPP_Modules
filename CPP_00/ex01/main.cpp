#include <iostream>
#include <string>
#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"


void displayMenu() {
    std::cout << "********************************************\n";
    std::cout << "*                                          *\n";
    std::cout << "*       📞 Welcome to Phonebook! 📞        *\n";
    std::cout << "*                                          *\n";
    std::cout << "*     What would you like to do?           *\n";
    std::cout << "*                                          *\n";
    std::cout << "*    ✨ Type 'ADD' to add a contact        *\n";
    std::cout << "*    🔍 Type 'SEARCH' to find a contact    *\n";
    std::cout << "*    ❌ Type 'EXIT' to close app           *\n";
    std::cout << "*                                          *\n";
    std::cout << "*******************************************\n";
}

int main() {
    displayMenu();
    PhoneBook phoneBook;
    std::string cmd;

    while (true) {
        std::cout << "\033[1;35m";
        std::cout << "Enter your command (ADD, SEARCH or EXIT): " << "\n";
        std::cin >> cmd;
        std::cout << "\033[0m";

        if (cmd == "ADD")
            phoneBook.set_contact();
        else if (cmd == "SEARCH")
            phoneBook.search_contacts();
        else if (cmd == "EXIT") 
        {
            std::cout << "❌ Exiting the phonebook. Goodbye!\n";
            return 0;
        } 
        else
        {
        std::cout << "\033[1;31m";
        std::cout << "❗ Oops! Looks like that command took a wrong turn at Albuquerque. Let's try something different, shall we 🤔😅?.\n";
        std::cout << "\033[0m";
        }
    }

    return 0;
}
