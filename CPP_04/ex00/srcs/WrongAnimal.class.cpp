/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.class.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:16 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/08/01 16:04:18 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.class.hpp"

/****************************************************/
/*                    Constructor                   */
/****************************************************/

WrongAnimal::WrongAnimal(std::string t): type(t)
{
    if (DEBUG){ std::cout << GREEN << "[WrongAnimal] Default Constructor called" << RESET_COLOR << std::endl;}
}
//WrongAnimal(std::string n = "Unkown"): name(n)

WrongAnimal::WrongAnimal(const WrongAnimal& src) 
{
    if (DEBUG){std::cout << GREEN << "[WrongAnimal] Copy Constructor called" << RESET_COLOR << std::endl;}
    *this = src;
}

/****************************************************/
/*                    Destructor.                   */
/****************************************************/

WrongAnimal::~WrongAnimal(void) 
{
    if (DEBUG){std::cout << GREEN << "[WrongAnimal] Destructor called" << RESET_COLOR << std::endl;}
}

/****************************************************
*                    Overload                      *
****************************************************/


WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs) 
{
    if (DEBUG){std::cout << GREEN << "[WrongAnimal] Copy assignment operator called" << RESET_COLOR <<  std::endl;}
    if (this != &rhs)
        this->type = rhs.get_type();
    return (*this);
}

/****************************************************
*                 Memeber Functions                *
****************************************************/

void WrongAnimal::make_sound() const
{
    std::cout << "wrong animal sound" << std::endl;
}