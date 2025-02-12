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
    orthodox_test();
	std::string input;
    int t = 0;

    std::cout << RED << "Test case " << t++ << ": Ints within the range(INT_MIN)" << RESET_COLOR << std::endl;
    input = "-2147483648";
    ScalarConverter::convert(input);
    std::cout << LINE << std::endl;

    std::cout << RED << "Test case " << t++ << ": Ints within the range(INT_MAX)" << RESET_COLOR << std::endl;
    input = "2147483647";
    ScalarConverter::convert(input);
    std::cout << LINE << std::endl;

    std::cout << RED << "Test case " << t++ << ": Ints out of the range(<INT_MIN)" << RESET_COLOR << std::endl;
    input = "-2147483649";
    ScalarConverter::convert(input);
    std::cout << LINE << std::endl;

    std::cout << RED << "Test case " << t++ << ": Ints out of the range(>INT_MAX)" << RESET_COLOR << std::endl;
    input = "2147483648";
    ScalarConverter::convert(input);
    std::cout << LINE << std::endl;

    std::cout << RED << "Test case " << t++ << ": Char non-displayable" << RESET_COLOR << std::endl;
    input = " ";
    ScalarConverter::convert(input);
    std::cout << LINE << std::endl;

    std::cout << RED << "Test case " << t++ << ": Char lower" << RESET_COLOR << std::endl;
    input = "a";
    ScalarConverter::convert(input);
    std::cout << LINE << std::endl;

    std::cout << RED << "Test case " << t++ << ": Char upper" << RESET_COLOR << std::endl;
    input = "Z";
    ScalarConverter::convert(input);
    std::cout << LINE << std::endl;

    std::cout << RED << "Test case " << t++ << ": Double" << RESET_COLOR << std::endl;
    input = "23231.34345";
    ScalarConverter::convert(input);
    std::cout << LINE << std::endl;

    std::cout << RED << "Test case " << t++ << ": Double +inf" << RESET_COLOR << std::endl;
    input = "+inf";
    ScalarConverter::convert(input);
    std::cout << LINE << std::endl;

    std::cout << RED << "Test case " << t++ << ": Double -inf" << RESET_COLOR << std::endl;
    input = "-inf";
    ScalarConverter::convert(input);
    std::cout << LINE << std::endl;

    std::cout << RED << "Test case " << t++ << ": Double nan" << RESET_COLOR << std::endl;
    input = "nan";
    ScalarConverter::convert(input);
    std::cout << LINE << std::endl;

    std::cout << RED << "Test case " << t++ << ": Float" << RESET_COLOR << std::endl;
    input = "23231.34345f";
    ScalarConverter::convert(input);
    std::cout << LINE << std::endl;

    std::cout << RED << "Test case " << t++ << ": Float +inff" << RESET_COLOR << std::endl;
    input = "+inff";
    ScalarConverter::convert(input);
    std::cout << LINE << std::endl;

    std::cout << RED << "Test case " << t++ << ": Float -inff" << RESET_COLOR << std::endl;
    input = "-inff";
    ScalarConverter::convert(input);
    std::cout << LINE << std::endl;

    std::cout << RED << "Test case " << t++ << ": Float nanf" << RESET_COLOR << std::endl;
    input = "nanf";
    ScalarConverter::convert(input);
    std::cout << LINE << std::endl; 
    return (0);
}