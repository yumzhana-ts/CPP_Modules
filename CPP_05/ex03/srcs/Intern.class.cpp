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

#include "Intern.class.hpp"

/****************************************************/
/*                    Constructor                   */
/****************************************************/

Intern::Intern() 
{
    if (DEBUG){ std::cout << GREEN << "[Intern] Default Constructor called" << RESET_COLOR << std::endl;}
}
//Intern(std::string n = "Unkown"): name(n)

Intern::Intern(const Intern& src) 
{
    if (DEBUG){std::cout << GREEN << "[Intern] Copy Constructor called" << RESET_COLOR << std::endl;}
    //*this = src;
}

/****************************************************/
/*                    Destructor.                   */
/****************************************************/

Intern::~Intern() 
{
    if (DEBUG){std::cout << GREEN << "[Intern] Destructor called" << RESET_COLOR << std::endl;}
}

/****************************************************
*                    Overload                      *
****************************************************/


Intern& Intern::operator=(const Intern& rhs) 
{
    if (DEBUG){std::cout << GREEN << "[Intern] Copy assignment operator called" << std::endl;}
    return (*this);
}

/****************************************************
*                 Memeber Functions                *
****************************************************/

/*AForm* Intern::make_form(std::string form, std::string target)
{
    if(form == "shrubbery creation")
    {
        AForm* form = new ShrubberyCreationForm(target);
    }
    else if(form == "robotomy request")
    {
        AForm* form = new RobotomyRequestForm(target);
    }
    else if(form == "presidential pardon")
    {
        AForm* form = new PresidentialPardonForm(target);
    }
    return (form);
}*/