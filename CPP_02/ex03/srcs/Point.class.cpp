/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:16 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/07/09 21:56:29 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.class.hpp"

/****************************************************/
/*                    Constructor                   */
/****************************************************/

Point::Point(void): x(0), y(0)
{
    if (DEBUG){ std::cout << GREEN << "[Constructor] Template - Default Constructor called" << RESET_COLOR << std::endl;}
}

Point::Point(const Fixed& f_x, const Fixed& f_y): x(f_x), y(f_y)
{
    if (DEBUG){ std::cout << GREEN << "[Constructor] Template - Default Constructor called" << RESET_COLOR << std::endl;}
}

Point::Point(const Point& src): x(src.x), y(src.y)
{
    if (DEBUG){std::cout << GREEN << "[Constructor] Template - Copy Constructor called" << RESET_COLOR << std::endl;}
}

/****************************************************/
/*                    Destructor.                   */
/****************************************************/

Point::~Point(void) 
{
    if (DEBUG){std::cout << GREEN << "[Destructor] Template - Destructor called" << RESET_COLOR << std::endl;}
}

/****************************************************
*                    Overload                      *
****************************************************/

/* Point& Point::operator=(const Point& rhs)
{
    return *this;
} */

/****************************************************
*                 Memeber Functions                *
****************************************************/

void Point::print_val()
{
    std::cout << BLUE "x:" << this->x;
    std::cout << " y: " << this->y << RESET_COLOR << std::endl;
}

Fixed Point::orientation(Point const a, Point const b, Point const p) 
{
    Fixed ax = a.get_x();
    Fixed ay = a.get_y();
    Fixed bx = b.get_x();
    Fixed by = b.get_y();
    Fixed px = p.get_x();
    Fixed py = p.get_y();
    return (bx - ax) * (py - ay) - (by - ay) * (px - ax);
}
bool Point::bsp( Point const a, Point const b, Point const c, Point const p)
{
    Fixed e(Fixed(Point::orientation(a, b, p)));
    std::cout << "AB x AP: " << e << std::endl;
    Fixed f(Fixed(Point::orientation(b, c, p)));
    std::cout << "BC x BP: " << f << std::endl;
    Fixed g(Fixed(Point::orientation(c, a, p)));
    std::cout << "CA x CP: " << g << std::endl;

    if((e <= 0 && f <= 0 &&g <=0 ) || (e >= 0 && f >= 0 && g >=0 ))
        return (true);
    else
        return (false);
}