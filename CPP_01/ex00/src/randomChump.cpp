#include "Zombie.class.hpp"

void randomChump(std::string name)
{
    std::cout << name << " zombie is born on stack for short life ⭐️"<< std::endl;
    Zombie zombie(name);
    zombie.announce();
}