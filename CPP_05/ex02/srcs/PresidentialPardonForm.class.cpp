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

#include "PresidentialPardonForm.class.hpp"

/****************************************************/
/*                    Constructor                   */
/****************************************************/

PresidentialPardonForm::PresidentialPardonForm(std::string t): AForm("Presidential", 25, 5), target(t)
{
    if (DEBUG){ std::cout << GREEN << "[PresidentialPardonForm] Default Constructor called" << RESET_COLOR << std::endl;}
}
//PresidentialPardonForm(std::string n = "Unkown"): name(n)

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src): AForm("Presidential", 25, 5), target(src.target) 
{
    if (DEBUG){std::cout << GREEN << "[PresidentialPardonForm] Copy Constructor called" << RESET_COLOR << std::endl;}
    //*this = src;
}

/****************************************************/
/*                    Destructor.                   */
/****************************************************/

PresidentialPardonForm::~PresidentialPardonForm(void) 
{
    if (DEBUG){std::cout << GREEN << "[PresidentialPardonForm] Destructor called" << RESET_COLOR << std::endl;}
}

/****************************************************
*                    Overload                      *
****************************************************/


PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs) 
{
    if (DEBUG){std::cout << GREEN << "[PresidentialPardonForm] Copy assignment operator called" << RESET_COLOR <<  std::endl;}
    if (this != &rhs)
        this->target= rhs.get_target();
    return (*this);
}

/****************************************************
*                 Memeber Functions                *
****************************************************/

void PresidentialPardonForm::execute() const
{
    std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
