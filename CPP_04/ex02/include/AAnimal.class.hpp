/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/08/05 16:41:25 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AAnimal_CLASS_H
#define AAnimal_CLASS_H

#include <iostream>
#include "Brain.class.hpp"

class AAnimal
{
protected:
    std::string type;
public:
    AAnimal(std::string t = "AAnimal");
    virtual ~AAnimal(void);
    AAnimal(const AAnimal& other);
    virtual AAnimal& operator=(const AAnimal& other);

    std::string get_type(void) const {return (this->type);}
    void set_type(std::string t){this->type = t;}
    
    virtual void make_sound() const = 0;
    virtual Brain* get_brain() const = 0;
    virtual AAnimal* clone() const = 0;
    virtual void print_brain_address() const = 0;
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
#define YELLOW "\033[0;33m"

#endif