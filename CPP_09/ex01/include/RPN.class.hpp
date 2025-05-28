/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2025/04/02 21:17:51 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPNLASS_H
#define RPNLASS_H

#include <iostream>
#include <stack>
#include <fstream>
#include <sstream>
#include <cctype>
#include <stdlib.h>

class RPN
{
private:
    std::stack<int> super_stack;
    RPN(void);
public:
    RPN(std::stack<int> ss);
    ~RPN(void);
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
};

int arithmetic_operation(char op, int num_1, int num_2);
void test();

#define DEBUG 1
// Define ANSI escape sequences for colors
#define RESET_COLOR "\033[0m"
#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define BLUE "\033[0;34m"
#define WHITE "\033[0;37m"
#define BOLD_BLACK "\033[1;30m"
#define BG_WHITE "\033[0;47m"
#endif