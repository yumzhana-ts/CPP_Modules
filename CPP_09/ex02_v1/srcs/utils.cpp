/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:16 by ytsyrend          #+#    #+#             */
/*   Updated: 2025/05/05 17:34:31 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pmerge_me.class.hpp"

void combine_to_pairs(std::vector<Pmerge_me> &vec, std::vector<std::pair<Pmerge_me, Pmerge_me> > &pair_vector)
{
    std::vector<Pmerge_me>::iterator it = vec.begin();
    while (it != vec.end())
    {
        int first_num = it->get_number();
        ++it;

        int second_num;
        if (it != vec.end())
        {
            second_num = it->get_number();
            ++it;
        }
        else
        {
            second_num = -1;
        }
        pair_vector.push_back(std::make_pair(Pmerge_me(first_num), Pmerge_me(second_num)));
    }
}

bool compare_by_first(Pmerge_me &ob_1, Pmerge_me &ob_2)
{
	return ob_1.get_number() < ob_2.get_number();
}

void chain_split(std::vector<Pmerge_me> &main_chain, std::vector<Pmerge_me> &insert_chain, std::vector<std::pair<Pmerge_me, Pmerge_me> > &pair_vector)
{
    for (std::vector<std::pair<Pmerge_me, Pmerge_me> >::iterator it = pair_vector.begin(); it != pair_vector.end(); ++it)
    {
        if (it->first.get_number() > it->second.get_number())
        {
            main_chain.push_back(it->first);
            insert_chain.push_back(it->second);
        }
        else
        {
            main_chain.push_back(it->second);
            insert_chain.push_back(it->first);
        }
    }
}

void save_it(std::vector<Pmerge_me> &main_chain, std::vector<Pmerge_me> &insert_chain)
{
    if (main_chain.size() != insert_chain.size())
    {
        std::cerr << "Chains must be of equal size!\n";
        return;
    }

    std::vector<Pmerge_me>::iterator main_it = main_chain.begin();
    std::vector<Pmerge_me>::iterator insert_it = insert_chain.begin();

    while (main_it != main_chain.end())
    {
        main_it->set_it(insert_it);
        ++main_it;
        ++insert_it;
    }
}

void save_it(t_chains &chains)
{
    save_it(chains.main_chain, chains.insert_chain);
    save_it(chains.insert_chain, chains.main_chain);
}

void print_ob_vec(const std::vector<Pmerge_me> vec)
{
    for (std::vector<Pmerge_me>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        std::cout << *it;
        std::vector<Pmerge_me>::iterator stored = it->get_iterator();
        std::cout << " [" << *stored << "] ";
    }
    std::cout << std::endl;
}


void insert(std::vector<Pmerge_me> &main_chain, int position_to_insert, std::vector<Pmerge_me> &insert_chain, int position_from_insert)
{
	std::vector<Pmerge_me>::iterator it_main = main_chain.begin() + position_to_insert;
	std::vector<Pmerge_me>::iterator it_insert = insert_chain.begin() + position_from_insert;
	//if ((*it_insert).get_number() >= 0)
	main_chain.insert(it_main, *it_insert);
}

int insert_position(t_chains &chains, int insert_index, int start, int end, int &comparison_count)
{
    if (DEBUG == 2){std::cout << GREEN << "Comparing " << chains.insert_chain[insert_index] << " from position " << start << " until " << end  << RESET_COLOR << std::endl;}

    if (start >= end)
    {
        if (DEBUG == 2){std::cout << GREEN << "Found position: " << start << RESET_COLOR << std::endl;}
        return start;
    }
    comparison_count++;
    int mid = (start + end) / 2;
    int insert_num = chains.insert_chain[insert_index].get_number();
    int mid_num = chains.main_chain[mid].get_number();

    if (DEBUG == 2){ std::cout << GREEN << "Checking: if " << insert_num << " is equal to " << mid_num << RESET_COLOR << std::endl;}

    if (insert_num == mid_num)
    {
        if (DEBUG == 2){std::cout << GREEN << "Exact match at position " << mid << RESET_COLOR << std::endl;}
        return mid;
    }
    else if (insert_num > mid_num)
    {
        if (DEBUG == 2){std::cout << BLUE << "Going right: from " << mid + 1 << " to " << end << RESET_COLOR << std::endl;}
        return insert_position(chains, insert_index, mid + 1, end, comparison_count);
    }
    else
    {
        if (DEBUG == 2){std::cout << BLUE << "Going left: from " << start << " to " << mid << RESET_COLOR << std::endl;}
        return insert_position(chains, insert_index, start, mid, comparison_count);
    }
}

void binary_insertion(t_chains &chains, int main_position)
{
    if (DEBUG == 2){std::cout << BLUE << " ---- Binary insertion of index: " << main_position << " ---- "  << RESET_COLOR << std::endl;}

    if (DEBUG == 2){std::cout << "Step 1: Take pair ";}
    int insert_index = chains.main_chain[main_position].get_pair_index(chains.insert_chain);
    if (DEBUG == 2){std::cout << "on index: " << insert_index << std::endl;}

    if (DEBUG == 2){std::cout << "Step 2: Find position using binary search\n" << RESET_COLOR;}
    int comparison_count = 0;
    int position_to_insert = insert_position(chains, insert_index, 0, main_position, comparison_count);
    if (DEBUG == 2){std::cout << "Total comparisons: " << comparison_count << " | Numbers to compare " << main_position<< std::endl;}
    
    if (DEBUG == 2){std::cout << "Step 3: Inserting at position " << position_to_insert << std::endl;}
    insert(chains.main_chain, position_to_insert, chains.insert_chain, insert_index);
}


//TODO: instead of making pairs we have to somehow still devide, but not combine into pairs 
//TODO: police appitment 
void recursive_process_steps(std::vector<Pmerge_me> &vec, t_chains &chains)
{
    if (DEBUG == 2){std::cout << BLUE << "Step 1. saving numbers to vector" << RESET_COLOR << std::endl;}
	//divide by half 
    if (DEBUG == 2){ std::cout << BLUE << "Step 3. make main chain and insert chain" << RESET_COLOR << std::endl;}
    chain_split(chains.main_chain, chains.insert_chain, chains.pair_vector);
    //save_it(chains);
	
    print_ob_vec(chains.main_chain);
    print_ob_vec(chains.insert_chain);
}