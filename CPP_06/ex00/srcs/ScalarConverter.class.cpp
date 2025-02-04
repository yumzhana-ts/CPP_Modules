/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.class.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:16 by ytsyrend          #+#    #+#             */
/*   Updated: 2025/02/04 00:12:02 by ytsyrend         ###   ########.fr       */
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
void print_conversion(s_data data);

void ScalarConverter::convert(std::string argument) 
{
    s_data data;
    data.type = get_type(argument);
    data.value = type_conversion(data.type, argument);

    if(data.type == int_type)
    {
        data.i = static_cast<long long int>(data.value.int_value);
        if (data.i >= 33 && data.i <= 126)
            data.c = static_cast<char>(data.value.int_value);
        else
            data.c = 0;
        data.f = static_cast<float>(data.value.int_value);
        data.d = static_cast<double>(data.value.int_value);
        print_conversion(data);
    }
    else if(data.type == float_type)
    {
        data.i = static_cast<long long int>(data.value.float_value);
        if (data.i >= 33 && data.i <= 126)
            data.c = static_cast<char>(data.value.float_value);
        else
            data.c = 0;
        data.f = static_cast<float>(data.value.float_value);
        data.d = static_cast<double>(data.value.float_value);
        print_conversion(data);
    }
    else if(data.type == double_type)
    {
        data.i = static_cast<long long int>(data.value.double_value);
        if (data.i >= 33 && data.i <= 126)
            data.c = static_cast<char>(data.value.double_value);
        else
            data.c = 0;
        data.f = static_cast<float>(data.value.double_value);
        data.d = static_cast<double>(data.value.double_value);
        print_conversion(data);
    }
    else if(data.type == char_type)
    {

        data.i = static_cast<long long int>(data.value.char_value);
        if (data.i >= 33 && data.i <= 126)
            data.c = static_cast<char>(data.value.char_value);
        else
            data.c = 0;
        data.f = static_cast<float>(data.value.char_value);
        data.d = static_cast<double>(data.value.char_value);
        print_conversion(data);
    }
    else if(data.type == undefined_type)
        std::cout << RED << "Type is undefined, please provide correct type" RESET_COLOR << std::endl;
}