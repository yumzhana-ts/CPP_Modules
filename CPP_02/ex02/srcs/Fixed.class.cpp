/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:16 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/07/09 14:38:38 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"

const int Fixed::frac_bits = 8;

/****************************************************/
/*                    Constructor                   */
/****************************************************/

Fixed::Fixed(void): fixed_point(0)
{
    if(DEBUG)
        std::cout << GREEN << "[Constructor] Default constructor called" << RESET_COLOR << std::endl;
}

Fixed::Fixed(const int value)
{
    if(DEBUG)
        std::cout << GREEN << "[Constructor] Int constructor called" << RESET_COLOR << std::endl;
    fixed_point = value * (1 << frac_bits); // number to multiply by 2^8
}

Fixed::Fixed(const float value)
{
    if(DEBUG)
        std::cout << GREEN << "[Constructor] Float constructor called" << RESET_COLOR << std::endl;   
    fixed_point = (int)(roundf(value * (1 << frac_bits))); //number to multiply by 2^8 and round
}

Fixed::Fixed(Fixed const & src)
{
    if(DEBUG)
        std::cout << GREEN << "[Copy constructor] Copy constructor called" << RESET_COLOR << std::endl;
    *this = src;
    //fixed_point = src.fixed_point;
}

/****************************************************/
/*                    Destructor.                   */
/****************************************************/

Fixed::~Fixed() 
{
    if(DEBUG)
        std::cout << GREEN << "[Destructor] Destructor called" << RESET_COLOR << std::endl;
}

/****************************************************
*                    Overload                      *
****************************************************/

Fixed& Fixed::operator=(const Fixed& rhs) 
{
    if(DEBUG)
        std::cout << GREEN << "[Assignment] Copy assignment operator called" << std::endl;
    if (this != &rhs)
        this->fixed_point = rhs.get_raw_bits();
    return (*this);
}

// comparison operators
bool Fixed::operator>(const Fixed& rhs) const
{
    return this->fixed_point > rhs.get_raw_bits();
}

bool Fixed::operator>=(const Fixed& rhs) const
{
    return this->fixed_point >= rhs.get_raw_bits();
}

bool Fixed::operator<(const Fixed& rhs) const
{
    return this->fixed_point < rhs.get_raw_bits();
}

bool Fixed::operator<=(const Fixed& rhs) const
{
    return this->fixed_point <= rhs.get_raw_bits();
}

bool Fixed::operator==(const Fixed& rhs) const
{
    return this->fixed_point == rhs.get_raw_bits();
}

bool Fixed::operator!=(const Fixed& rhs) const
{
    return this->fixed_point != rhs.get_raw_bits();
}

//arithmetic operators
Fixed   Fixed::operator+(Fixed const &rhs) const 
{
    int result = (this->get_raw_bits()) + rhs.get_raw_bits();
    return Fixed((float)(result) / (1 << frac_bits));
}

Fixed   Fixed::operator-(Fixed const &rhs) const 
{
    int result = (this->get_raw_bits()) - rhs.get_raw_bits();
    return Fixed((float)(result) / (1 << frac_bits));
}

Fixed   Fixed::operator*(Fixed const &rhs) const 
{
    long long result = (long long)(this->get_raw_bits()) * rhs.get_raw_bits();
    int result_fixed_point_value = (int)(result >> frac_bits);
    return Fixed((float)(result_fixed_point_value) / (1 << frac_bits));
}

Fixed   Fixed::operator/(const Fixed& rhs) const 
{
    long long numerator = (long long)(this->fixed_point) << frac_bits;
    int denominator = rhs.get_raw_bits();
    int result_fixed_point_value = (int)(numerator / denominator);
    return Fixed((float)(result_fixed_point_value) / (1 << frac_bits));
}

//post & pre increment
Fixed   &Fixed::operator++() 
{
    this->fixed_point++;
    return (*this);
}

Fixed   Fixed::operator++(int) 
{
    Fixed temp(*this);
    this->fixed_point++;
    return (temp);
}

Fixed   &Fixed::operator--() 
{
    this->fixed_point--;
    return (*this);
}

Fixed   Fixed::operator--(int) 
{
    Fixed temp(*this);
    this->fixed_point--;
    return (temp);
}

//min & max
Fixed    Fixed::min(Fixed &obj1, Fixed &obj2)
{
    return obj1 > obj2 ? obj2 : obj1;
}

const Fixed    Fixed::min(const Fixed &obj1, const Fixed &obj2)
{
    return obj1 > obj2 ? obj2 : obj1;
}

Fixed    Fixed::max(Fixed &obj1, Fixed &obj2)
{
    return obj1 > obj2 ? obj1 : obj2;
}

const Fixed    Fixed::max(const Fixed &obj1, const Fixed &obj2)
{
    return obj1 > obj2 ? obj1 : obj2;
}


std::ostream &operator<<(std::ostream & o, Fixed const & rhs)
{
    o << rhs.to_float();
    return o;
}

/****************************************************/
/*                Getters & Setters                 */
/****************************************************/

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

/****************************************************
*                 Memeber Functions                *
****************************************************/

float Fixed::to_float(void) const
{
    return (float)(fixed_point) / (1 << frac_bits); // divide by 2^8 to represent in float
}

int Fixed::to_int(void) const
{   
    return fixed_point >> frac_bits; //remove the fractional part, use the right shift (>>) operator
}

void Fixed::print_val(void) const
{
    std::cout << BOLD_BLACK << "raw bits: " << this->fixed_point << std::endl;
    std::cout << "in float: " << ((float)(fixed_point) / (1 << frac_bits)) << std::endl;
    std::cout << "in int: " << (fixed_point >> frac_bits) << RESET_COLOR << std::endl;
}