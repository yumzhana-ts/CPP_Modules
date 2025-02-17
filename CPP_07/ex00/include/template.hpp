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

#ifndef TEMPLATE_H
#define TEMPLATE_H

#include <iostream>
#define c_max(x, y) (((x)>=(y)) ? (x) : (y))

int foo(int x){return x;}

template< typename T >
void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template< typename T >
T const & min(T const &a, T const &b)
{
    return (a >= b) ? b : a; 
}

template< typename T >
T const & max(T const  &a, T const  &b)
{
   return (a <= b) ? b : a; 
}

template< typename T >
void print_swapped(T const  &a, T const  &b, T const  &max, T const  &min)
{
    std::cout <<  "Swapped values: a=" << a << ", b=" << b << std::endl;
    std::cout << "Min: " << min << " Max: " << max << std::endl;  
}

template< typename T >
void print_init(T const  &a, T const  &b)
{
    std::cout <<  "Input values: a=" << a << ", b=" << b << std::endl;
}

template< typename T >
void nice_testing(T &a, T &b)
{
    ::print_init(a, b);
    ::swap(a, b);
    ::print_swapped(a, b, ::max(a,b), ::min(a,b));
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