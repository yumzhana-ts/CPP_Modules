/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:16 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/08/01 16:16:13 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.class.hpp"

/****************************************************/
/*                    Constructor                   */
/****************************************************/

Cat::Cat(): Animal("Cat")
{
    if (DEBUG){ std::cout << GREEN << "[Cat] Default Constructor called" << RESET_COLOR << std::endl;}
}
//Cat(std::string n = "Unkown"): name(n)

Cat::Cat(const Cat& src) 
{
    if (DEBUG){std::cout << GREEN << "[Cat] Copy Constructor called" << RESET_COLOR << std::endl;}
    *this = src;
}

/****************************************************/
/*                    Destructor.                   */
/****************************************************/

Cat::~Cat(void) 
{
    if (DEBUG){std::cout << GREEN << "[Cat] Destructor called" << RESET_COLOR << std::endl;}
}


/****************************************************
*                 Memeber Functions                *
****************************************************/

void Cat::make_sound() const
{
    std::cout << "Meow!" << std::endl;
}