/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:16 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/08/01 16:15:55 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.class.hpp"

/****************************************************/
/*                    Constructor                   */
/****************************************************/

WrongCat::WrongCat(): WrongAnimal("WrongCat")
{
    if (DEBUG){ std::cout << GREEN << "[WrongCat] Default Constructor called" << RESET_COLOR << std::endl;}
}
//WrongCat(std::string n = "Unkown"): name(n)

WrongCat::WrongCat(const WrongCat& src) 
{
    if (DEBUG){std::cout << GREEN << "[WrongCat] Copy Constructor called" << RESET_COLOR << std::endl;}
    *this = src;
}

/****************************************************/
/*                    Destructor.                   */
/****************************************************/

WrongCat::~WrongCat(void) 
{
    if (DEBUG){std::cout << GREEN << "[WrongCat] Destructor called" << RESET_COLOR << std::endl;}
}


/****************************************************
*                 Memeber Functions                *
****************************************************/

void WrongCat::make_sound() const
{
    std::cout << "Meow!" << std::endl;
}