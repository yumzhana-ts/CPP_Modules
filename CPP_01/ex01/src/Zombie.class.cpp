#include "Zombie.class.hpp"

int Zombie::z_count = 0;

void Zombie::announce(void)
{
    std::cout << get_name() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}