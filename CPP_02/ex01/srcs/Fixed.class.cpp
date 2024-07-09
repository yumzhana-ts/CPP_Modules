/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:16 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/07/07 23:04:15 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"

const int Fixed::frac_bits = 8;

Fixed::Fixed(void): fixed_point(0)
{
    std::cout << GREEN << "[Constructor] Default constructor called" << RESET_COLOR << std::endl;
}

Fixed::Fixed(const int value)
{
    std::cout << GREEN << "[Constructor] Int constructor called" << RESET_COLOR << std::endl;
    fixed_point = value * (1 << frac_bits); // number to multiply by 2^8
}

Fixed::Fixed(const float value)
{
    std::cout << GREEN << "[Constructor] Float constructor called" << RESET_COLOR << std::endl;   
    fixed_point = (int)(roundf(value * (1 << frac_bits))); //number to multiply by 2^8 and round
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
    //std::cout << GREEN << "[Getter] Get_raw_bits member function called" << RESET_COLOR << std::endl;
    return (this->fixed_point);
}

void Fixed::set_raw_bits(int v)
{
    //std::cout << GREEN << "[Setter] Set_raw_bits member function called" << RESET_COLOR << std::endl;
    this->fixed_point = v;
}

float Fixed::to_float(void) const
{
    return (float)(fixed_point) / (1 << frac_bits); // divide by 2^8 to represent in float
}

int Fixed::to_int(void) const
{   
    return fixed_point >> frac_bits; //remove the fractional part, use the right shift (>>) operator
}

std::ostream &operator<<(std::ostream & o, Fixed const & rhs)
{
    o << rhs.to_float();
    return o;
}