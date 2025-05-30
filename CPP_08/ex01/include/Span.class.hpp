/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2025/03/20 13:20:52 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_CLASS_H
#define SPAN_CLASS_H

#include <iostream>
#include <algorithm>
#include <vector>


class Span
{
private:
    unsigned int N;
    std::vector<int> vec;
    Span();
public:
    Span(unsigned int size);
    ~Span(void);
    Span(const Span& other);
    Span& operator=(const Span& other);

    int get_N(void) const {return (this->N);}
    void add_number(int num);
    int shortest_span();
    int longest_span();
    void print_vector();
    void add_number(std::vector<int> &vec2);

    class SuperException: public std::exception
    {
    public:
        const char* what() const throw();
    };
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
#endif