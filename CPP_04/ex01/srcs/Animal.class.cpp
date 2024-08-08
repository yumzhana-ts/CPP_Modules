/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:16 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/08/03 21:57:00 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.class.hpp"
#include "Brain.class.hpp"

/****************************************************/
/*                    Constructor                   */
/****************************************************/

Animal::Animal(std::string t): type(t)
{
    if (DEBUG){ std::cout << GREEN << "[Animal] Default Constructor called" << RESET_COLOR << std::endl;}
}
//Animal(std::string n = "Unkown"): name(n)

Animal::Animal(const Animal& other) : type(other.type)
{
    if (DEBUG) { std::cout << GREEN << "[Animal] Copy Constructor called" << RESET_COLOR << std::endl; }
}

/****************************************************/
/*                    Destructor.                   */
/****************************************************/

Animal::~Animal(void) 
{
    if (DEBUG){std::cout << GREEN << "[Animal] Destructor called" << RESET_COLOR << std::endl;}
}

/****************************************************
*                    Overload                      *
****************************************************/


Animal& Animal::operator=(const Animal& rhs) 
{
    if (DEBUG){std::cout << GREEN << "[Animal] Copy assignment operator called" << RESET_COLOR <<  std::endl;}
    if (this != &rhs)
    {
        this->type = rhs.type;
    }
    return (*this);
}

/****************************************************
*                 Memeber Functions                *
****************************************************/

void Animal::make_sound() const
{
    std::cout << "animal sound" << std::endl;
}


