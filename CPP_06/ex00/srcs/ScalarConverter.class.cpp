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
s_data_types get_type(std::string str);
s_data_values type_conversion(s_data_types type, std::string argument);

void ScalarConverter::convert(std::string argument) 
{
    s_data data;
    std::cout << GREEN << "Converting string " << argument << "..." RESET_COLOR << std::endl;
    data.type = get_type(argument);
    data.value = type_conversion(get_type(argument), argument);
    if(data.type == int_type)
    {
        std:: cout << data.value.int_value;
    }
    else if(data.type == float_type)
    {
        std::cout << data.value.float_value;
    }
}