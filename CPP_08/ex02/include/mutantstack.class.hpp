/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.class.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2025/03/27 23:42:43 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANSTACK_CLASS_H
#define MUTANSTACK_CLASS_H

#include <iostream>
#include <stack>

template <typename T>
class MutantStack: public std::stack<T>
{
private:
public:
    MutantStack(void);
    ~MutantStack(void);
    MutantStack(const MutantStack& other);
    MutantStack& operator=(const MutantStack& other);
    
    typedef typename std::deque<T>::iterator iterator;
    typename std::deque<T>::iterator begin() { return this->c.begin(); }
    typename std::deque<T>::iterator end() { return this->c.end(); }
};

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
#include "../srcs/mutantstack.class.tpp" 
#endif