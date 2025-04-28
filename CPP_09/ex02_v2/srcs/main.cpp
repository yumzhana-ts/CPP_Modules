/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:41:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2025/04/15 16:21:45 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pmerge_me.class.hpp"

//TODO: 1. operator overload for pairs will structure small parts
//TODO: 2. template for comparation of pairs which i guess will be easier when i do overload
//TODO: 3. template for making pairs from single element
//TODO: 4. are templates also has to be recursive? brain explode
//TODO: 5. i have to start from scratch, eat and work
int main(int argc, char **argv)
{
    if (argc == 2)
    {
        std::string string;
        std::stringstream ss(argv[1]);
        std::vector<int> vec;
        t_chains chains;
        chains.main_chain.reserve(chains.pair_vector.size());
        chains.insert_chain.reserve(chains.pair_vector.size());
        while (std::getline(ss, string, ' '))
        {
            int num = std::atol(string.c_str());
            if (num >= 0 && num < INT_MAX)
            {
                vec.push_back(num);
            }
        }
        if (vec.size() > 1)
        {
            print_vec(vec);
            ford_johnson(vec, chains);
        }
    }
    else
    {
        std::cout << RED << "Error" << RESET_COLOR << std::endl;
    }
    return (0);
}