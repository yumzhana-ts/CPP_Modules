/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:16 by ytsyrend          #+#    #+#             */
/*   Updated: 2025/02/18 20:50:14 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.class.hpp"

/****************************************************/
/*                    Constructor                   */
/****************************************************/

Array::Array(void) 
{
    if (DEBUG){ std::cout << GREEN << "[Array] Default Constructor called" << RESET_COLOR << std::endl;}
}
//Array(std::string n = "Unkown"): name(n)

Array::Array(const Array& src) 
{
    if (DEBUG){std::cout << GREEN << "[Array] Copy Constructor called" << RESET_COLOR << std::endl;}
    //*this = src;
}

/****************************************************/
/*                    Destructor.                   */
/****************************************************/

Array::~Array(void) 
{
    if (DEBUG){std::cout << GREEN << "[Array] Destructor called" << RESET_COLOR << std::endl;}
}

/****************************************************
*                    Overload                      *
****************************************************/


Array& Array::operator=(const Array& rhs) 
{
    if (DEBUG){std::cout << GREEN << "[Array] Copy assignment operator called" << std::endl;}
    if (this != &rhs)
        this->value = rhs.get_value();
    return (*this);
}

/****************************************************
*                 Memeber Functions                *
****************************************************/
