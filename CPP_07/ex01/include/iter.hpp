/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2025/02/18 18:39:26 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATE_H
#define TEMPLATE_H

#include <iostream>

template< typename T>
void process(T const &x) 
{
    std::cout << x << std::endl;
}


template< typename T >
void iter(T *array, int size, void(*Func)(T const &))
{
    std::cout << "pointer to array: " << array << std::endl;
    std::cout << "size: " << size << std::endl;
    for(int i = 0; i < size; i++)
    {
        Func(array[i]);
    }
}

template< typename T >
void iter(T *array, int size, void(*Func)(T &))
{
    std::cout << "pointer to array: " << array << std::endl;
    std::cout << "size: " << size << std::endl;
    for(int i = 0; i < size; i++)
    {
        Func(array[i]);
    }
}


#define DEBUG 1
// Define ANSI escape sequences for colors
#define RESET_COLOR "\033[0m"
#define LINE "----------------------------"
#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define BLUE "\033[0;34m"
#define WHITE "\033[0;37m"
#define BOLD_BLACK "\033[1;30m"
#define BG_WHITE "\033[0;47m"
#endif