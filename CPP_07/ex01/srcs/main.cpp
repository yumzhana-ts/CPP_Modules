/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:41:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2025/02/18 18:48:44 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "template.hpp"

int main() 
{
    int t = 1;
    std::cout << GREEN << "Test case " << t++ << ": int" << RESET_COLOR << std::endl;
    int array[] = {1, 2, 3, 4, 5};
    int size = sizeof(array)/sizeof(array[0]);
    iter(array, size, process);

    std::cout << GREEN << "Test case " << t++ << ": doubles" << RESET_COLOR << std::endl;
    double array_double[] = {1.87, 2.987, 3.90, 4.65, 5.99, 7.033};
    int size_double = sizeof(array_double)/sizeof(array_double[0]);
    iter(array_double, size_double, process);

    std::cout << GREEN << "Test case " << t++ << ": string" << RESET_COLOR << std::endl;
    std::string array_string[] = {"Make ", "dreams ", "come ", "true"};
    int size_string = sizeof(array_string)/sizeof(array_string[0]);
    iter(array_string, size_string, process);

    std::cout << GREEN << "Test case " << t++ << ": bool" << RESET_COLOR << std::endl;
    bool array_bool[] = {true, false, true};
    int size_bool = sizeof(array_bool)/sizeof(array_bool[0]);
    iter(array_bool, size_bool, process);
}