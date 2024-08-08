/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.class.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:16 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/08/06 19:49:29 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.class.hpp"

/****************************************************/
/*                    Constructor                   */
/****************************************************/

IMateriaSource::IMateriaSource(void) 
{
    if (DEBUG){ std::cout << GREEN << "[IMateriaSource] Default Constructor called" << RESET_COLOR << std::endl;}
}

/* IMateriaSource::IMateriaSource(const IMateriaSource& src) 
{
    if (DEBUG){std::cout << GREEN << "[IMateriaSource] Copy Constructor called" << RESET_COLOR << std::endl;}
    *this = src;
} */

/****************************************************/
/*                    Destructor.                   */
/****************************************************/

IMateriaSource::~IMateriaSource(void) 
{
    if (DEBUG){std::cout << GREEN << "[IMateriaSource] Destructor called" << RESET_COLOR << std::endl;}
}

/****************************************************
*                    Overload                      *
****************************************************/


/* IMateriaSource& IMateriaSource::operator=(const IMateriaSource& rhs) 
{
    if (DEBUG){std::cout << GREEN << "[IMateriaSource] Copy assignment operator called" << std::endl;}
    if (this != &rhs)
        this->value = rhs.get_value();
    return (*this);
} */

/****************************************************
*                 Memeber Functions                *
****************************************************/

