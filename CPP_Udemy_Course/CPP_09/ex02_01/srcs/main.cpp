/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:41:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2025/05/16 14:40:31 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Pmerge_me.class.hpp"

template <template <typename> class Container_wrapper>
void process_container(int argc, char **argv)
{
    typedef typename Container_wrapper<int>::type ContainerType;
    t_data<ContainerType> container;
    setup_container<Container_wrapper>(argc, argv, container);
    dispatcher<Container_wrapper>(container);
    print_vector<int, Container_wrapper>(container.original_container);
}

int main(int argc, char **argv)
{
    process_container<VectorWrapper>(argc, argv);
    process_container<DequeWrapper>(argc, argv);
    return 0;
}