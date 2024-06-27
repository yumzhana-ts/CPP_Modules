#include "PhoneBook.class.hpp"
#include <iomanip>
#include <cstdlib> // Required for std::atoi

//constructor & desctructor
PhoneBook::PhoneBook() : current_index(0) 
{}

PhoneBook::~PhoneBook()
{}

bool PhoneBook::set_contact()
{
    std::cout << "**********************************************\n";
    std::cout << "*  📞       Add a New Contact         📞     *\n";
    std::cout << "**********************************************\n";

    std::string name, surname, nickname, phone, darkest_secret;
    std::cout << "Name:";
    std::getline(std::cin, name);
    std::cout << "Surname:";
    std::getline(std::cin, surname);
    std::cout << "Nickname:";
    std::getline(std::cin, nickname);
    std::cout << "Phone:";
    std::getline(std::cin, phone);
    std::cout << "Darkest secret:";
    std::getline(std::cin, darkest_secret);

    contacts[(current_index+size) % size] = Contact(name, surname, nickname, phone, darkest_secret);
    current_index++;
    std::cout << "**********************************************\n";
    std::cout << "*  📞 Contact Added Successfully!      📞    *\n";
    std::cout << "**********************************************\n";
    return true;
}

void PhoneBook::display_contacts()
{
    std::cout << "📇 ************  CONTACT LIST  ************ 📇\n";
    std::cout << " -------------------------------------------\n";   
    std::cout << "|";
    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First name" << "|";
    std::cout << std::setw(10) << "Last name" << "|";
    std::cout << std::setw(10) << "Nickname" << "|" << std::endl;
    std::cout << " -------------------------------------------\n"; 

    int i = 0;
    while(i < size)
    {
        std::string n;
        std::cout << "|";
        std::cout << std::setw(10) << i + 1 << "|";
        std::cout << std::setw(10) << (std::string(contacts[i].get_name()).length() > 10 ? std::string(contacts[i].get_name(), 0, 9) + "." : contacts[i].get_name()) << "|";
        std::cout << std::setw(10) << (std::string(contacts[i].get_surname()).length() > 10 ? std::string(contacts[i].get_surname(), 0, 9) + "." : contacts[i].get_surname()) << "|";
        std::cout << std::setw(10) << (std::string(contacts[i].get_nickname()).length() > 10 ? std::string(contacts[i].get_nickname(), 0, 9) + "." : contacts[i].get_nickname()) << "|" << std::endl;
        i++;
    }
    std::cout << "📇 **************************************** 📇\n";
}



void PhoneBook::search_contacts()
{
    display_contacts();
    
    std::string contact;
    std::cout << "Please enter the contact number to display:🔍" << std::endl;
    std::getline(std::cin, contact);
    int n = std::atoi(contact.c_str());

    if (n > 0 && n <= size)
    {
    std::cout << "**********************************************\n";
    std::cout << "*       📞 Contact information 📞            *\n";
    std::cout << "**********************************************\n";
    std::cout << "First name: " << contacts[n-1].get_name() << std::endl;
    std::cout << "Last name: " << contacts[n-1].get_surname() << std::endl;
    std::cout << "Nickname: " << contacts[n-1].get_nickname() << std::endl;
    std::cout << "Phone number: " << contacts[n-1].get_phone_number() << std::endl;
    std::cout << "Darkest secret: " << contacts[n-1].get_secret() << std::endl;
    std::cout << "**********************************************\n";
 
    }
    else
    {
        std::cout << "\033[1;31m";
        std::cout << "Whoops! It seems you've ventured into the land of imaginary contacts. 🧙‍♂️✨\n";
        std::cout << "Maybe this index is hiding with Bigfoot or lost in the Bermuda Triangle. Keep searching! 🔍🌊\n";
        std::cout << "\033[0m";
        } 
}

