/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:16 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/08/01 16:16:07 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.class.hpp"

/****************************************************/
/*                    Constructor                   */
/****************************************************/

Dog::Dog(void): Animal("Dog")
{
    if (DEBUG){ std::cout << GREEN << "[Dog] Default Constructor called" << RESET_COLOR << std::endl;}
}
//Dog(std::string n = "Unkown"): name(n)

Dog::Dog(const Dog& src) 
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
}


/****************************************************
*                 Memeber Functions                *
****************************************************/

void Dog::make_sound() const
{
    std::cout << "Woooof!"<< std::endl;
}