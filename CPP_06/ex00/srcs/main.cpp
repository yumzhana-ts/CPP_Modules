/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:41:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2025/02/06 14:51:27 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.class.hpp"

int main(int argc, char **argv) 
{
    if (argc == 2 && (static_cast<std::string>(argv[1])).size() < 19)
        ScalarConverter::convert(argv[1]);
    else
        std::cout << RED << "Please, provide at least one argument or string in range of LONG LONG INT" << RESET_COLOR << std::endl;
    return (0);
}