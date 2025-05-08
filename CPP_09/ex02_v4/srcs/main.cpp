/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:41:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2025/05/08 02:01:43 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Pmerge_me.class.hpp"


// TODO: fix sequence when its more then jakob index
// TODO: intialize indexes only when needed or rewrite logic. mb better logic?
// TODO: how to set recursion depth before compilation process?
// TODO: clean trash


int main(int argc, char **argv)
{
    t_original_vector vec;
    parse_and_store_numbers(argc, argv, vec);
    meta_recursive(vec);
    return 0;
}