/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/07/09 21:11:19 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_CLASS_H
#define POINT_CLASS_H

#include <iostream>
#include "Fixed/include/Fixed.class.hpp"

class Point
{
private:
    const Fixed x;
    const Fixed y;
public:
    Point(void);
    Point(const Fixed& f_x, const Fixed& f_y);
    ~Point(void);
    Point(const Point& other);
    //Point& operator=(const Point& other);

    //get&set
    Fixed get_x() const {return (this->x);}
    Fixed get_y() const {return (this->y);}
    void print_val();
    static Fixed orientation(Point const a, Point const b, Point const point); 
    //void set_value(int v){this->x = v;}

    static bool bsp( Point const a, Point const b, Point const c, Point const point);
};


#define DEBUG 0
// Define ANSI escape sequences for colors
#define RESET_COLOR "\033[0m"
#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define BLUE "\033[0;34m"
#define WHITE "\033[0;37m"
#define BOLD_BLACK "\033[1;30m"
#define BG_WHITE "\033[0;47m"
#endif