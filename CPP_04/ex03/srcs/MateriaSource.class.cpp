/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.class.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:16 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/08/08 01:11:39 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.class.hpp"

/****************************************************/
/*                    Constructor                   */
/****************************************************/

MateriaSource::MateriaSource(void) 
{
    if (DEBUG){ std::cout << GREEN << "[MateriaSource] Default Constructor called" << RESET_COLOR << std::endl;}
    int i = 0;
    while(i < 4)
    {
        this->materia_array[i] = NULL;
        i++;
    }
}
//MateriaSource(std::string n = "Unkown"): name(n)

MateriaSource::MateriaSource(const MateriaSource& src) 
{
    if (DEBUG){std::cout << GREEN << "[MateriaSource] Copy Constructor called" << RESET_COLOR << std::endl;}
    int i = 0;
    while(i < 4)
    {
        this->materia_array[i] = src.materia_array[i];
        i++;
    }
}

/****************************************************/
/*                    Destructor.                   */
/****************************************************/

MateriaSource::~MateriaSource(void) 
{
    if (DEBUG){std::cout << GREEN << "[MateriaSource] Destructor called" << RESET_COLOR << std::endl;}
    int i = 0;
    while(i < 4)
    {
        delete this->materia_array[i];
        i++;
    }
}

/****************************************************
*                    Overload                      *
****************************************************/


MateriaSource& MateriaSource::operator=(const MateriaSource& rhs) 
{
    if (DEBUG){std::cout << GREEN << "[MateriaSource] Copy assignment operator called" RESET_COLOR << std::endl;}
    if (this != &rhs) 
    {
        int i = 0;
        while(i < 4)
        {
            this->materia_array[i] = rhs.materia_array[i];
            i++;
        }
    }
    return (*this);
}

/****************************************************
*                 Memeber Functions                *
****************************************************/

void MateriaSource::learn_materia(AMateria* src)
{
    static int i = 0;
     if (src == NULL) {
        std::cout << RED << "Learning failed: Invalid materia." << RESET_COLOR << std::endl;
        return;
    } 
    if (i < 4)
    {
        materia_array[i] = src;
        std::cout << "Learning successful: "<< materia_array[i]->get_type() << " has been added to the 'Learned Items' list." << std::endl;
        i++;
    }
    else
    {
        delete src;
        std::cout << RED << "Learning failed: 'Learned Items' list is full." << RESET_COLOR << std::endl;
    }
}

void MateriaSource::print_materia()
{
    int i = 0;
    std::cout << "+---------------------------------------------------+" << std::endl;
    std::cout << "|              📜 **Learned Items** 🧙‍♂️             |" << std::endl;
    std::cout << "+---------------------------------------------------+" << std::endl;
    
    if (this->materia_array[0] == NULL)
        std::cout << RED << "🔴 List is empty" << RESET_COLOR << "               |" << std::endl;
    else 
    {
        while (i < 4 && this->materia_array[i] != NULL) {
            std::cout << " 🌟 Item " << i + 1 << ": " << this->materia_array[i]->get_type() << std::endl;
            i++;
        }
    }
    std::cout << "+---------------------------------------------------+" << std::endl;
    std::cout << "+---------------------------------------------------+" << std::endl;
}

AMateria* MateriaSource::create_Materia(std::string const & type)
{
    int i = 0;
    while (this->materia_array[i] != NULL)
    {
        if(this->materia_array[i]->get_type() == type)
        {
            std::cout << "Creation successful: Item " << type << " has been created from 'Learned Items' list." << std::endl;
            return(this->materia_array[i]->clone());
        }
        i++;
    }
    std::cout << RED << "Creation failed: Item name not found in the Learned List." << RESET_COLOR << std::endl;
    return(0);
}

