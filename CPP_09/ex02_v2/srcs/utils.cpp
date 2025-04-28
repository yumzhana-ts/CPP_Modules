/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:16 by ytsyrend          #+#    #+#             */
/*   Updated: 2025/04/15 16:12:48 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pmerge_me.class.hpp"

void ford_johnson(std::vector<int> &vec, t_chains &chains)
{
	debug("1 level of recursion");
	pair_combination(vec, chains);
	print_vec(chains.pair_vector);
	debug("sort pair vector");
	pair_element_sort(chains);
	print_vec(chains.pair_vector);
	//TODO: 2 level of recursion
	debug("2 level of recursion");
	pair_combination_pair(chains.pair_vector, chains);
}

void pair_element_sort(t_chains &chains)
{
	std::vector<std::pair<int,int> >::iterator it = chains.pair_vector.begin();
	for(; it < chains.pair_vector.end(); it++)
	{
		if ((*it).first > (*it).second)
		{
			int temp = (*it).first;
			(*it).first = (*it).second;
			(*it).second = temp;
		}
	}
}

void pair_combination(std::vector<int> &vec, t_chains &chains)
{
    std::vector<int>::iterator it = vec.begin();
    while (it != vec.end())
    {
		std::pair<int,int> super_pair;
        super_pair.first = *it;
        ++it;
        if (it != vec.end())
        {
            super_pair.second = *it;
            ++it;
			chains.pair_vector.push_back(super_pair);
        }
        else
        {
            break;
        }
    }
}

//TODO: must be a template
//TODO: such a crazyyyyyyyyyyyy meeeeeeee
//TODO: i dont know if those vectors has to be saved for futute
//TODO: i dont know what to do with spare element
//TODO: i dont know if i should convert it back to simple vector for input and output of recursions
//TODO: if recursion is doing templates then it has to always process elements
//TODO: i need to write overload for printing and maybe for comparing 

void pair_combination_pair(std::vector<std::pair<int,int> > &vec, t_chains &chains)
{
    std::vector<std::pair<int,int> >::iterator it = vec.begin();
    while (it != vec.end())
    {
        std::pair<std::pair<int, int>, std::pair<int, int> > brain_fuck_pair_vector;
        brain_fuck_pair_vector.first = *it;
        ++it;
        if (it != vec.end())
        {
            brain_fuck_pair_vector.second = *it;
            ++it;
            chains.pair_pair_vector.push_back(brain_fuck_pair_vector);
        }
        else
        {
            break;
        }
    }
}
