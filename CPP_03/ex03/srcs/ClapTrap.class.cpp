/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:16 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/07/29 16:51:06 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.class.hpp"

/****************************************************/
/*                    Constructor                   */
/****************************************************/

ClapTrap::ClapTrap(std::string n): name(n), hit_points(10), energy_points(10), attack_damage(0) 
{
    if (DEBUG){ std::cout << GREEN << "[ClapTrap] Default Constructor called" << RESET_COLOR << std::endl;}
}

ClapTrap::ClapTrap(const ClapTrap& src) 
{
    if (DEBUG){std::cout << GREEN << "[ClapTrap] Copy Constructor called" << RESET_COLOR << std::endl;}
    *this = src;
}

/****************************************************/
/*                    Destructor.                   */
/****************************************************/

ClapTrap::~ClapTrap(void) 
{
    if (DEBUG){std::cout << GREEN << "[ClapTrap] Destructor called" << RESET_COLOR << std::endl;}
}

/****************************************************
*                    Overload                      *
****************************************************/


ClapTrap& ClapTrap::operator=(const ClapTrap& rhs) 
{
    if (DEBUG){std::cout << GREEN << "[ClapTrap] Copy assignment operator called" << RESET_COLOR <<  std::endl;}
    if (this != &rhs)
    {
        this->name = rhs.name;
        this->hit_points = rhs.hit_points;
        this->energy_points = rhs.energy_points;
        this->attack_damage = rhs.attack_damage;
    }
    return (*this);
}

/****************************************************
*                 Memeber Functions                *
****************************************************/


void ClapTrap::attack(const std::string& target)
{
    if( this->energy_points <= 0 || this->hit_points <= 0 )
        std::cout <<  BG_WHITE  << (this->energy_points <= 0 ? "You have exhausted all your energy." : "You have zero hit points remaining.") << RESET_COLOR << std::endl;
    else
    {
        std::cout << BLUE << this-> name << " ClapTrap attacks " << target << ", causing " << this->attack_damage << " points of damage!" << RESET_COLOR << std::endl;
        this->energy_points--;
    }
}
void ClapTrap::take_damage(unsigned int amount)
{
    if( this->energy_points <= 0 || this->hit_points <= 0 )
        std::cout <<  BG_WHITE  << (this->energy_points <= 0 ? "You have exhausted all your energy." : "You have zero hit points remaining.") << RESET_COLOR << std::endl;
    else
    {
        std::cout << BLUE << "The creatures roared in anger, their glowing eyes blazing as they prepared to strike back. ";
        std::cout << this->name << " Trap was attacked, taking " << amount << " points of damage and left breathless by the impact." RESET_COLOR << std::endl;
        this->hit_points -= amount;
        if (this->hit_points < 0)
            this->hit_points = 0;
    }
}
void ClapTrap::be_repaired(unsigned int amount)
{    
    if( this->energy_points <= 0 || this->hit_points <= 0 )
        
        std::cout << (this->energy_points <= 0 ? "You have exhausted all your energy." : "You have zero hit points remaining.") << RESET_COLOR << std::endl;
    else
    {
        this->energy_points--;
        this->hit_points += amount;
/*         if (this->hit_points > 10)
            this->hit_points = 10; */
        std::cout << BLUE << "Trap sensors activated.";
        std::cout << this->name << " restores " << amount << " health, feeling a surge of energy." RESET_COLOR << std::endl;
    }
};


void ClapTrap::print_state()
{
    std::cout << RED << "System status: "<< this->hit_points << " hit points and "
    << this->energy_points << " energy points" << RESET_COLOR << std::endl;
};



