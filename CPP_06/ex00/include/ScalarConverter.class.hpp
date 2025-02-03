/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/07/06 12:37:40 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ScalarConverterLASS_H
#define ScalarConverterLASS_H

#include <iostream>
#include <typeinfo>
#include <cctype>
#include <string>

typedef enum t_data_types
{
    int_type,
    char_type,
    double_type,
    float_type,
    undefined_type,
    inff_minus,
    inff_plus,
    nanf,
    inf_plus,
    inf_minus,
    nan
} s_data_types;

typedef union t_data_values
{
    int int_value;
    float float_value;
    double double_value;
    const char* char_value;
} s_data_values;

typedef struct t_data
{
    s_data_types type;
    s_data_values value;
} s_data;

class ScalarConverter
{
public:
    ScalarConverter(void);
    ~ScalarConverter(void);
    //ScalarConverter(const ScalarConverter& other);
    //ScalarConverter& operator=(const ScalarConverter& other);
    static void convert(std::string argument);
};



#define DEBUG 1
// Define ANSI escape sequences for colors
#define RESET_COLOR "\033[0m"
#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define BLUE "\033[0;34m"
#define WHITE "\033[0;37m"
#define BOLD_BLACK "\033[1;30m"
#define BG_WHITE "\033[0;47m"
#endif