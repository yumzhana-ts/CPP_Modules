#include <iostream>
#include <string>
#include <vector>

class Contact
{
private:
    std::string name;
    int phone;

public:
    // Constructor
    Contact(std::string name, int phone) : name(name), phone(phone) {}

    // Method to display contact details
    void display() const
    {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Phone: " << phone << std::endl;
    }
};

class PhoneBook
{
private:
    std::vector<Contact> contacts;

public:
    // Method to add a contact to the phone book
    void addContact(const Contact& contact)
    {
        contacts.push_back(contact);
    }
};

int main()
{
    // Create a PhoneBook object
    PhoneBook phoneBook;

    // Create a Contact object
    Contact contact("Yuma", 608473761);

    // Add the contact to the phone book
    phoneBook.addContact(contact);

    contact.display();

    return 0;
}