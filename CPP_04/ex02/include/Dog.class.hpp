/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/08/05 22:54:16 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_CLASS_H
#define DOG_CLASS_H

#include "AAnimal.class.hpp"
#include "Brain.class.hpp"
#include <iostream>

class Dog: public AAnimal
{
private:
    Brain* brain;
public:
    Dog(void);
    virtual ~Dog(void);
    Dog(const Dog& other);
    Dog& operator=(const Dog& rhs);

    virtual void make_sound() const;
    virtual Brain* get_brain() const {return brain;}
    AAnimal* clone() const {return new Dog(*this);}
    virtual void print_brain_address() const {brain->print_address();}
};


#define DEBUG 1
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