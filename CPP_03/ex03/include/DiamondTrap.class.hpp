/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.class.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/08/07 21:52:41 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_CLASS_H
#define DIAMONDTRAP_CLASS_H

#include "FragTrap.class.hpp"
#include "ScavTrap.class.hpp"
#include <iostream>

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
    std::string name;
public:
    DiamondTrap (std::string n);
    ~DiamondTrap (void);
    DiamondTrap (const DiamondTrap & other);
    DiamondTrap & operator=(const DiamondTrap & other);

    void attack(const std::string& target);
    void who_am_i();


    int get_hit_points(void) const {return (this->hit_points);}
    int get_energy_points(void) const {return (this->energy_points);}
    int get_attack_damage(void) const {return (this->attack_damage);}
};


#define DEBUG 0
// Define ANSI escape sequences for colors
#define RESET_COLOR "\033[0m"
#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define BLUE "\033[0;34m"
#define WHITE "\033[0;37m"
#define BOLD_BLACK "\033[1;30m"
#define BG_WHITE "\033[0;47m"
#endif