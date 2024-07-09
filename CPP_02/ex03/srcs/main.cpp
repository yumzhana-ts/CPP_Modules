/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:41:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/07/09 22:22:31 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.class.hpp"

int main() 
{
    Point a(7, 7); // Default Constructor called
    Point b(11, 1);
    Point c(2, 2);
    Point p(7, 3);


    if(Point::bsp(a, b, c, p) == true)
        std::cout << GREEN "The point lies inside the triangle, comfortably nestled within its geometric confines." RESET_COLOR<< std::endl;
    else
        std::cout << RED "The point lies outside the triangle, beyond its boundaries." RESET_COLOR<< std::endl;
    return (0);
}