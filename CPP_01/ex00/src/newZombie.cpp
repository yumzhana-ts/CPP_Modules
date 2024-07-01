#include "Zombie.class.hpp"

//return a pointer to an instance of the Zombie class, not the class itself
Zombie* newZombie(std::string name)
{
    std::cout << "Voodoo: Creating " << name << " on heap"<< std::endl;
    return new Zombie(name);
}

void deleteZombie(Zombie* zombie) 
{
    std::cout << "Voodoo: Killing " << zombie->get_name() << " on heap. Rest in peace! "<< std::endl;
    delete zombie;
}