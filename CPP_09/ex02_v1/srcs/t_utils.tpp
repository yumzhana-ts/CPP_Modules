/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_utils.tpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:16 by ytsyrend          #+#    #+#             */
/*   Updated: 2025/04/15 15:51:29 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pmerge_me.class.hpp"

template <typename T1, typename T2>
std::ostream &operator<<(std::ostream &o, const std::pair<T1, T2> &pair)
{
    o << "{" << pair.first << ", " << pair.second << "}";
    return o;
}

template <typename T>
void print_vec(const std::vector<T>& vec)
{
    typename std::vector<T>::const_iterator begin = vec.begin();
    typename std::vector<T>::const_iterator end = vec.end();
    while (begin != end)
    {
        std::cout << *begin << " ";
        ++begin;
    }
    std::cout << std::endl;
}
