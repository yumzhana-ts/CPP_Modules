/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.class.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:16 by ytsyrend          #+#    #+#             */
/*   Updated: 2025/02/06 15:40:10 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.class.hpp"

/****************************************************/
/*                    Constructor                   */
/****************************************************/

ScalarConverter::ScalarConverter(void)
{
    if (DEBUG)
    {
        std::cout << GREEN << "[ScalarConverter] Default Constructor called" << RESET_COLOR << std::endl;
    }
}
// ScalarConverter(std::string n = "Unkown"): name(n)

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
    if (DEBUG)
    {
        std::cout << GREEN << "[ScalarConverter] Destructor called" << RESET_COLOR << std::endl;
    }
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
void print_conversion_edge_cases(s_data data);

void ScalarConverter::convert(std::string argument)
{
    s_data data;
    data.type = get_type(argument);
    if ((data.type == 0 && (std::atoll(argument.c_str()) > INT_MAX || std::atoll(argument.c_str()) < INT_MIN)) || (data.type == 3 && (static_cast<float>(std::atof(argument.c_str())) > __FLT_MAX__ || static_cast<float>(std::atof(argument.c_str())) < __FLT_MIN__)) || (data.type == 2 && (std::atof(argument.c_str()) > __DBL_MAX__ || std::atof(argument.c_str()) < __DBL_MIN__)))
        data.type = undefined_type;
    else
        data.value = type_conversion(data.type, argument);
    data.c = 0;
    if (data.type == int_type)
    {
        data.i = data.value.int_value;
        if (data.i >= 0 && data.i <= 127)
            data.c = static_cast<char>(data.i);
        data.f = static_cast<float>(data.value.int_value);
        data.d = static_cast<double>(data.value.int_value);
        print_conversion(data);
    }
    else if (data.type == float_type)
    {
        data.i = static_cast<int>(data.value.float_value);
        if (data.i >= 0 && data.i <= 127)
            data.c = static_cast<char>(data.i);
        data.f = data.value.float_value;
        data.d = static_cast<double>(data.value.float_value);
        print_conversion(data);
    }
    else if (data.type == double_type)
    {
        data.i = static_cast<int>(data.value.double_value);
        if (data.i >= 0 && data.i <= 127)
            data.c = static_cast<char>(data.i);
        data.f = static_cast<float>(data.value.double_value);
        data.d = data.value.double_value;
        print_conversion(data);
    }
    else if (data.type == char_type)
    {
        data.i = static_cast<int>(data.value.char_value);
        data.c = data.value.char_value;
        data.f = static_cast<float>(data.value.char_value);
        data.d = static_cast<double>(data.value.char_value);
        print_conversion(data);
    }
    else if (data.type == inff_plus)
    {
        data.f = data.value.float_value;
        data.d = static_cast<double>(data.value.float_value);
        print_conversion_edge_cases(data);
    }
    else if (data.type == inff_minus)
    {
        data.f = data.value.float_value;
        data.d = static_cast<double>(data.value.float_value);
        print_conversion_edge_cases(data);
    }
    else if (data.type == inf_plus)
    {
        data.d = data.value.double_value;
        data.f = static_cast<float>(data.value.double_value);
        print_conversion_edge_cases(data);
    }
    else if (data.type == inf_minus)
    {
        data.d = data.value.double_value;
        data.f = static_cast<float>(data.value.double_value);
        print_conversion_edge_cases(data);
    }
    else if (data.type == nanf_type)
    {
        data.f = data.value.float_value;
        data.d = static_cast<double>(data.value.float_value);
        print_conversion_edge_cases(data);
    }
    else if (data.type == nan_type)
    {
        data.d = data.value.double_value;
        data.f = static_cast<float>(data.value.double_value);
        print_conversion_edge_cases(data);
    }
    else if (data.type == undefined_type)
        std::cout << RED << "Type is undefined, please provide correct type" RESET_COLOR << std::endl;
}