#ifndef _ZOMBIE
#define _ZOMBIE
#include <iostream>

class Zombie
{
private:
    std::string name;
public:
    static int z_count;
    Zombie(std::string n = "Unkown"): name(n)
    {
        std::cout << "Voodoo: " << get_name() << " zombie " << z_count << " has woken up on heap! 🧟😄 " << std::endl;
        z_count++;
    }
    ~Zombie()
    {
        z_count--;
        std::cout << "Officer Smith: Another " << get_name() <<  " zombie " << z_count << " neutralized!🧟💀" << std::endl;
    };

    void set_name(std::string name){this->name = name;}
    std::string get_name() const {return name;}
    void announce(void);
};

void randomChump(std::string name);
Zombie* zombieHorde(int N, std::string name);
void announcements(Zombie *apocalypse);

#endif