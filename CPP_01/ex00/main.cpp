#include "Zombie.class.hpp"

int main()
{
    std::cout << "\033[1;31m";
    Zombie* zombiePtr = newZombie("Yuma");
    zombiePtr->announce();
    deleteZombie(zombiePtr);
    std::cout << "\033[0m";
}