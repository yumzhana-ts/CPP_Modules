#ifndef _WEAPON_
#define _WEAPON_
#include <iostream>

class Weapon
{
private:
    std::string type;
public:
    Weapon(std::string t): type(t)
    {
        std::cout << "New weapons '" << type << "' have just arrived at the store" << std::endl;
    }
    ~Weapon(){}
    std::string get_type () const {return type;}
    void set_type(std::string type)
    {
        this->type = type;
        std::cout << "Weapon is changed to '" << type << "'" << std::endl;
    }
};

#endif