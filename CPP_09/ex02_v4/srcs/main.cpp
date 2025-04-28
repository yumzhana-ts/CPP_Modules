/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:41:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2025/04/28 21:16:09 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Pmerge_me.class.hpp"



void recursive_group_start(std::vector<PmergeMe::SingleNumber> vec)
{
    std::vector<PairN<1>::type> new_vec = group_into_pairs<0>(vec);
    std::vector<PairN<2>::type> new_vec1 = group_into_pairs<1>(new_vec);
    std::vector<PairN<3>::type> new_vec2 = group_into_pairs<2>(new_vec1);
    std::vector<PairN<4>::type> new_vec3 = group_into_pairs<3>(new_vec2);
    std::vector<PairN<5>::type> new_vec4 = group_into_pairs<4>(new_vec3);
}




int main(int argc, char **argv)
{
    std::vector<PmergeMe::SingleNumber> vec;
    save_numbers_to_vector(argc, argv, vec);
    //recursive_group_start(vec);
    recursive_group<0>(vec);
    return 0;
}
