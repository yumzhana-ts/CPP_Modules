/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:16 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/08/06 16:50:29 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.class.hpp"
#include "AMateria.class.hpp"

/****************************************************/
/*                    Constructor                   */
/****************************************************/

Cure::Cure(void): AMateria("cure")
{
    if (DEBUG){ std::cout << GREEN << "[Cure] Default Constructor called" << RESET_COLOR << std::endl;}
}
//Cure(std::string n = "Unkown"): name(n)

Cure::Cure(const Cure& src): AMateria(src.type)
{
    if (DEBUG){std::cout << GREEN << "[Cure] Copy Constructor called" << RESET_COLOR << std::endl;}
    *this = src;
}

/****************************************************/
/*                    Destructor.                   */
/****************************************************/

Cure::~Cure(void) 
{
    if (DEBUG){std::cout << GREEN << "[Cure] Destructor called" << RESET_COLOR << std::endl;}
}

/****************************************************
*                    Overload                      *
****************************************************/


Cure& Cure::operator=(const Cure& rhs) 
{
    if (DEBUG){std::cout << GREEN << "[Cure] Copy assignment operator called" << RESET_COLOR <<  std::endl;}
    if (this != &rhs)
        this->type = rhs.type;
    return (*this);
}

/****************************************************
*                 Memeber Functions                *
****************************************************/
