/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:41:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2025/06/02 14:34:29 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Pmerge_me.class.hpp"

template <template <typename> class container_wrapper>
bool is_sorted(typename container_wrapper<int>::type& vec, size_t original_size) 
{
    for (size_t i = 1; i < vec.size(); ++i) 
    {
        if (vec[i - 1] > vec[i]) 
        {
            std::cout << "⛔️ Not sorted at index " << i - 1 << " and " << i << "!\n";
            return false;
        }
    }
    if(vec.size() == original_size)
        std::cout << "✅ Conatiner has same size and is sorted!\n";
    return true;
}


template <template <typename> class Container_wrapper>
void process_container(int argc, char **argv, bool print = false)
{
    typedef typename Container_wrapper<int>::type ContainerType;
    t_data<ContainerType> container;
    setup_container<Container_wrapper>(argc, argv, container);
    if (print == true)
    {
        std::cout << "before:  ";
        print_vector<int, Container_wrapper>(container.original_container);
    }
    size_t original_size = container.original_container.size();

    clock_t start_vector = clock();
    dispatcher<Container_wrapper>(container);
    clock_t end_vector = clock();
    double duration_vector = double(end_vector - start_vector) / CLOCKS_PER_SEC;
    if (print == true)
    {
        std::cout << "after:   ";
        print_vector<int, Container_wrapper>(container.used);
        if (SUPER_DEBUG)
        {
            is_sorted<Container_wrapper>(container.used, original_size);
            if (container.total_comparisons < F(container.total))
            {
                std::cout << "✅ Number of comparisons less then expected!" <<
                "(Total comparisons: " << container.total_comparisons << " | ";
                std::cout << "Max allowed F(" << container.total << ") = " << F(container.total) << ")" << std::endl;
            }
        }
    }
    std::cout << "Time to process a range of " << original_size << 
    " elements with std::" << Container_wrapper<int>::name()<< " : " << std::fixed << std::setprecision(5) << duration_vector << " us\n";
}


int main(int argc, char **argv)
{
    process_container<VectorWrapper>(argc, argv, true);
    process_container<DequeWrapper>(argc, argv, false);
    return 0;
}