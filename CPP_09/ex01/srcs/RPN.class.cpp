/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:16 by ytsyrend          #+#    #+#             */
/*   Updated: 2025/04/02 13:02:17 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.class.hpp"

/****************************************************/
/*                    Constructor                   */
/****************************************************/

RPN::RPN(std::stack<int> ss): super_stack(ss)
{
    if (DEBUG){ std::cout << GREEN << "[RPN] Default Constructor called" << RESET_COLOR << std::endl;}
}
//RPN(std::string n = "Unkown"): name(n)

RPN::RPN(const RPN& src) : super_stack(src.super_stack)
{
    if (DEBUG){std::cout << GREEN << "[RPN] Copy Constructor called" << RESET_COLOR << std::endl;}
    //*this = src;
}

/****************************************************/
/*                    Destructor.                   */
/****************************************************/

RPN::~RPN(void) 
{
    if (DEBUG){std::cout << GREEN << "[RPN] Destructor called" << RESET_COLOR << std::endl;}
}

/****************************************************
*                    Overload                      *
****************************************************/


RPN& RPN::operator=(const RPN& rhs) 
{
    if (DEBUG){std::cout << GREEN << "[RPN] Copy assignment operator called" << std::endl;}
    if (this != &rhs)
    {
        this->super_stack = rhs.super_stack;
    }
    return (*this);
}

/****************************************************
*                 Memeber Functions                *
****************************************************/
