#ifndef _CONTACT_
#define _CONTACT_
#include <iostream>
#include <string>

class Contact
{
private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;
public:
    //constructor & desctructor
    Contact(std::string first_name = "unknown", std::string last_name = "unknown", 
    std::string nickname = "unknown" ,std::string phone_number = "unknown", std::string secret = "unknown");
    ~Contact();

    //get & set
    void set_name(std::string first_name){this->first_name = first_name;}
    std::string get_name() const {return first_name;}

    void set_surname(std::string last_name){this->last_name = last_name;}
    std::string get_surname() const {return last_name;}

    void set_nickname(std::string nickname){this->nickname = nickname;}
    std::string get_nickname() const {return nickname;}

    void set_phone_number(std::string phone_number){this->phone_number = phone_number;}
    std::string get_phone_number() const {return phone_number;}

    void set_secret(std::string darkest_secret){this->darkest_secret = darkest_secret;}
    std::string get_secret() const {return darkest_secret;}
};

#endif
