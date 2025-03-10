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

#include "Span.class.hpp"

/****************************************************/
/*                    Constructor                   */
/****************************************************/

Span::Span(void) 
{
    if (DEBUG){ std::cout << GREEN << "[Span] Default Constructor called" << RESET_COLOR << std::endl;}
}
//Span(std::string n = "Unkown"): name(n)

Span::Span(const Span& src) 
{
    if (DEBUG){std::cout << GREEN << "[Span] Copy Constructor called" << RESET_COLOR << std::endl;}
    //*this = src;
}

/****************************************************/
/*                    Destructor.                   */
/****************************************************/

Span::~Span(void) 
{
    if (DEBUG){std::cout << GREEN << "[Span] Destructor called" << RESET_COLOR << std::endl;}
}

/****************************************************
*                    Overload                      *
****************************************************/


Span& Span::operator=(const Span& rhs) 
{
    if (DEBUG){std::cout << GREEN << "[Span] Copy assignment operator called" << std::endl;}
    if (this != &rhs)
        this->value = rhs.get_value();
    return (*this);
}

/****************************************************
*                 Memeber Functions                *
****************************************************/
