/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:16 by ytsyrend          #+#    #+#             */
/*   Updated: 2025/05/29 13:28:21 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.class.hpp"

/****************************************************/
/*                    Constructor                   */
/****************************************************/

RPN::RPN(std::stack<int> ss): super_stack(ss)
{
    if (DEBUG){ std::cout << GREEN << "[RPN] Default Constructor called" << RESET_COLOR << std::endl;}
}
//RPN(std::string n = "Unkown"): name(n)

RPN::RPN(const RPN& src) : super_stack(src.super_stack)
{
    if (DEBUG){std::cout << GREEN << "[RPN] Copy Constructor called" << RESET_COLOR << std::endl;}
    //*this = src;
}

/****************************************************/
/*                    Destructor.                   */
/****************************************************/

RPN::~RPN(void) 
{
    if (DEBUG){std::cout << GREEN << "[RPN] Destructor called" << RESET_COLOR << std::endl;}
}

/****************************************************
*                    Overload                      *
****************************************************/


RPN& RPN::operator=(const RPN& rhs) 
{
    if (DEBUG){std::cout << GREEN << "[RPN] Copy assignment operator called" << std::endl;}
    if (this != &rhs)
    {
        this->super_stack = rhs.super_stack;
    }
    return (*this);
}

/****************************************************
*                 Memeber Functions                *
****************************************************/


void test()
{
    std::stack<int> super_stack;
    RPN obj1(super_stack); // Default Constructor called
    RPN obj2(obj1);        // Copy Constructor called
    RPN obj3(super_stack);
    obj3 = obj2; // Copy Assignment Operator called
}

int arithmetic_operation(char op, int num_1, int num_2)
{
    if (DEBUG)
    {
        std::cout << GREEN << "[DEBUG] processing operation: ";
        std::cout <<  num_1 << op << num_2 << RESET_COLOR << std::endl;
    }
    int result;
    switch (op)
    {
        case '-':
            result = num_1 - num_2;
            break;
        case '+':
            result = num_1 + num_2;
            break;
        case '/':
            if (num_2 == 0)
                throw std::runtime_error("Error: Division by zero");
            result = num_1 / num_2;
            break;
        case '*':
            result = num_1 * num_2;
            break;
    }
    return (result);
}

bool is_operation(char string)
{
    if(string == '-' || string == '+' || string == '/' || string == '*')
        return true;
    return false;
}

void process_operations(std::stack<int> &super_stack, std::string &string, int &result)
{
    if (super_stack.size() < 2)
        throw std::runtime_error("Error");
    int num_1 = super_stack.top();
    super_stack.pop();

    int num_2 = super_stack.top();
    super_stack.pop();

    result = arithmetic_operation(string[0], num_2, num_1);
    super_stack.push(result);
}