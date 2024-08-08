/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/08/07 21:53:33 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_CLASS_H
#define ICE_CLASS_H

#include <iostream>
#include "AMateria.class.hpp"

class Ice: public AMateria
{
private:
public:
    Ice(void);
    ~Ice(void);
    Ice(const Ice& other);
    Ice& operator=(const Ice& other);

    virtual AMateria* clone() const{return new Ice(*this);}

    //get&set
    //int get_value(void) const {return (this->value);}
    //void set_value(int v){this->value = v;}
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