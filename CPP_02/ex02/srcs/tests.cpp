/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:41:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/07/09 14:51:53 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"


int main() 
{
    Fixed a;
    Fixed b;
    a = Fixed(1234.4421f);
    b = Fixed(1234.4321f);
    Fixed c(b);

    std::cout << "values for a:" <<std::endl; 
    a.print_val();
    std::cout << "values for b:" <<std::endl; 
    b.print_val();
    std::cout << "values for c:" <<std::endl; 
    c.print_val();

    std::cout << "Test case 1: operator >" << std::endl;
    std::cout << ((a > b) ? (GREEN  "Passed: a is greater than b" RESET_COLOR) : (RED "Failed: a is not greater than b" RESET_COLOR)) << std::endl;
    std::cout << "Test case 2: operator <" << std::endl;
    std::cout << ((b < a) ? (GREEN  "Passed: b is less than a" RESET_COLOR) : (RED "Failed: b is not less than a" RESET_COLOR)) << std::endl;
    std::cout << "Test case 3: operator >=" << std::endl;
    std::cout << ((b >= c) ? (GREEN  "Passed: b is greater or equal than c" RESET_COLOR) : (RED "Failed: b is not greater or equal  than c" RESET_COLOR)) << std::endl;
    std::cout << "Test case 4: operator <=" << std::endl;
    std::cout << ((b <= c) ? (GREEN  "Passed: b is less or equal than c" RESET_COLOR) : (RED "Failed: b is not less or equal than c" RESET_COLOR)) << std::endl;
    std::cout << "Test case 5: operator <=" << std::endl;
    std::cout << ((a >= c) ? (GREEN  "Passed: a is greater or equal than c" RESET_COLOR) : (RED "Failed: a is not greater or equal than c" RESET_COLOR)) << std::endl;
    std::cout << "Test case 6: operator <=" << std::endl;
    std::cout << ((c <= a) ? (GREEN  "Passed: c is less or equal than a" RESET_COLOR) : (RED "Failed: c is not less or equal than a" RESET_COLOR)) << std::endl;
    std::cout << "Test case 7: operator ==" << std::endl;
    std::cout << ((c == b) ? (GREEN  "Passed: c is equal to b" RESET_COLOR) : (RED "Failed: c is not equal to b" RESET_COLOR)) << std::endl;
    std::cout << "Test case 8: operator !=" << std::endl;
    std::cout << ((a != b) ? (GREEN  "Passed: a is not equal to b" RESET_COLOR) : (RED "Failed: a is equal to b" RESET_COLOR)) << std::endl;
    
    std::cout << "Test case 9: operator +" << std::endl;
    Fixed const d(Fixed(5.05f) + Fixed(2));
    std::cout << GREEN "Current state: " << d << std::endl;
    std::cout << "Expected state: 7.05078" RESET_COLOR << std::endl;

    std::cout << "Test case 10: operator -" << std::endl;
    Fixed const e(Fixed(5.05f) - Fixed(2));
    std::cout << GREEN "Current state: " << e << std::endl;
    std::cout << "Expected state: 3.05078" RESET_COLOR << std::endl;

    std::cout << "Test case 11: operator *" << std::endl;
    Fixed const f(Fixed(5.05f) * Fixed(2));
    std::cout << GREEN "Current state: " << f << std::endl;
    std::cout << "Expected state: 10.1016" RESET_COLOR << std::endl;

    std::cout << "Test case 12: operator +" << std::endl;
    Fixed const g(Fixed(5.05f) / Fixed(2));
    std::cout << GREEN "Current state: " << g << std::endl;
    std::cout << "Expected state: 2.52344 " RESET_COLOR << std::endl;

    std::cout << "Test case 13: ++operator" << std::endl;
    Fixed h;
    std::cout << GREEN "Current state: " << ++h << " " << h << std::endl;
    std::cout << "Expected state: 0.00390625 0.00390625" RESET_COLOR  << std::endl;
    
    std::cout << "Test case 14: --operator" << std::endl;
    std::cout << GREEN "Current state: " << --h << " " << h << std::endl;
    std::cout << "Expected state: 0 0" RESET_COLOR  << std::endl;

    std::cout << "Test case 15: operator++" << std::endl;
    std::cout << GREEN "Current state: " << h++ << " " << h << std::endl;
    std::cout << "Expected state: 0 0.00390625" RESET_COLOR  << std::endl;

    std::cout << "Test case 16: operator--" << std::endl;
    std::cout << GREEN "Current state: " << h-- << " " << h << std::endl;
    std::cout << "Expected state: 0.00390625 0" RESET_COLOR  << std::endl;

    std::cout << "Test case 17: min " << std::endl;
    std::cout << GREEN "Current state: "  <<  Fixed::min(a,b)<< std::endl;
    std::cout << "Expected state: 1234.43" RESET_COLOR  << std::endl;    

    std::cout << "Test case 18: min const" << std::endl;
    std::cout << GREEN "Current state: " << Fixed::min(a,b) << std::endl;
    std::cout << "Expected state: 1234.43" RESET_COLOR  << std::endl;

    std::cout << "Test case 17: max " << std::endl;
    std::cout << GREEN "Current state: " << Fixed::max(a,b) << std::endl;
    std::cout << "Expected state: 1234.44" RESET_COLOR  << std::endl;    

    std::cout << "Test case 18: max const" << std::endl;
    std::cout << GREEN "Current state: " << Fixed::max(a,b) << std::endl;
    std::cout << "Expected state: 1234.44" RESET_COLOR  << std::endl; 

    return (0);
}