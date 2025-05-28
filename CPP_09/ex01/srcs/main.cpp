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

void process_input(char **argv)
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
                super_stack.push(atol(string.c_str()));
            }
            else if ((string[0] == '-' || string[0] == '+' || string[0] == '/' || string[0] == '*'))
            {
                //TODO: supper ugly solution
                //TODO: separate bad input from operations
                //TODO: add check for incorrect values 
                if (super_stack.size() < 2)
                {
                    std::string string2;
                    if (std::getline(ss, string2, ' ') && isdigit(string2[0]))
                    {
                        super_stack.push(atol(string2.c_str()));
                    }
                    else
                    {
                        std::cout << "Error" << std::endl;
                        exit(1);
                    }
                }
                if (super_stack.size() >= 2)
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
                    }                    
                }
            }
        }
    }
    std::cout << result << std::endl;
}


int main(int argc, char **argv)
{
    if (argc == 2)
    {
        process_input(argv);
    }
    else
    {
        std::cout << RED << "Error" << RESET_COLOR << std::endl;
    }
    return (0);
}