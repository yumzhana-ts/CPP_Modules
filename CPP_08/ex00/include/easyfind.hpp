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

#ifndef EASYFIND_H
#define EASYFIND_H
#define RESET_COLOR "\033[0m"
#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define BLUE "\033[0;34m"
#define WHITE "\033[0;37m"
#define BOLD_BLACK "\033[1;30m"
#define BG_WHITE "\033[0;47m"

#include <iostream>
#include <algorithm>
#include <list> 
#include <stdexcept>
#include <vector>
#include <deque>

template <typename T>
void easyfind(const T& x, int n) 
{  
    if (std::find(x.begin(), x.end(), n) == x.end())
        throw std::runtime_error(RED"Element not found");
    else
        std::cout << GREEN <<"Found element" << RESET_COLOR << std::endl;
}


#define DEBUG 1
#endif