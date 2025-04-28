/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:41:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2025/04/10 11:09:12 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pmerge_me.class.hpp"

void orth_test()
{
    /*unsigned int p = 3;
    Pmerge_me obj1(p);
    Pmerge_me obj2(obj1);
    Pmerge_me obj3(p);
    obj3 = obj2;*/
}

void process_steps(std::vector<Pmerge_me> &vec, t_chains &chains)
{
    if (DEBUG == 2){std::cout << BLUE << "Step 1. saving numbers to vector" << RESET_COLOR << std::endl;}
    print_vec(vec);

    if (DEBUG == 2){std::cout << BLUE << "Step 2. making pairs" << RESET_COLOR << std::endl;}
    combine_to_pairs(vec, chains.pair_vector);
    print_vec(chains.pair_vector);

    if (DEBUG == 2){ std::cout << BLUE << "Step 3. make main chain and insert chain" << RESET_COLOR << std::endl;}
    chain_split(chains.main_chain, chains.insert_chain, chains.pair_vector);
    save_it(chains);

    print_ob_vec(chains.main_chain);
    print_ob_vec(chains.insert_chain);
}

int index_jacobstahl(t_chains &chains)
{
    return(chains.jacobstahl_number_last * 2 + chains.jacobstahl_number);
}


void jacobstahl_sequence(t_chains &chains)
{
    std::cout << BLUE << "Jacobstahl sequence:\n" << RESET_COLOR;
    for (size_t i = 0; i < chains.pair_vector.size() * 2; i=i+2)
    {
        //std::cout << "---------Processing index: " << i << " -----------" << std::endl;
        binary_insertion(chains, i);
        std::cout << "Updated main chain: ";
        print_vec(chains.main_chain);
    }
}

//TODO: when calling function recursively i have sorted main chain, sp i need to create insert chain from half of it
void ford_johnson(std::vector<Pmerge_me> &vec, t_chains &chains)
{
    if(vec.size() <= 1)
        return;
    
    //std::cout << BLUE << "Step 4. first sort and insert" << RESET_COLOR << std::endl;
    //std::sort(chains.main_chain.begin(), chains.main_chain.end(), compare_by_first);
    
    ford_johnson(chains.main_chain, chains);
    std::cout << BLUE << "Sorted pairs: \n" << RESET_COLOR;
    print_ob_vec(chains.main_chain);
    jacobstahl_sequence(chains);
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        std::string string;
        std::stringstream ss(argv[1]);
        std::vector<Pmerge_me> vec;
        t_chains chains;
        chains.jacobstahl_number = 1;
        chains.jacobstahl_number_last = 1;
        chains.main_chain.reserve(chains.pair_vector.size());
        chains.insert_chain.reserve(chains.pair_vector.size());
        while (std::getline(ss, string, ' '))
        {
            int num = std::atol(string.c_str());
            if (num >= 0 && num < INT_MAX)
            {
                vec.push_back(Pmerge_me(num));
            }
        }
        process_steps(vec, chains);
        ford_johnson(vec, chains);
    }
    else
    {
        std::cout << RED << "Error" << RESET_COLOR << std::endl;
    }
    return (0);
}