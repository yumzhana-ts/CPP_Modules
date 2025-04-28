/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:41:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2025/04/02 21:18:53 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.class.hpp"

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
    std::cout << GREEN << "[DEBUG] processing operation: ";
    std::cout <<  num_1 << op << num_2 << RESET_COLOR << std::endl;
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
            {
                throw std::runtime_error("Error: Division by zero");
            }
            result = num_1 / num_2;
            break;
        case '*':
            result = num_1 * num_2;
            break;
    }
    return (result);
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        std::stack<int> super_stack;
        std::string string;
        std::stringstream ss(argv[1]);
        int result = 0;
        while (std::getline(ss, string, ' '))
        {
            if (string.size() == 1)
            {
                if (isdigit(string[0]))
                {
                    super_stack.push(std::atol(string.c_str()));
                }
                else if ((string[0] == '-' || string[0] == '+' || string[0] == '/' || string[0] == '*') && super_stack.size() >= 2)
                {
                    try
                    {
                        int num_1 = super_stack.top();
                        super_stack.pop();
                        int num_2 = super_stack.top();
                        super_stack.pop();            
                        result = arithmetic_operation(string[0], num_2, num_1);
                        super_stack.push(result);
                    }
                    catch(std::exception& e)
                    {
                        std::cout << e.what() << std::endl;
                        return(1);
                    }
                }
            }
            else
            {
                std::cout << RED << "Error" << RESET_COLOR << std::endl;
                return (1);
            }
        }
        std::cout  << result  << std::endl;
    }
    else
    {
        std::cout << RED << "Error" << RESET_COLOR << std::endl;
    }
    return (0);
}