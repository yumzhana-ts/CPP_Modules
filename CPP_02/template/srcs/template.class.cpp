/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:16 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/07/09 16:38:53 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Template.class.hpp"

/****************************************************/
/*                    Constructor                   */
/****************************************************/

Template_c::Template_c(void) 
{
    if (DEBUG){ std::cout << GREEN << "[Constructor] Template - Default Constructor called" << RESET_COLOR << std::endl;}
}
//Template_c(std::string n = "Unkown"): name(n)

Template_c::Template_c(const Template_c& src) 
{
    if (DEBUG){std::cout << GREEN << "[Constructor] Template - Copy Constructor called" << RESET_COLOR << std::endl;}
    *this = src;
}

/****************************************************/
/*                    Destructor.                   */
/****************************************************/

Template_c::~Template_c(void) 
{
    if (DEBUG){std::cout << GREEN << "[Destructor] Template - Destructor called" << RESET_COLOR << std::endl;}
}

/****************************************************
*                    Overload                      *
****************************************************/


Template_c& Template_c::operator=(const Template_c& rhs) 
{
    if (DEBUG){std::cout << GREEN << "[Assignment] Copy assignment operator called" << std::endl;}
    if (this != &rhs)
        this->value = rhs.get_value();
    return (*this);
}

/****************************************************
*                 Memeber Functions                *
****************************************************/
