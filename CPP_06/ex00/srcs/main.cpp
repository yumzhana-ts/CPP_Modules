/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:41:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/07/13 03:54:02 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.class.hpp"

void orthodox_test()
{
    ScalarConverter obj1; // Default Constructor called
    ScalarConverter obj2(obj1); // Copy Constructor called
    ScalarConverter obj3;
    obj3 = obj2; // Copy Assignment Operator called  
}

int main(int argc, char **argv) 
{
    //td::string str = argv[1];
    if (argc == 2)
        ScalarConverter::convert(argv[1]);
    else
        std::cout << RED << "Please, provide at least one argument or string in range of LONG LONG INT" << RESET_COLOR << std::endl;
    return (0);
}