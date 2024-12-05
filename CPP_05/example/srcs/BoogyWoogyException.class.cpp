/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BoogyWoogyException.class.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:16 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/11/27 16:10:14 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BoogyWoogyException.class.hpp"

/****************************************************/
/*                    Constructor                   */
/****************************************************/

BoogyWoogyException::BoogyWoogyException() 
{
    if (DEBUG){ std::cout << GREEN << "[BoogyWoogyException] Default Constructor called" << RESET_COLOR << std::endl;}
}

/****************************************************/
/*                    Destructor.                   */
/****************************************************/

BoogyWoogyException::~BoogyWoogyException() throw()
{
    if (DEBUG){std::cout << GREEN << "[BoogyWoogyException] Destructor called" << RESET_COLOR << std::endl;}
}
