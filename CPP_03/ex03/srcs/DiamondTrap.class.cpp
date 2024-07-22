/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.class.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/07/21 02:27:23 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.class.hpp"
#include "FragTrap.class.hpp"
#include "ScavTrap.class.hpp"
#include "ClapTrap.class.hpp"

/****************************************************/
/*                    Constructor                   */
/****************************************************/

DiamondTrap ::DiamondTrap (std::string n): ClapTrap(n + "_clap_name"), FragTrap(n), ScavTrap(n), name(name)
{
    hit_points = FragTrap::hit_points;
    energy_points = ScavTrap::energy_points;
    attack_damage = FragTrap::attack_damage;
    if (DEBUG){ std::cout << GREEN << "[DiamondTrap] Default Constructor called" << RESET_COLOR << std::endl;}
}

DiamondTrap ::DiamondTrap (const DiamondTrap & src) : ClapTrap(src), FragTrap(src), ScavTrap(src)
{
    if (DEBUG){std::cout << GREEN << "[DiamondTrap] Copy Constructor called" << RESET_COLOR << std::endl;}
    *this = src;
}

/****************************************************/
/*                    Destructor.                   */
/****************************************************/

DiamondTrap ::~DiamondTrap (void) 
{
    if (DEBUG){std::cout << GREEN << "[DiamondTrap] Destructor called" << RESET_COLOR << std::endl;}
}

/****************************************************
*                    Overload                      *
****************************************************/


DiamondTrap & DiamondTrap ::operator=(const DiamondTrap & rhs) 
{
    if (DEBUG){std::cout << GREEN << "[DiamondTrap] Copy assignment operator called" << std::endl;}
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

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}