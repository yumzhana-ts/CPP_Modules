#include "HumanB.class.hpp"
#include "Weapon.class.hpp"

void HumanB::attack()
{
    std::cout << name << " attacks with their '"<< weapon->get_type() <<"'" <<std::endl;
}

void HumanB::set_weapon(Weapon* w)
{
    weapon = w;
    std::cout << name << " just hit the store and got himself a weapon "<< std::endl;
}


