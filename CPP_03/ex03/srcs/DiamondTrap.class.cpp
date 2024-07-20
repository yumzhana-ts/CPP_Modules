/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.class.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/07/16 14:34:36 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.class.hpp"
#include "DiamondTrap.class.hpp"
#include "ClapTrap.class.hpp"

/****************************************************/
/*                    Constructor                   */
/****************************************************/

DiamondTrap ::DiamondTrap (std::string n): ClapTrap(n)
{
    hit_points = 100;
    energy_points = 100;
    attack_damage = 30;
    if (DEBUG){ std::cout << GREEN << "[DiamondTrap] Default Constructor called" << RESET_COLOR << std::endl;}
}
//DiamondTrap (std::string n = "Unkown"): name(n)

DiamondTrap ::DiamondTrap (const DiamondTrap & src) : ClapTrap(src) 
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

void DiamondTrap::high_fives_guys() {
    std::cout << BLUE << "DiamondTrap " << this->name << " requests a positive high five!" << RESET_COLOR << std::endl;
}