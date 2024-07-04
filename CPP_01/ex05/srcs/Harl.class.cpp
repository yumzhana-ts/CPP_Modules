#include "Harl.class.hpp"

void Harl::complain(std::string level) 
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*ptr[5])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error, &Harl::other};

    int i = 0;
    while(i < 4 && levels[i] != level)
        i++;
    (this->*ptr[i])();
}

void Harl::debug()
{
    std::cout << "DEBUG: I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}
void Harl::info( void )
{
    std::cout << "INFO: I cannot believe adding extra bacon costs more money. You didnt put enough bacon in my burger! If you did, I wouldnt be asking for more!" << std::endl;
}
void Harl::warning( void )
{
    std::cout << "WARNING: I think I deserve to have some extra bacon for free. Ive been coming for years whereas you started working here since last month." << std::endl;
}
void Harl::error( void )
{
    std::cout << "ERROR: This is unacceptable! I want to speak to the manager now." << std::endl;
}
void Harl::other( void )
{
    std::cout << "COMMAND NOT FOUND: No burger is found on the menu." << std::endl;
}