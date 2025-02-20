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
#include "array.hpp"

int main() 
{
    int t = 1;
    std::cout << GREEN << "Test case " << t++ << ": int" << RESET_COLOR << std::endl;
    int a = 2;
    int b = 9;
    ::nice_testing(a, b);
    std::cout << LINE << std::endl;

    std::cout << GREEN << "Test case " << t++ << ": equal ints" << RESET_COLOR << std::endl;
    a = 9;
    b = 9;
    ::nice_testing(a, b);
    std::cout << LINE << std::endl;

    std::cout << GREEN << "Test case " << t++ << ": doubles" << RESET_COLOR << std::endl;
    double a_d = 3.14;
    double b_d = 4.14;
    ::nice_testing(a_d, b_d);
    std::cout << LINE << std::endl;

    std::cout << GREEN << "Test case " << t++ << ": string" << RESET_COLOR << std::endl;
    std::string a_s = "a";
    std::string b_s = "b";
    ::nice_testing(a_s, b_s);
    std::cout << LINE << std::endl;

    std::cout << GREEN << "Test case " << t++ << ": int explicit type instantiation" << RESET_COLOR << std::endl;
    ::nice_testing<int>(a, b);
    std::cout << LINE << std::endl;

    std::cout << GREEN << "Test case " << t++ << ": double explicit type instantiation" << RESET_COLOR << std::endl;
    ::nice_testing<double>(a_d, b_d);
    std::cout << LINE << std::endl;

    std::cout << GREEN << "Test case " << t++ << ": passing a function and parametric macros" << RESET_COLOR << std::endl;
    std::cout << max<int>(foo(a), foo(b)) << std::endl;
    std::cout << c_max(foo(a), foo(b)) << std::endl;
    std::cout << LINE << std::endl;

    return 0;
}