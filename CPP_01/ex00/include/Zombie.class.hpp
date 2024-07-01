#ifndef _ZOMBIE
#define _ZOMBIE
#include <iostream>

class Zombie
{
private:
    std::string name;
public:
    Zombie(std::string n = "unkown"): name(n)
    {
        std::cout << get_name() << " has woken up! 🧟" << std::endl;
    }
    ~Zombie()
    {
        std::cout << get_name() << " is dead 🧟💀" << std::endl;
    };

    void set_name(std::string name){this->name = name;}
    std::string get_name() const {return name;}
    void announce(void);
};

void randomChump(std::string name);
Zombie* newZombie(std::string name);
void deleteZombie(Zombie* zombie);

#endif