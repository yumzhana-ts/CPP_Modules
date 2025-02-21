/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2025/02/18 20:51:11 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_CLASS_H
#define ARRAY_CLASS_H
#define DEBUG 1
#define RESET_COLOR "\033[0m"
#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define BLUE "\033[0;34m"
#define WHITE "\033[0;37m"
#define BOLD_BLACK "\033[1;30m"
#define BG_WHITE "\033[0;47m"
#define BOLD    "\033[1m"
#define UNDERL  "\033[4m"
#define BG_DARK_GRAY  "\033[48;5;236m"
#define LINE "--------------------------------------"
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <cstdlib>

template <typename T>
class Array
{
private:
    T *my_array;
    unsigned int n;
public:
    Array(void);
    Array(unsigned int n);
    ~Array();
    Array(const Array& other);
    Array& operator=(const Array& other);
    unsigned int size(void) const {return (this->n);}
    T get_element(unsigned int n_element);
    void nice_testing(unsigned int n_element);
};


#endif