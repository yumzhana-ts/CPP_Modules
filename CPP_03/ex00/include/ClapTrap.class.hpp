/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/08/07 21:52:41 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_CLASS_H
#define CLAPTRAP_CLASS_H

#include <iostream>

class ClapTrap
{
private:
    std::string name;
    int hit_points;
    int energy_points;
    int attack_damage;
public:
    ClapTrap(std::string n);
    ~ClapTrap(void);
    ClapTrap(const ClapTrap& other);
    ClapTrap& operator=(const ClapTrap& other);

    //get&set
    std::string get_name(void) const {return (this->name);}
    void set_name(std::string name){this->name = name;}
    int get_hit_points(void) const {return (this->hit_points);}
    void set_hit_points(int hit_points){this->hit_points = hit_points;}
    int get_energy_points(void) const {return (this->energy_points);}
    void set_energy_points(int energy_points){this->energy_points = energy_points;}
    int get_attack_damage(void) const {return (this->attack_damage);}
    void set_attack_damage(int attack_damage){this->attack_damage = attack_damage;}
    

    void attack(const std::string& target);
    void take_damage(unsigned int amount);
    void be_repaired(unsigned int amount);
    void print_state();
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