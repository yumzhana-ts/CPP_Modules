                                                                                        /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:16 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/12/01 22:50:01 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.class.hpp"

/****************************************************/
/*                    Constructor                   */
/****************************************************/

RobotomyRequestForm::RobotomyRequestForm(std::string t): target(t), AForm()
{
    if (DEBUG){ std::cout << GREEN << "[RobotomyRequestForm] Default Constructor called" << RESET_COLOR << std::endl;}
}
//RobotomyRequestForm(std::string n = "Unkown"): name(n)

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src): target(src.target), AForm()
{
    if (DEBUG){std::cout << GREEN << "[RobotomyRequestForm] Copy Constructor called" << RESET_COLOR << std::endl;}
    //*this = src;
}

/****************************************************/
/*                    Destructor.                   */
/****************************************************/

RobotomyRequestForm::~RobotomyRequestForm(void) 
{
    if (DEBUG){std::cout << GREEN << "[RobotomyRequestForm] Destructor called" << RESET_COLOR << std::endl;}
}

/****************************************************
*                    Overload                      *
****************************************************/


RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs) 
{
    if (DEBUG){std::cout << GREEN << "[RobotomyRequestForm] Copy assignment operator called" << std::endl;}
    if (this != &rhs)
        this->value = rhs.get_value();
    return (*this);
}

/****************************************************
*                 Memeber Functions                *
****************************************************/
