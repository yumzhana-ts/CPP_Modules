#include "Zombie.class.hpp"

int main()
{
    std::cout << "\033[1;31m";
    std::cout << "*********************************************************\n";
    std::cout << "*  ...    Zombie party has been started on heap  ...    *\n";
    std::cout << "*********************************************************\n";
    std::cout << "\033[0m";
    Zombie* party = zombieHorde(20, "Yuma");
    std::cout << "Officer Smith: Investigating the zombie's late-night howling. Sounds like the undead are having a party!" << std::endl;
    announcements(party);
    std::cout << "Officer Smith: Protecting the living by sending zombies back to the grave." << std::endl;
    delete [] party;
    std::cout << "\033[1;31m";
    std::cout << "*********************************************************\n";
    std::cout << "*            ...  End of zombie party.  ...             *\n";
    std::cout << "*********************************************************\n";
    std::cout << "\033[0m";
}