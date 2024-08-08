/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:16 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/08/06 16:50:22 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.class.hpp"
#include "AMateria.class.hpp"

/****************************************************/
/*                    Constructor                   */
/****************************************************/

Ice::Ice(void): AMateria("ice")
{
    if (DEBUG){ std::cout << GREEN << "[Ice] Default Constructor called" << RESET_COLOR << std::endl;}
}
//Ice(std::string n = "Unkown"): name(n)

Ice::Ice(const Ice& src): AMateria(src.type)
{
    if (DEBUG){std::cout << GREEN << "[Ice] Copy Constructor called" << RESET_COLOR << std::endl;}
    *this = src;
}

/****************************************************/
/*                    Destructor.                   */
/****************************************************/

Ice::~Ice(void) 
{
    if (DEBUG){std::cout << GREEN << "[Ice] Destructor called" << RESET_COLOR << std::endl;}
}

/****************************************************
*                    Overload                      *
****************************************************/


Ice& Ice::operator=(const Ice& rhs) 
{
    if (DEBUG){std::cout << GREEN << "[Ice] Copy assignment operator called" << RESET_COLOR << std::endl;}
    if (this != &rhs)
        this->type = rhs.type;
    return (*this);
}

/****************************************************
*                 Memeber Functions                *
****************************************************/
