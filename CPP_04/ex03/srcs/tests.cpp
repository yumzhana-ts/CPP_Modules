/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:41:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/08/08 01:26:29 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.class.hpp"
#include "Character.class.hpp"
#include "AMateria.class.hpp"
#include "Ice.class.hpp"
#include "Cure.class.hpp"
#include "IMateriaSource.class.hpp"
#include "MateriaSource.class.hpp"

/* int main() 
{
    std::string name;
    std::cout << BLUE "Welcome to Eldoria, \nwhere the ancient Tower of Elements stands tall amidst lush forests, shimmering lakes, and jagged mountains. \n" << std::endl;
    IMateriaSource* src = new MateriaSource();
    std::cout << "One day, the Materia Source was activated, and it absorbed the ambient magical energy, glowing with newfound life." << RESET_COLOR << std::endl;
    src->learn_materia(new Ice());
    src->learn_materia(new Cure()); 
    src->print_materia();
    ICharacter* me = new Character("Lyra");
    std::cout << BLUE "A mage named "<< me->get_name() <<" emerges, her presence illuminated by the tower’s arcane glow." << RESET_COLOR << std::endl;
    ICharacter* enemy = new Character("Morgath");
    std::cout << BLUE "In the shadowy depths of Eldoria, a dark force stirs: an enemy named " << enemy->get_name() << ", the Shadow Sorcerer. \nNow, he commands the power of shadow and decay, using his malevolent abilities to spread fear and chaos across the realm." << RESET_COLOR << std::endl;
    int action;
    //int damage = 0;
    while(true)
    {
        std::cout << GREEN <<"Choose next action: create and equip Ice (1), create and equip Cure(2), unequip(3), use inventory(4)" << RESET_COLOR << std::endl;
        std::cout << GREEN <<"For test: create and equip wrong Materia (5), make a deep copy of charachter(6), learn invalid Materia(7), load list of Materia Source(8), exit(0)" << RESET_COLOR << std::endl;
        std::cin >> action;
        AMateria* tmp = NULL;
        ICharacter* me_two;
        switch (action) 
        {
            case 1:
                tmp = src->create_Materia("ice");
                me->equip(tmp);
                me->print_inventory();
                break;
            case 2:
                tmp = src->create_Materia("cure");
                me->equip(tmp);
                me->print_inventory();
                break;
            case 3:
                int item;
                std::cout << "Choose number of item to unequip" << std::endl;
                std::cin >> item;
                me->unequip(item);
                me->print_inventory();
                break;
            case 4:
                me->print_inventory();
                int item_use;
                std::cout << "Choose item to use" << std::endl;
                std::cin >> item_use;
                me->use(item_use, *enemy);
                break;
            case 5:
                tmp = src->create_Materia("waste");
                me->equip(tmp);
                me->print_inventory();
                break;
            case 6:
                me_two = new Character(*static_cast<Character*>(me));
                std::cout << "Hello, i am a clone of " << me->get_name() << ". My name is " << me_two->get_name() << std::endl;
                me_two->print_inventory();
                delete me_two;
                break;
            case 7:
                src->learn_materia(NULL);
                break;
            case 8:
                src->learn_materia(new Ice());
                src->learn_materia(new Cure());
                src->learn_materia(new Cure());
                src->print_materia();
                break;
            case 0: // Exit case
                std::cout << "Exiting the program." << std::endl;
                break;
            default:
                std::cout << "Invalid action!" << std::endl;
                break;
        }
        if (action == 0)
            break; // Exit the loop if action is 0
    }
    delete enemy; 
    delete me;
    delete src;
    return 0;
} */