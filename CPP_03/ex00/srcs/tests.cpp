/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:41:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/07/13 02:37:34 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.class.hpp"

int main() 
{
    std::string name;
    std::cout << "Name your character:";
    std::cin >> name;
    ClapTrap obj1(name);
    std::cout << BLUE << "ClapTrap " << obj1.get_name() << " the quirky robot 🤖, set off on his ship, The Wanderer 🚢, to explore new worlds." << std::endl;
    std::cout <<"He found a mysterious island, but as night fell, strange creatures appeared—twisted animals with shiny scales," << std::endl;
    std::cout << "spiky fur, and glowing eyes, all ready to fight." << RESET_COLOR << std::endl;
    obj1.print_state();
    int action;
    int damage = 0;
    while(true)
    {
        if (obj1.get_energy_points() <= 0 || obj1.get_hit_points() <= 0)
        {
            std::cout << BLUE << "Rushed back to his ship " << obj1.get_name() <<" left the island behind to recharge for his next adventure." << RESET_COLOR << std::endl;
            return (false);
        }
        std::cout << "Choose next action: attack (1), take damage(2), be repaired (3)" << std::endl;
        std::cin >> action;
        int creature;
        std::string target;
        switch (action) 
        {
            case 1:
                std::cout << obj1.get_name() << " had to choose his attack: he could aim for the closest(1) creature with sharp claws or focus on a larger(2) beast with glowing eyes that seemed to lead the pack."  << std::endl;
                std::cin >> creature;
                if (creature == 1 || creature == 2)
                {
                    if(creature == 1)
                    {
                        damage = 1;
                        target = "closest creature with sharp claws";
                    }
                    else
                    {
                        damage = 3;
                        target = "larger beast with glowing eyes";
                    }
                    obj1.attack(target);
                    obj1.print_state();
                    break;
                }
                else
                    std::cout << "Please enter valid target" << std::endl;
                    break;
            case 2:;
                obj1.take_damage(damage);
                obj1.print_state();
                break;
            case 3:
                obj1.be_repaired(damage);
                obj1.print_state();
                break;
            default:
                std::cout << "Invalid action!" << std::endl;
                break;
        }
    }
}