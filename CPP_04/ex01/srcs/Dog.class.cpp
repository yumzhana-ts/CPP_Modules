/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:16 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/08/05 23:48:54 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.class.hpp"
#include "Brain.class.hpp"

/****************************************************/
/*                    Constructor                   */
/****************************************************/

Dog::Dog(void): Animal("Dog"), brain(new Brain())
{
    if (DEBUG){ std::cout << GREEN << "[Dog] Default Constructor called" << RESET_COLOR << std::endl;}
}
//Dog(std::string n = "Unkown"): name(n)

Dog::Dog(const Dog& src): Animal(src.type), brain(new Brain(*src.brain)) 
{
    if (DEBUG){std::cout << GREEN << "[Dog] Copy Constructor called" << RESET_COLOR << std::endl;}
    *this = src;
}

/****************************************************/
/*                    Destructor.                   */
/****************************************************/

Dog::~Dog(void) 
{
    if (DEBUG){std::cout << GREEN << "[Dog] Destructor called" << RESET_COLOR << std::endl;}
    delete brain;
}

/****************************************************
*                    Overload                      *
****************************************************/


Dog& Dog::operator=(const Dog& rhs) 
{
    if (DEBUG){std::cout << GREEN << "[Dog] Copy assignment operator called" << RESET_COLOR <<  std::endl;}
    if (this != &rhs)
    {
        this->type = rhs.type;
        this->brain = new Brain(*rhs.brain);
    }
    return (*this);
}

/****************************************************
*                 Memeber Functions                *
****************************************************/

void Dog::make_sound() const
{
    std::cout << "Woooof!"<< std::endl;
}

/* void Dog::print_brain_address() const 
{
    std::cout << GREEN << "Brain address: " << brain << RESET_COLOR <<std::endl;
} */