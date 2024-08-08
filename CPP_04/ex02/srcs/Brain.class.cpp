/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:16 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/08/06 20:54:02 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.class.hpp"

/****************************************************/
/*                    Constructor                   */
/****************************************************/

Brain::Brain(void) 
{
    if (DEBUG){ std::cout << GREEN << "[Brain] Default Constructor called" << RESET_COLOR << std::endl;}
}
//Brain(std::string n = "Unkown"): name(n)

Brain::Brain(const Brain& src) {
    if (DEBUG) { std::cout << GREEN << "[Brain] Copy Constructor called" << RESET_COLOR << std::endl; }
    int i = 0;
    while(i < 100)
    {
        this->ideas[i] = src.ideas[i];
        i++;
    }
}

void Brain::print_address() const 
{
    std::cout << "Brain address: " << this << std::endl;
}

/****************************************************/
/*                    Destructor.                   */
/****************************************************/

Brain::~Brain(void) 
{
    if (DEBUG){std::cout << GREEN << "[Brain] Destructor called" << RESET_COLOR << std::endl;}
}

/****************************************************
*                    Overload                      *
****************************************************/


Brain& Brain::operator=(const Brain& rhs) 
{
    if (DEBUG){std::cout << GREEN << "[Brain] Copy assignment operator called" << std::endl;}
    if (this != &rhs) 
    {
        int i = 0;
        while(i < 100)
        {
            this->ideas[i] = rhs.ideas[i];
            i++;
        }
    }
    return (*this);
}

/****************************************************
*                 Memeber Functions                *
****************************************************/

void Brain::set_ideas(const std::string& ideas)
{
    int i = 0;
    while(i < 100)
    {
        this->ideas[i] = ideas;
        i++;
    }
}

void Brain::print_ideas() const
{
    int i = 0;
    while(i < 100)
    {
        std::cout << this->ideas[i] << " ";
        i++;
    }
    std::cout << std::endl;
}