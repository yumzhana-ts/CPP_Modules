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

#include "B.class.hpp"

/****************************************************/
/*                    Constructor                   */
/****************************************************/

B::B(void) 
{
    if (DEBUG){ std::cout << GREEN << "[B] Default Constructor called" << RESET_COLOR << std::endl;}
}

/****************************************************/
/*                    Destructor.                   */
/****************************************************/

B::~B(void) 
{
    if (DEBUG){std::cout << GREEN << "[B] Destructor called" << RESET_COLOR << std::endl;}
}

/****************************************************
*                 Memeber Functions                *
****************************************************/
