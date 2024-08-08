/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:16 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/08/06 15:46:45 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.class.hpp"

/****************************************************/
/*                    Constructor                   */
/****************************************************/

ICharacter::ICharacter(void) 
{
    if (DEBUG){ std::cout << GREEN << "[ICharacter] Default Constructor called" << RESET_COLOR << std::endl;}
}
//ICharacter(std::string n = "Unkown"): name(n)

/* ICharacter::ICharacter(const ICharacter& src) 
{
    if (DEBUG){std::cout << GREEN << "[ICharacter] Copy Constructor called" << RESET_COLOR << std::endl;}
    *this = src;
} */

/****************************************************/
/*                    Destructor.                   */
/****************************************************/

ICharacter::~ICharacter(void) 
{
    if (DEBUG){std::cout << GREEN << "[ICharacter] Destructor called" << RESET_COLOR << std::endl;}
}

/****************************************************
*                    Overload                      *
****************************************************/


/* ICharacter& ICharacter::operator=(const ICharacter& rhs) 
{
    if (DEBUG){std::cout << GREEN << "[ICharacter] Copy assignment operator called" << std::endl;}
    if (this != &rhs)
        this->value = rhs.get_value();
    return (*this);
} */

/****************************************************
*                 Memeber Functions                *
****************************************************/
