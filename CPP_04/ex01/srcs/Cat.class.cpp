/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:16 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/08/05 23:48:39 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.class.hpp"
#include "Brain.class.hpp"

/****************************************************/
/*                    Constructor                   */
/****************************************************/

Cat::Cat(void): Animal("Cat"), brain(new Brain())
{
    if (DEBUG){ std::cout << GREEN << "[Cat] Default Constructor called" << RESET_COLOR << std::endl;}
}
//Cat(std::string n = "Unkown"): name(n)

Cat::Cat(const Cat& src): Animal(src.type), brain(new Brain(*src.brain)) 
{
    if (DEBUG){std::cout << GREEN << "[Cat] Copy Constructor called" << RESET_COLOR << std::endl;}
    *this = src;
}

/****************************************************/
/*                    Destructor.                   */
/****************************************************/

Cat::~Cat(void) 
{
    if (DEBUG){std::cout << GREEN << "[Cat] Destructor called" << RESET_COLOR << std::endl;}
    delete brain;
}

/****************************************************
*                    Overload                      *
****************************************************/


Cat& Cat::operator=(const Cat& rhs) 
{
    if (DEBUG){std::cout << GREEN << "[Cat] Copy assignment operator called" << RESET_COLOR <<  std::endl;}
    if (this != &rhs)
    {
        this->type = rhs.type;
        brain = new Brain(*rhs.brain);
    }
    return (*this);
}


/****************************************************
*                 Memeber Functions                *
****************************************************/

void Cat::make_sound() const
{
    std::cout << "Meow!" << std::endl;
}

/* void Cat::print_brain_address() const 
{
    std::cout << GREEN << "Brain address: " << brain << RESET_COLOR <<std::endl;
} */