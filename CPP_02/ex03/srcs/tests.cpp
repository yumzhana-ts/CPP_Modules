/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:41:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/07/09 21:56:57 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.class.hpp"

int main() 
{
    std::cout << "Enter values for point a x: " << std::endl;
    float a_x;
    std::cin >> a_x;
    std::cout << "Enter values for point a y: " << std::endl;
    float a_y;
    std::cin >> a_y;
    Point a(a_x, a_y); // Default Constructor called
    std::cout << BLUE "Point a: ";
    a.print_val();

    std::cout << "Enter values for point b x: " << std::endl;
    float b_x;
    std::cin >> b_x;
    std::cout << "Enter values for point b y: " << std::endl;
    float b_y;
    std::cin >> b_y;
    Point b(b_x, b_y);
    std::cout << BLUE  "Point b: ";
    b.print_val();

    std::cout << "Enter values for point c x: " << std::endl;
    float c_x;
    std::cin >> c_x;
    std::cout << "Enter values for point c y: " << std::endl;
    float c_y;
    std::cin >> c_y;
    Point c(c_x, c_y);
    std::cout << BLUE  "Point c: ";
    c.print_val();
    
    std::cout << "Enter values for point p x: " << std::endl;
    float p_x;
    std::cin >> p_x;
    std::cout << "Enter values for point p y: " << std::endl;
    float p_y;
    std::cin >> p_y;
    Point p(p_x, p_y);
    std::cout << BLUE "Point p: ";
    c.print_val();

    if(Point::bsp(a, b, c, p) == true)
        std::cout << GREEN "The point lies inside the triangle, comfortably nestled within its geometric confines." RESET_COLOR<< std::endl;
    else
        std::cout << RED "The point lies outside the triangle, beyond its boundaries." RESET_COLOR<< std::endl;
    
    //int ab_ax_raw = (b_x.get_raw_bits() - a_x.get_raw_bits()) * (p_y.get_raw_bits() - a_y.get_raw_bits()) - (b_y.get_raw_bits() - a_y.get_raw_bits()) * (p_x.get_raw_bits() - a_x.get_raw_bits());
    //value.set_raw_bits(ab_ax_raw);
    //std::cout << "Vector cross product AB * AP: "<< value;
    return (0);
}