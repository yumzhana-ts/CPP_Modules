/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:16 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/07/15 19:06:18 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.class.hpp"
#include "ClapTrap.class.hpp"

/****************************************************/
/*                    Constructor                   */
/****************************************************/

FragTrap ::FragTrap (std::string n): ClapTrap(n)
{
    hit_points = 100;
    energy_points = 100;
    attack_damage = 30;
    if (DEBUG){ std::cout << GREEN << "[FragTrap] Default Constructor called" << RESET_COLOR << std::endl;}
}
//FragTrap (std::string n = "Unkown"): name(n)

FragTrap ::FragTrap (const FragTrap & src) : ClapTrap(src) 
{
    if (DEBUG){std::cout << GREEN << "[FragTrap] Copy Constructor called" << RESET_COLOR << std::endl;}
    *this = src;
}

/****************************************************/
/*                    Destructor.                   */
/****************************************************/

FragTrap ::~FragTrap (void) 
{
    if (DEBUG){std::cout << GREEN << "[FragTrap] Destructor called" << RESET_COLOR << std::endl;}
}

/****************************************************
*                    Overload                      *
****************************************************/


FragTrap & FragTrap ::operator=(const FragTrap & rhs) 
{
    if (DEBUG){std::cout << GREEN << "[FragTrap] Copy assignment operator called" << std::endl;}
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

void FragTrap::high_fives_guys() {
    std::cout << BLUE << "FragTrap " << this->name << " requests a positive high five!" << RESET_COLOR << std::endl;
}