/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:16 by ytsyrend          #+#    #+#             */
/*   Updated: 2025/04/18 22:33:39 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pmerge_me.class.hpp"

void sort_numbers_level_one(std::vector<std::pair<Pmerge_me, Pmerge_me> > &output)
{
    std::vector<std::pair<Pmerge_me, Pmerge_me> >::iterator it = output.begin();
    for (; it != output.end(); ++it)
    {
        if (it->first.get_number() > it->second.get_number())
        {
            std::swap(it->first, it->second);
			std::iter_swap(it->first.get_position(), it->second.get_position());
        }
    }
}

void add_numbers_to_vector(int argc, char **argv, std::vector<Pmerge_me>& vec)
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
                vec.push_back(Pmerge_me(num));
            }
        }
    }
    else
    {
        std::cout << RED << "Error: Invalid input" << RESET_COLOR << std::endl;
    }
}

void link_elements(std::vector<Pmerge_me>& vec)
{
    for (size_t i = 0; i < vec.size(); ++i)
    {
        if (i > 0)
        {
            vec[i].set_position(vec.begin() + i);
        }

        if (i < vec.size() - 1)
        {
            vec[i].set_position(vec.begin() + i);
        }
    }
}

void print_linked_list(const std::vector<Pmerge_me>& vec)
{
	std::cout << RED << "original vector " << RESET_COLOR;
    for (size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i].get_number();
        if (i < vec.size() - 1) 
        {
            std::cout << " -> ";
        }
    }
    std::cout <<  std::endl;
}