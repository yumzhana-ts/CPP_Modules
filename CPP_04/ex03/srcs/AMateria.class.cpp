/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:16 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/08/06 16:32:50 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.class.hpp"

/****************************************************/
/*                    Constructor                   */
/****************************************************/

AMateria::AMateria(std::string const &type): type(type)
{
    if (DEBUG){ std::cout << GREEN << "[AMateria] Default Constructor called" << RESET_COLOR << std::endl;}
}
//AMateria(std::string n = "Unkown"): name(n)

AMateria::AMateria(const AMateria& src) 
{
    if (DEBUG){std::cout << GREEN << "[AMateria] Copy Constructor called" << RESET_COLOR << std::endl;}
    *this = src;
}

/****************************************************/
/*                    Destructor.                   */
/****************************************************/

AMateria::~AMateria(void) 
{
    if (DEBUG){std::cout << GREEN << "[AMateria] Destructor called" << RESET_COLOR << std::endl;}
}

/****************************************************
*                    Overload                      *
****************************************************/


AMateria& AMateria::operator=(const AMateria& rhs) 
{
    if (DEBUG){std::cout << GREEN << "[AMateria] Copy assignment operator called" << std::endl;}
    if (this != &rhs)
        this->type = rhs.type;
    return (*this);
}

/****************************************************
*                 Memeber Functions                *
****************************************************/
