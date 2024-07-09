/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:41:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/07/06 01:39:22 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"

int main() 
{
    Fixed a;
    Fixed b(a);
    Fixed c;

    c = b;

    std::cout << a.get_raw_bits() << std::endl;
    std::cout << b.get_raw_bits() << std::endl;
    std::cout << c.get_raw_bits() << std::endl;

    return (0);
}