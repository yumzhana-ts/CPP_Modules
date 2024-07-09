/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:16 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/07/07 23:04:34 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"

const int Fixed::frac_bits = 8;

Fixed::Fixed(void): fixed_point(0)
{
    std::cout << GREEN << "[Constructor] Default constructor called" << RESET_COLOR << std::endl;
}

Fixed::~Fixed() 
{
    std::cout << GREEN << "[Destructor] Destructor called" << RESET_COLOR << std::endl;
}

Fixed::Fixed(Fixed const & src)
{
    std::cout << GREEN << "[Copy constructor] Copy constructor called" << RESET_COLOR << std::endl;
    *this = src;
    //fixed_point = src.fixed_point;
}

Fixed& Fixed::operator=(const Fixed& rhs) 
{
    std::cout << GREEN << "[Assignment] Copy assignment operator called" << std::endl;
    if (this != &rhs)
        this->fixed_point = rhs.get_raw_bits();
    return (*this);
}

int Fixed::get_raw_bits(void) const
{
    std::cout << GREEN << "[Getter] Get_raw_bits member function called" << RESET_COLOR << std::endl;
    return (this->fixed_point);
}

void Fixed::set_raw_bits(int v)
{
    //std::cout << GREEN << "[Setter] Set_raw_bits member function called" << RESET_COLOR << std::endl;
    this->fixed_point = v;
}