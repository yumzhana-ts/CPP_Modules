/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:16 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/08/08 01:27:00 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.class.hpp"

AMateria* Character::floor[3] = {NULL};
/****************************************************/
/*                    Constructor                   */
/****************************************************/

Character::Character(std::string n): name(n)
{
    if (DEBUG){ std::cout << GREEN << "[Character] Default Constructor called" << RESET_COLOR << std::endl;}
}
//Character(std::string n = "Unkown"): name(n)

Character::Character(const Character& src): name(src.name)
{
    if (DEBUG){std::cout << GREEN << "[Character] Copy Constructor called" << RESET_COLOR << std::endl;}
    int i = 0;
    while (i < 4) 
    {
        if (src.inventory[i])
            inventory[i] = src.inventory[i]->clone();
        else
            inventory[i] = NULL;
        ++i;
    }
}

/****************************************************/
/*                    Destructor.                   */
/****************************************************/

Character::~Character(void) 
{
    if (DEBUG){std::cout << GREEN << "[Character] Destructor called" << RESET_COLOR << std::endl;}
    int i = 0;
    while (i < 4) 
    {
        delete inventory[i];
        ++i;
    }
}

/****************************************************
*                    Overload                      *
****************************************************/


Character& Character::operator=(const Character& rhs) 
{
    if (DEBUG){std::cout << GREEN << "[Character] Copy assignment operator called" << RESET_COLOR << std::endl;}
    if (this != &rhs) {
        name = rhs.name;
        int i = 0;
        while (i < 4) 
        {
            delete inventory[i];  // Delete existing inventory
            if (rhs.inventory[i]) 
                inventory[i] = rhs.inventory[i]->clone();
            else
                inventory[i] = NULL;
            ++i;
        }
    }
    return *this;
}

/****************************************************
*                 Memeber Functions                *
****************************************************/

void Character::equip(AMateria* m)
{
    int i = 0;
    if (m == NULL) {
        std::cout << RED << "Equipment failed: Invalid materia." << RESET_COLOR << std::endl;
        return;
    }
    while(i < 4 && this->inventory[i] != NULL)
        i++;
    if (i < 4 && this->inventory[i] == NULL)
    {
        this->inventory[i] = m;
        std::cout << "Equipment successful: Item "<< inventory[i]->get_type() << " has been added to inventory." << std::endl;
    }
    else
        std::cout << RED << "Equipment failed: Inventory is full." << RESET_COLOR << std::endl;
}


void Character::unequip(int idx) 
{
    static int f = 0;

    if (idx < 0 || idx >= 4 || inventory[idx] == NULL) {
        std::cout << RED << "Unequipment failed: Inventory index is out of range or slot is empty." << RESET_COLOR << std::endl;
        return;
    }
    if (f < 3) 
    {
        this->floor[f] = this->inventory[idx]->clone();
        this->inventory[idx] = NULL;
        std::cout << "Unequipment successful: Inventory has been left on the floor." << std::endl;
        f++;
    } 
    else {
        std::cout << RED << "Unequipment failed: No space on the floor." << RESET_COLOR <<  std::endl;
        return;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= 4 || inventory[idx] == NULL) 
    {
        std::cout << RED << "Unequipment failed: Inventory index is out of range or slot is empty." << RESET_COLOR << std::endl;
        return;
    }
    if(this->inventory[idx] != NULL)
    {
        if (this->inventory[idx]->get_type() == "ice")
            std::cout << "* shoots an ice bolt at " << target.get_name() << " *" << std::endl;
        else
            std::cout << "* heals " << target.get_name() <<"'s wounds *"<< std::endl;
    }
    else
        std::cout << RED << "Usage failed: Inventory index is out of range or slot is empty." << RESET_COLOR << std::endl;
}

void Character::print_inventory() const
{
    std::cout << "+---------------------------------------------------+" << std::endl;
    std::cout << "|                📦 **Inventory** 📦                |" << std::endl;
    std::cout << "+---------------------------------------------------+" << std::endl;
    
    int i = 0;
    while (i < 4) {
        if (inventory[i] != NULL) {
            std::cout << "Slot " << i << ": " << inventory[i]->get_type() << std::endl;
        } else {
            std::cout << "Slot " << i << ": Empty" << std::endl;
        }
        ++i;
    }
    
    std::cout << "+---------------------------------------------------+" << std::endl;
    std::cout << "|                  🌟 Floor Items 🌟                |" << std::endl;
    std::cout << "+---------------------------------------------------+" << std::endl;
    
    i = 0;
    while (i < 3) {
        if (floor[i] != NULL) {
            std::cout << "Floor slot " << i << ": " << floor[i]->get_type() << std::endl;
        } else {
            std::cout << "Floor slot " << i << ": Empty" << std::endl;
        }
        ++i;
    }
    
    std::cout << "+---------------------------------------------------+" << std::endl;
    std::cout << "+---------------------------------------------------+" << std::endl;
}