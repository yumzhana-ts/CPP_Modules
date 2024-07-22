/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:41:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/07/15 19:16:41 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.class.hpp"
#include "ScavTrap.class.hpp"

int main() 
{
    int action = 0;
    int damage_to_take = 0;
    int player = 0;
    int total_damage = 0;
    ClapTrap* obj1 = NULL;
    std::cout << "Choose player: ClapTrap(1), ScavTrap(2)" << std::endl;
    std::cin >> player;
    if (player == 1 || player == 2)
    {
        if(player == 1)
        {
            std::string Clap_name;
            std::cout << "Name your character of Claptrap:";
            std::cin >> Clap_name;
            obj1 = new ClapTrap(Clap_name);
        }
        else
        {
            std::string Scav_name;
            std::cout << "Name your character of Scavtrap:";
            std::cin >> Scav_name;
            obj1 = new ScavTrap(Scav_name);
        }
    }
        else
        {
            std::cout << "Choose correct charachter";
            delete obj1;
        }
    std::cout << BLUE << "ClapTrap and Scavtrap, while traveling through the galaxy aboard their spacecraft," << std::endl;
    std::cout << "suddenly came under attack from a sleek enemy ship. " << RESET_COLOR << std::endl;
    obj1->print_state();
    while(true)
    {
        std::cout << "Choose next action: attack (1), take damage(2), be repaired (3)" << std::endl;
        if (player == 2)
            std::cout << "additional option for ScavTrap: guard gate(4) " << std::endl;
        std::cin >> action;
        int creature;
        std::string target;
        if (obj1->get_energy_points() <= 0 || obj1->get_hit_points() <= 0 )
        {
            std::cout << BLUE << "After narrowly escaping the enemy ship, Craptrap and Scavtrap hurried to make repairs and recharge aboard the Rusty Roamer," << std::endl;
            std::cout << "leaving their attackers behind and preparing for their next adventure." << RESET_COLOR << std::endl;
            delete obj1;
            return (false);
        }
        if (total_damage > 100)
        {
            std::cout << BLUE << "After an intense battle with the enemy ship, Craptrap and Scavtrap made their escape aboard the Rusty Roamer," << std::endl;
            std::cout << "ready to continue their journey and seek out new adventures among the stars." << RESET_COLOR << std::endl;
            delete obj1;
            return (false);
        }
        switch (action) 
        {
            case 1:
                std::cout << obj1->get_name() << " had to choose his attack: he could aim for the closest (1) alien with razor-sharp claws and armored scales or focus on a larger (2) alien with glowing eyes and tentacles that seemed to command the others."  << std::endl;
                std::cin >> creature;
                if (creature == 1 || creature == 2)
                {
                    if(creature == 1)
                    {
                        damage_to_take = 20;
                        target = "closest alien with razor-sharp claws";
                    }
                    else
                    {
                        damage_to_take = 30;
                        target = "alien with glowing eyes and tentacles";
                    }
                    obj1->attack(target);
                    obj1->print_state();
                    total_damage += obj1->get_attack_damage();
                    break;
                }
                else
                {
                    std::cout << "Please enter valid target" << std::endl;
                    break;
                }
            case 2:;
                obj1->take_damage(damage_to_take);
                obj1->print_state();
                break;
            case 3:
                obj1->be_repaired(damage_to_take);
                obj1->print_state();
                break;
            case 4:
                if (player == 2)
                {
                    ScavTrap* scavTrapPtr = (ScavTrap*)(obj1);
                    scavTrapPtr->guard_gate();
                    break;
                }
            default:
                std::cout << "Invalid action!" << std::endl;
                break;
        }
    }
}