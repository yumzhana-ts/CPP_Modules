/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:41:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2025/02/06 14:59:24 by ytsyrend         ###   ########.fr       */
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

int main() 
{
	/*std::string input;
    std::cout << RED << "Test case 1: Ints within range(long long int min)" << RESET_COLOR << std::endl;
    input = "-9223372036854775808";
    ScalarConverter::convert(input);
    std::cout << LINE << std::endl;
    std::cout << RED << "Test case 2: Ints within range(long long int max)" << RESET_COLOR << std::endl;
    input = "9223372036854775807";
    ScalarConverter::convert(input);
    std::cout << LINE << std::endl;
    std::cout << RED << "Test case 3: Ints out of the range(0)" << RESET_COLOR << std::endl;
    input = "-9223372036854775809";
    ScalarConverter::convert(input);
    std::cout << LINE << std::endl;
    std::cout << RED << "Test case 4: Ints out of the range(long long int max+)" << RESET_COLOR << std::endl;
    input = "9223372036854775808";
    std::cout << RED << "note: tady by to chtelo pred converzi controlu na long long int" << RESET_COLOR << std::endl;
    ScalarConverter::convert(input);
    std::cout << LINE << std::endl;*/

    double number = 2147483.034;
    //int num = number;
    std::cout << number << std::endl;
    return (0);
}