/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:16 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/12/01 22:50:01 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.class.hpp"

/****************************************************/
/*                    Constructor                   */
/****************************************************/

Serialize::Serialize(void) 
{
    if (DEBUG){ std::cout << GREEN << "[Serialize] Default Constructor called" << RESET_COLOR << std::endl;}
}
//Serialize(std::string n = "Unkown"): name(n)

Serialize::Serialize(const Serialize& src) 
{
    if (DEBUG){std::cout << GREEN << "[Serialize] Copy Constructor called" << RESET_COLOR << std::endl;}
    *this = src;
}

/****************************************************/
/*                    Destructor.                   */
/****************************************************/

Serialize::~Serialize(void) 
{
    if (DEBUG){std::cout << GREEN << "[Serialize] Destructor called" << RESET_COLOR << std::endl;}
}

/****************************************************
*                    Overload                      *
****************************************************/


Serialize& Serialize::operator=(const Serialize& rhs) 
{
    if (DEBUG){std::cout << GREEN << "[Serialize] Copy assignment operator called" << std::endl;}
    if (this != &rhs)
    {

    }
    return (*this);
}

/****************************************************
*                 Memeber Functions                *
****************************************************/

uintptr_t Serialize::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}


Data* Serialize::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data *>(raw);
}