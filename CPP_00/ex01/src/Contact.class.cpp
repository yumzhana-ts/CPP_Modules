#include "Contact.class.hpp"

//constructor & desctructor
Contact::Contact(std::string first, std::string last, std::string nick,
std::string phone, std::string sec) 
: first_name(first), last_name(last), nickname(nick), phone_number(phone), darkest_secret(sec) {}
Contact::~Contact(){}
