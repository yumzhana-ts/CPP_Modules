#include "HumanA.class.hpp"

void HumanA::attack()
{
    std::cout << name << " attacks with their '"<< weapon.get_type() <<"'" <<std::endl;
}