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
#include <cstdlib>

/****************************************************/
/*                    Constructor                   */
/****************************************************/

RobotomyRequestForm::RobotomyRequestForm(std::string t): AForm("Robotomy", 72, 45), target(t)
{
    if (DEBUG){ std::cout << GREEN << "[RobotomyRequestForm] Default Constructor called" << RESET_COLOR << std::endl;}
}
//RobotomyRequestForm(std::string n = "Unkown"): name(n)

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src): AForm("Robotomy", 25, 5), target(src.target)
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
    if (DEBUG){std::cout << GREEN << "[RobotomyRequestForm] Copy assignment operator called" << RESET_COLOR <<   std::endl;}
    if (this != &rhs)
        this->target= rhs.get_target();
    return (*this);
}

/****************************************************
*                 Memeber Functions                *
****************************************************/

void RobotomyRequestForm::execute() const
{
    for(int i = 0; i < 5; i++)
    {
        std::cout << "Bzzzzzzz...  ";
        std::cout << "Vrrrrrrr...  ";;
    }
    std::cout << std::endl;
    if (rand() % 2 == 0)
        std::cout << this->target << " has been robotomized successfully" << RESET_COLOR << std::endl;
    else
        std::cout << "The robotomy failed" << RESET_COLOR << std::endl;
}