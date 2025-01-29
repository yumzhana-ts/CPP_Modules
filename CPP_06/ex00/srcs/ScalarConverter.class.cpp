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

#include "ScalarConverter.class.hpp"


/****************************************************/
/*                    Constructor                   */
/****************************************************/

ScalarConverter::ScalarConverter(void) 
{
    if (DEBUG){ std::cout << GREEN << "[ScalarConverter] Default Constructor called" << RESET_COLOR << std::endl;}
}
//ScalarConverter(std::string n = "Unkown"): name(n)

/*ScalarConverter::ScalarConverter(const ScalarConverter& src) 
{
    if (DEBUG){std::cout << GREEN << "[ScalarConverter] Copy Constructor called" << RESET_COLOR << std::endl;}
    *this = src;
}*/

/****************************************************/
/*                    Destructor.                   */
/****************************************************/

ScalarConverter::~ScalarConverter(void) 
{
    if (DEBUG){std::cout << GREEN << "[ScalarConverter] Destructor called" << RESET_COLOR << std::endl;}
}

/****************************************************
*                    Overload                      *
****************************************************/


/*ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs) 
{
    if (DEBUG){std::cout << GREEN << "[ScalarConverter] Copy assignment operator called" << std::endl;}
    if (this != &rhs)
        this->value = rhs.get_value();
    return (*this);
}*/

/****************************************************
*                 Memeber Functions                *
****************************************************/


std::string ScalarConverter::convert(std::string argument) 
{
    std::cout << GREEN << "Converting string " << argument << "..." RESET_COLOR << std::endl;
    
    if (argument.length() == 1)
    {
        if (std::isdigit(argument[0]) == 1)
            ;
    }
}