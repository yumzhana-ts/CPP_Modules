/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:41:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2025/04/19 22:46:14 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pmerge_me.class.hpp"

//TODO: 1. operator overload for pairs will structure small parts
//TODO: 2. template for comparation of pairs which i guess will be easier when i do overload
//TODO: 3. template for making pairs from single element
//TODO: 4. are templates also has to be recursive? brain explode
//TODO: 5. i have to start from scratch, eat and work


// OurPair::OurPair(int level, std::pair<T,T> pair)
// {
    
// }

std::vector<std::pair<Pmerge_me, Pmerge_me> > start_pair_sorting(std::vector<Pmerge_me> &vec, int &level)
{
    
    std::vector<std::pair<Pmerge_me, Pmerge_me> > output = group_into_pairs(vec);
    //tady potreba ulozit prvni vektor párů;
    OurPair<Pmerge_me> obj(1, output);
    // std::vector<Pair::Pair> crazy_pair;
    
    sort_numbers_level_one(output);

    //rekurze
    
    print_pairs_vector(output);
    print_linked_list(vec);
    level++;
    return (output);
}

// std::vector<std::pair<Pmerge_me, Pmerge_me> >

// std::vector<std::pair<std::pair, Pmerge_me> >


int main(int argc, char **argv)
{
    std::vector<Pmerge_me> vec;
    add_numbers_to_vector(argc, argv, vec);
    link_elements(vec);
    print_linked_list(vec);

    int level = 1;
    start_pair_sorting(vec);

    return 0;
}