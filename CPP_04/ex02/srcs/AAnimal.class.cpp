/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:16 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/08/05 16:38:52 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.class.hpp"
#include "Brain.class.hpp"

/****************************************************/
/*                    Constructor                   */
/****************************************************/

AAnimal::AAnimal(std::string t): type(t)
{
    if (DEBUG){ std::cout << GREEN << "[AAnimal] Default Constructor called" << RESET_COLOR << std::endl;}
}
//AAnimal(std::string n = "Unkown"): name(n)

AAnimal::AAnimal(const AAnimal& other) : type(other.type)
{
    if (DEBUG) { std::cout << GREEN << "[AAnimal] Copy Constructor called" << RESET_COLOR << std::endl; }
}

/****************************************************/
/*                    Destructor.                   */
/****************************************************/

AAnimal::~AAnimal(void) 
{
    if (DEBUG){std::cout << GREEN << "[AAnimal] Destructor called" << RESET_COLOR << std::endl;}
}

/****************************************************
*                    Overload                      *
****************************************************/


AAnimal& AAnimal::operator=(const AAnimal& rhs) 
{
    if (DEBUG){std::cout << GREEN << "[AAnimal] Copy assignment operator called" << RESET_COLOR <<  std::endl;}
    if (this != &rhs)
    {
        this->type = rhs.type;
    }
    return (*this);
} 

/****************************************************
*                 Memeber Functions                *
****************************************************/

/* void AAnimal::make_sound() const
{
    std::cout << "AAnimal sound" << std::endl;
} */


