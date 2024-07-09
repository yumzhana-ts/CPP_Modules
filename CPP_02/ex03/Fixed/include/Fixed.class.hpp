/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/07/09 20:03:33 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_H
#define FIXED_CLASS_H
#include <iostream>
#include <cmath>

class Fixed
{
private:
    int                 fixed_point;
    const static int    frac_bits;
public:
    Fixed(void);
    Fixed(const int value);
    Fixed(const float value);
    ~Fixed(void);
    Fixed(const Fixed& rhs);
    //Fixed& operator=(const Fixed& rhs);
    bool operator>(const Fixed& rhs) const;
    bool operator<(const Fixed& rhs) const;
    bool operator>=(const Fixed& rhs) const;
    bool operator<=(const Fixed& rhs) const;
    bool operator==(const Fixed& rhs) const;
    bool operator!=(const Fixed& rhs) const;
    Fixed operator+(Fixed const &rhs) const;
    Fixed operator-(Fixed const &rhs) const;
    Fixed operator*(Fixed const &rhs) const;
    Fixed operator/(Fixed const &rhs) const;
    Fixed  &operator++();
    Fixed  operator++(int);
    Fixed  &operator--();
    Fixed  operator--(int);
    static Fixed  min(Fixed &obj1, Fixed &obj2);
    static const Fixed  min(const Fixed &obj1, const Fixed &obj2);
    static Fixed  max(Fixed &obj1, Fixed &obj2);
    static const Fixed  max(const Fixed &obj1, const Fixed &obj2);   
    int get_raw_bits(void) const;
    void set_raw_bits(int v);
    float to_float(void) const;
    int to_int(void) const;
    void print_val(void) const;
};

std::ostream &operator<<(std::ostream & o, Fixed const & rhs);

#define DEBUG 0
// Define ANSI escape sequences for colors
#define RESET_COLOR "\033[0m"
#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define BLUE "\033[0;34m"
#define WHITE "\033[0;37m"
#define BOLD_BLACK "\033[1;30m"
#define BOLD_WHITE "\033[1;37m"
#define BG_WHITE "\033[0;47m"


#endif