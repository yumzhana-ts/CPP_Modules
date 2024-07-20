/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:16 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/07/15 17:15:38 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.class.hpp"
#include "ClapTrap.class.hpp"

/****************************************************/
/*                    Constructor                   */
/****************************************************/

ScavTrap ::ScavTrap (std::string n): ClapTrap(n)
{
    hit_points = 100;
    energy_points = 50;
    attack_damage = 20;
    if (DEBUG){ std::cout << GREEN << "[ScavTrap] Default Constructor called" << RESET_COLOR << std::endl;}
}
//ScavTrap (std::string n = "Unkown"): name(n)

ScavTrap ::ScavTrap (const ScavTrap & src) : ClapTrap(src) 
{
    if (DEBUG){std::cout << GREEN << "[ScavTrap] Copy Constructor called" << RESET_COLOR << std::endl;}
    *this = src;
}

/****************************************************/
/*                    Destructor.                   */
/****************************************************/

ScavTrap ::~ScavTrap (void) 
{
    if (DEBUG){std::cout << GREEN << "[ScavTrap] Destructor called" << RESET_COLOR << std::endl;}
}

/****************************************************
*                    Overload                      *
****************************************************/


ScavTrap & ScavTrap ::operator=(const ScavTrap & rhs) 
{
    if (DEBUG){std::cout << GREEN << "[ScavTrap] Copy assignment operator called" << std::endl;}
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

void ScavTrap::attack(const std::string& target) 
{
    if (this->energy_points <= 0 || this->hit_points <= 0) 
    {
        std::cout << BG_WHITE << (this->energy_points <= 0 ? "You have exhausted all your energy." : "You have zero hit points remaining.") << RESET_COLOR << std::endl;
    } 
    else 
    {
        std::cout << BLUE << this->name << " ScavTrap attacks " << target << ", causing " << this->attack_damage << " points of damage!" << RESET_COLOR << std::endl;
        this->energy_points--;
    }
}

void ScavTrap::guard_gate()
{    
    if( this->energy_points <= 0 || this->hit_points <= 0 )
        std::cout << (this->energy_points <= 0 ? "You have exhausted all your energy." : "You have zero hit points remaining.") << RESET_COLOR << std::endl;
    else
        std::cout << BLUE << "ScavTrap " << this->name << " is now in Gate Keeper mode." << RESET_COLOR << std::endl;
};