/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:41:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2025/02/18 20:50:14 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main() 
{
    int t = 1;
    std::cout << BOLD << "Test case " << t++ << ": Int array creation" << RESET_COLOR << std::endl;
    Array<int> obj(10);
    obj.nice_testing(1);

    std::cout << BOLD << "Test case " << t++ << ": double array creation" << RESET_COLOR << std::endl;
    Array<double> obj1(10);
    obj1.nice_testing(11);

    std::cout << BOLD << "Test case " << t++ << ": string array creation" << RESET_COLOR << std::endl;
    Array<std::string> obj2(10);
    obj2.nice_testing(1);

    std::cout << BOLD << "Test case " << t++ << ": bool array creation" << RESET_COLOR << std::endl;
    Array<bool> obj3(10);
    obj3.nice_testing(1);

    std::cout << BOLD << "Test case " << t++ << ": empty int array creation " << RESET_COLOR << std::endl;
    Array<int> obj4;

    std::cout << BOLD << "Test case " << t++ << ": bad access creation " << RESET_COLOR << std::endl;
    obj4.nice_testing(1);

    std::cout << BOLD << "Test case " << t++ << ": copy constructor " << RESET_COLOR << std::endl;
    Array<int> obj5(obj4);
    obj5.nice_testing(0);

    std::cout << BOLD << "Test case " << t++ << ": copy assignment operator " << RESET_COLOR << std::endl;
    obj5 = obj;
    obj5.nice_testing(0);
    return (0);
}