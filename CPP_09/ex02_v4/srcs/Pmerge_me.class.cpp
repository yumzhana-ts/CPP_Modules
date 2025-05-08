/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pmerge_me.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:16 by ytsyrend          #+#    #+#             */
/*   Updated: 2025/05/08 02:28:44 by ytsyrend         ###   ########.fr       */
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
    return (std::ceil(std::log2(n)) - 1);
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
    int total_width = 54;  // ширина таблицы, можно подогнать под нужные значения

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
    std::cout << name << ": [";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i];
        if (i != vec.size() - 1) std::cout << ", ";
    }
    std::cout << "]\n";
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
    //vec.leftovers.clear();
    //pretty_print(vec);
}

/****************************************************/
/*                Functions to save numbers         */
/****************************************************/

void parse_and_store_numbers(int argc, char **argv, t_original_vector &vec)
{
    add_numbers_to_vector(argc, argv, vec.original_vector);
    vec.total = vec.original_vector.size();
    vec.info = get_usage_up_to_max_level(vec.total);
    print_usage_info(vec.info, vec.total);
}


void add_numbers_to_vector(int argc, char **argv, std::vector<int>& vec)
{
    if (argc == 2)
    {
        std::string string;
        std::stringstream ss(argv[1]);

        while (std::getline(ss, string, ' '))
        {
            int num = std::atol(string.c_str());
            if (num >= 0 && num < INT_MAX)
            {
                vec.push_back(int(num));
            }
        }
    }
    else
    {
        std::cout << RED << "Error: Invalid input" << RESET_COLOR << std::endl;
    }
}

/****************************************************/
/*         Functions to make and sort pairs         */
/****************************************************/

void meta_recursive(t_original_vector &vec)
{
    enum { MAX_RECURSION_DEPTH = 4};
    enum { TARGET_UNWRAP_LEVEL = 1};
    if (vec.original_vector.size() <= 1) 
    {
        std::cout << "Vector size is less then one" << std::endl;
        return;
    }

    typedef PairN<MAX_RECURSION_DEPTH>::type FinalPairType;
    typedef std::vector<FinalPairType> FinalVectorType;

    //typedef PairN<2>::type MidPairType;
    //typedef std::vector<MidPairType> MidVectorType;
    
    std::cout << BLUE << LINE << "wrapping numbers" << LINE <<  RESET_COLOR << std::endl;
    FinalVectorType final_result = ConstructLevels<0, MAX_RECURSION_DEPTH>::run(vec.original_vector, true, vec);
    std::cout << BLUE << "\n "<< LINE << "vector after sorting" << LINE <<  RESET_COLOR << std::endl;
    print_linked_list(vec.original_vector);
    std::cout << BLUE << "\n "<< LINE <<  "unwrapping numbers" << LINE <<  RESET_COLOR << std::endl;
    typedef PairN<TARGET_UNWRAP_LEVEL>::type UnwrappedElementType; // Это PmergeMe::SingleNumber
    typedef std::vector<UnwrappedElementType> UnwrappedVectorType;

    UnwrappedVectorType unwrapped_vec = RecursiveUnwrapper<MAX_RECURSION_DEPTH, TARGET_UNWRAP_LEVEL>::run(final_result, vec);
}

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

