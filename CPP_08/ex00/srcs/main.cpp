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

#include "easyfind.hpp"

int main() 
{
    int t = 1;
    int array[] = {1, 2, 3, 4, 5};
    int size = sizeof(array)/sizeof(array[0]);


    std::cout << "Test case " << t++ << ": finding an element in list " << RESET_COLOR << std::endl;
    std::list<int> lst(array, array + size);
    try
    {
        easyfind(lst, 1);
    }
    catch(const std::runtime_error& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "Test case " << t++ << ": finding an element in vector " << RESET_COLOR << std::endl;
    std::vector<int> vec(array, array + size);
    try
    {
        easyfind(vec, 1);
    }
    catch(const std::runtime_error& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "Test case " << t++ << ": finding an element in deque " << RESET_COLOR << std::endl;
    std::deque<int> dq(array, array + size);
    try
    {
        easyfind(dq, 100);
    }
    catch(const std::runtime_error& e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}