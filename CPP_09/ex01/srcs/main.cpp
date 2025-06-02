/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:41:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2025/05/30 11:31:28 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.class.hpp"

bool is_allowed_char(char c)
{
    if (std::isdigit(c) || std::isspace(c) || c == '+' || c == '-' || c == '*' || c == '/')
        return true;
    return false;
}

void validate_input(const std::stringstream &ss)
{
    std::string raw = ss.str();
    for (size_t i = 0; i < raw.size(); ++i)
    {
        if (!is_allowed_char(raw[i]) || (isdigit(raw[i]) && isdigit(raw[i+1])) || raw.size() == 1)
            throw std::logic_error("Invalid character in input.");
    }
}

int process_input(std::stringstream &ss)
{
    std::stack<int> super_stack;
    std::string string;
    int result = 0;
    validate_input(ss);
    while (std::getline(ss, string, ' '))
    {
        if (isdigit(string[0]))
            super_stack.push(atol(string.c_str()));
        else if (is_operation(string[0]))
            process_operations(super_stack, string, result);
    }
    if (super_stack.size() != 1)
        throw std::logic_error("Error");
    return result;
}


int main(int argc, char **argv)
{
    if (argc == 2)
    {
        try
        {
            std::stringstream ss(argv[1]);
            int result = process_input(ss);
            std::cout << result << std::endl;
        }
        catch (const std::exception&)
        {
            std::cerr << "Error" << std::endl;
        }
    }
    else
    {
        std::cerr << "Error" << std::endl;
    }
    return (0);
}