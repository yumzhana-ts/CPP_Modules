/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:16 by ytsyrend          #+#    #+#             */
/*   Updated: 2025/03/20 13:16:32 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.class.hpp"

/****************************************************/
/*                    Constructor                   */
/****************************************************/

Span::Span():N(0), vec()
{
    vec.reserve(N);
    if (DEBUG){ std::cout << GREEN << "[Span] Default Constructor called" << RESET_COLOR << std::endl;}
}

Span::Span(unsigned int size): N(size), vec()
{
    vec.reserve(N);
    if (DEBUG){ std::cout << GREEN << "[Span] Default Parametrized constructor called" << RESET_COLOR << std::endl;}
}

Span::Span(const Span& src) 
{
    if (DEBUG){std::cout << GREEN << "[Span] Copy Constructor called" << RESET_COLOR << std::endl;}
    *this = src;
}

/****************************************************/
/*                    Destructor.                   */
/****************************************************/

Span::~Span(void) 
{
    if (DEBUG){std::cout << GREEN << "[Span] Destructor called" << RESET_COLOR << std::endl;}
}

/****************************************************
*                    Overload                      *
****************************************************/


Span& Span::operator=(const Span& rhs) 
{
    if (DEBUG){std::cout << GREEN << "[Span] Copy assignment operator called" << RESET_COLOR << std::endl;}
    if (this != &rhs)
    {
        this->N = rhs.N;
        this->vec = rhs.vec;
    }
    return (*this);
}

/****************************************************
*                 Memeber Functions                *
****************************************************/

const char* Span::SuperException::what() const throw()
{
    return("Error: At least 2 numbers in vector should be present");
}

void Span::add_number(int num)
{
    try
    {
        if (vec.size() >= this->N)
            throw std::out_of_range("Index out of bounds");
        vec.push_back(num);
    }
    catch (const std::exception &e)
    {
        std::cout << RED << "Error: " << e.what() << RESET_COLOR << std::endl;
    }
}

void Span::add_number(std::vector<int>& vec2)
{
    try
    {
        if (vec.size() >= this->N || (this->N - vec.size()) < vec2.size())
            throw std::out_of_range("Index out of bounds");
        vec.insert(vec.end(), vec2.begin(), vec2.end());
    }
    catch (const std::exception &e)
    {
        std::cout << RED << "Error: " << e.what() << RESET_COLOR << std::endl;
    }
}

void print_num(int num) 
{
    std::cout << num << " ";
}

void Span::print_vector()
{
    std::for_each(vec.begin(), vec.end(), print_num);
    std::cout << std::endl;
    std::cout << "size: " << vec.size() << std::endl;
    std::cout << "last element: " << vec.end() - vec.begin() << std::endl;
}

int Span::shortest_span()
{
    int shortest_span = INT_MAX;
    try
    {
        if (vec.size() <= 1)
            throw SuperException();
        std::sort(vec.begin(), vec.end());
        for(size_t i = 1; i < this->vec.size(); i++)
        {
            int result = vec[i] - vec[i-1];
            shortest_span = std::min(shortest_span, result);
        }
        return (shortest_span);
    }
    catch(Span::SuperException& e)
    {
        std::cout << e.what() << std::endl;
        return (-1);
    }
}

int Span::longest_span()
{
    try
    {
        if (vec.size() <= 1)
            throw SuperException();
        int min_val = *std::min_element(vec.begin(), vec.end());
        int max_val = *std::max_element(vec.begin(), vec.end());
        return(max_val - min_val);
    }
    catch(Span::SuperException& e)
    {
        std::cout << e.what() << std::endl;
        return (-1);
    }
}