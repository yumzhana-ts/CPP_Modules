/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pmerge_me.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:16 by ytsyrend          #+#    #+#             */
/*   Updated: 2025/06/02 14:22:13 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pmerge_me.class.hpp"

/****************************************************/
/*             Math things                          */
/****************************************************/

int recursion_levels(int n) 
{
    if (n <= 1) 
        return 0;
    return (std::floor(log2(n)));
}

std::vector<t_level_info> get_usage_up_to_max_level(int total)
{
    std::vector<t_level_info> usage_info;
    int current = total;
    int level = recursion_levels(total);
    current = total;

    for (int i = 0; i < level; ++i)
    {
        int pairs = current / 2;
        int numbers_in_pair = 2 << i;
        int used = pairs * numbers_in_pair;
        int rest = (current % 2) * (numbers_in_pair / 2);

        t_level_info p(used, rest, pairs, numbers_in_pair);
        usage_info.push_back(p);
        current = pairs;
    }

    return usage_info;
}


bool is_valid_number(const std::string& s)
{
    if (s.empty()) return false;

    for (size_t i = 0; i < s.size(); ++i)
    {
        if (!std::isdigit(s[i]))
            return false;
    }
    return true;
}

void error_and_exit(const std::string& msg)
{
    std::cerr << RED << msg << RESET_COLOR << std::endl;
    std::exit(1);
}

int convert_to_int(const std::string& s)
{
    long num = atol(s.c_str());
    if (num < 0 || num > INT_MAX)
    {
        std::string msg = std::string("Error: Number out of range '") + s + "'";
        error_and_exit(msg);
    }
    return static_cast<int>(num);
}

/****************************************************/
/*             Different debug functions            */
/****************************************************/


void print_usage_info(const std::vector<t_level_info> &usage_info, int total)
{
    int level = recursion_levels(total);
    int total_width = 54; 

    std::string border = "+" + std::string(total_width, '-') + "+";
    std::cout << GREEN << border << "\n";
    std::cout << "| " << std::left << std::setw(total_width) 
        << "Initial number of elements: " << total << "|\n";
    std::cout << "| " << std::left << std::setw(total_width) 
        << "Total recursion: " << level << "|\n";
    std::cout << border << "\n";

    std::cout << "| " << std::left
        << std::setw(7) << "Level"
        << std::setw(9) << "Pairs"
        << std::setw(19) << "Numbers in Pairs"
        << std::setw(9) << "Used"
        << std::setw(10) << "Leftover"
        << "|\n";
    std::cout << "|" << total_width << "|\n";
    for (size_t i = 0; i < usage_info.size(); ++i)
    {
        const t_level_info &level_info = usage_info[i];
        std::cout << "| " << std::left
            << std::setw(7) << (i + 1)
            << std::setw(9) << level_info.pairs
            << std::setw(19) << level_info.numbers_in_pair
            << std::setw(9) << level_info.used
            << std::setw(10) << level_info.rest
            << "|\n";
    }
    std::cout << border << "\n";
    int leftovers = 0;
    for (size_t i = 0; i < usage_info.size(); ++i)
    {
        leftovers += usage_info[i].rest;
    }
    std::cout << "| " << std::left << std::setw(total_width)
        << "Total number of leftovers: " << leftovers  << "|\n";
    std::cout << border << "\n";
    std::cout << "\n" << RESET_COLOR <<  std::endl;
}

int F(int n)
{
    int sum = 0;
    for (int k = 1; k <= n; ++k) {
        double value = (3.0 / 4.0) * k;
        sum += static_cast<int>(ceil(log2(value)));
    }
    return sum;
}
