#ifndef _HUMAN_A_
#define _HUMAN_A_
#include "Weapon.class.hpp"
#include <iostream>

class HumanA
{
private:
    std::string name;
    const Weapon& weapon;
public:
    HumanA(std::string n, const Weapon& w): name(n), weapon(w)
    {
        std::cout << "Agent Smith " << name << ": Entered the Matrix with '" << weapon.get_type() << "'" << std::endl;
    }
    ~HumanA(){}
    void set_name(std::string name){this->name = name;}
    std::string get_name(){return name;}
    void attack();
};

#endif