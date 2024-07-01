#include "Weapon.class.hpp"
#include "HumanA.class.hpp"
#include "HumanB.class.hpp"


int main()
{
    {
        std::cout << "Entering to Matrix: Reference" << std::endl;
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.set_type("slingshot that shoots marshmallows");
        bob.attack();
    }
    {
        std::cout << std::endl << "Entering to Matrix: Pointer" << std::endl;
        Weapon club = Weapon("water gun that shoots bubbles");
        HumanB jim("Jim");
        jim.set_weapon(&club);
        jim.attack();
        club.set_type("slingshot that shoots marshmallows");
        jim.attack();
    }
}