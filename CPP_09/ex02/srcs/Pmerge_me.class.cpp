/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pmerge_me.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:16 by ytsyrend          #+#    #+#             */
/*   Updated: 2025/05/15 13:17:45 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pmerge_me.class.hpp"



/****************************************************/
/*           Functions to save level inf            */
/****************************************************/

int recursion_levels(int n) 
{
    if (n <= 1) 
        return 0;
    return (std::floor(std::log2(n)));
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


void print_usage_info(const std::vector<t_level_info> &usage_info, int total)
{
    int level = recursion_levels(total);
    int total_width = 54; 

    std::string border = "+" + std::string(total_width, '-') + "+";
    std::cout << border << "\n";
    std::cout << "| " << std::left << std::setw(total_width) 
              << ("Initial number of elements: " + std::to_string(total)) << "|\n";
    std::cout << "| " << std::left << std::setw(total_width) 
              << ("Total recursion: " + std::to_string(level)) << "|\n";
    std::cout << border << "\n";

    std::cout << "| " << std::left
              << std::setw(7) << "Level"
              << std::setw(9) << "Pairs"
              << std::setw(19) << "Numbers in Pairs"
              << std::setw(9) << "Used"
              << std::setw(10) << "Leftover"
              << "|\n";

    std::cout << "|" << std::string(total_width, '-') << "|\n";

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
              << ("Total number of leftovers: " + std::to_string(leftovers)) << "|\n";
    std::cout << border << "\n";
    std::cout << "\n" << std::endl;
}

/****************************************************/
/*                Utils                             */
/****************************************************/

void print_linked_list(const std::vector<int>& vec)
{
	std::cout << RED << "original vector " << RESET_COLOR;
    for (size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i];
        if (i < vec.size() - 1) 
        {
            std::cout << " -> ";
        }
    }
    std::cout <<  std::endl;
}

void print_vector(const std::string& name, const std::vector<int>& vec) 
{
    std::cout << name << ": ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i];
        if (i != vec.size() - 1) std::cout << ", ";
    }
    std::cout << "\n";
}



void pretty_print(const t_original_vector& data) 
{
    std::cout << "----- t_original_vector -----\n";
    print_vector("Original", data.original_vector);
    print_vector("Used", data.used);
    print_vector("Leftovers", data.leftovers);
    std::cout << "-----------------------------\n";
}

void restore_original_vector(t_original_vector& vec)
{
    vec.original_vector.clear();
    vec.original_vector.insert(vec.original_vector.begin(), vec.leftovers.begin(), vec.leftovers.end());
    vec.original_vector.insert(vec.original_vector.begin(), vec.used.begin(), vec.used.end());
    vec.used.clear();
}

/****************************************************/
/*                Functions to save numbers         */
/****************************************************/

void parse_and_store_numbers(int argc, char **argv, t_original_vector &vec)
{
    add_numbers_to_vector(argc, argv, vec.original_vector);
    vec.total = vec.original_vector.size();
    vec.info = get_usage_up_to_max_level(vec.total);
    vec.total_comparisons = 0;
    if (DEBUG == 3) {print_usage_info(vec.info, vec.total);}
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

void add_numbers_to_vector(int argc, char **argv, std::vector<int>& vec)
{
    if (argc == 2)
    {
        std::string string;
        std::stringstream ss(argv[1]);

        while (std::getline(ss, string, ' '))
        {
            if (string.empty())
                continue;

            if (!is_valid_number(string))
            {
                std::cerr << RED << "Error: Invalid input '" << string << "'" << RESET_COLOR << std::endl;
                exit(1);
            }

            long num = std::atol(string.c_str());
            if (num < 0 || num > INT_MAX)
            {
                std::cerr << RED << "Error: Number out of range '" << string << "'" << RESET_COLOR << std::endl;
                exit(1);
            }
            vec.push_back(static_cast<int>(num));
        }
        if (vec.size() <= 1)
        {
            std::cout << vec[0] << std::endl;
            exit(0);          
        }
    }
    else
    {
        std::cerr << RED << "Error: Invalid number of arguments" << RESET_COLOR << std::endl;
        exit(1);
    }
}


/****************************************************/
/*         Functions to make and sort pairs         */
/****************************************************/


void save_rest_to_vector(std::vector<t_level_info> levels, std::vector<int> &vec, std::vector<int> &rest, int level)
{
    size_t leftovers = levels[level-1].rest;
    if (leftovers > 0 && leftovers <= vec.size())
    {
        std::vector<int> slice(vec.end() - leftovers, vec.end());
        rest.insert(rest.begin(), slice.begin(), slice.end());
        vec.erase(vec.end() - leftovers, vec.end());
    }
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

