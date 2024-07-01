#include "Zombie.class.hpp"



Zombie* zombieHorde(int N, std::string name)
{
    std::cout << "Voodoo: Zombie party is about to begin! " << N << " zombies invited!" << std::endl; 
    Zombie* apocalypse = new Zombie[N];
    int i = 0;
    while(i < N)
    {
        apocalypse[i].set_name(name);
        std::cout << "Voodoo: Zombie " << i << " has been named "<< name << std::endl;
        i++;
    }
    return(apocalypse);
}

void announcements(Zombie *apocalypse)
{
    int i = 0;
    while(i < apocalypse->z_count)
    {
        apocalypse[i].announce();
        i++;
    }
}