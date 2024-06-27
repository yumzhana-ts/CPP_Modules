#ifndef _PHONEBOOK_
#define _PHONEBOOK_
#include <iostream>
#include <iomanip>
#include <string>
#include "Contact.class.hpp"

class PhoneBook
{
private:
    static const int size = 8;
    unsigned int	current_index;
    Contact contacts[size];
public:
    PhoneBook();
    ~PhoneBook();

    bool set_contact();
    void search_contacts();
    void display_contacts();
};

#endif
