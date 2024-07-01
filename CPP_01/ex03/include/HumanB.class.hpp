#ifndef _HUMAN_B_
#define _HUMAN_B_
#include <Weapon.class.hpp>
#include <iostream>

class HumanB
{
private:
    std::string name;
    Weapon* weapon;
public:
    HumanB(std::string n = "unknown"): name(n), weapon(nullptr)
    {
        std::cout << "Agent Smith " << name << ": Got any leads on where I can snag a weapon?" << std::endl;
    }
    ~HumanB(){;}
    void set_name(std::string name){this->name = name;}
    std::string get_name(){return name;}
    void set_weapon(Weapon* w);
    void attack();
};

#endif