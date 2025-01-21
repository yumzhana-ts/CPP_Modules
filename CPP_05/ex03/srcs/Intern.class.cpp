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
#include "PresidentialPardonForm.class.hpp"
#include "RobotomyRequestForm.class.hpp"
#include "ShrubberyCreationForm.class.hpp"

/****************************************************
*                 Memeber Functions                *
****************************************************/

AForm* Intern::complain(std::string level, std::string target) 
{
    std::string levels[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    void (Harl::*ptr[4])() = {&sh, &rob, &pr, &other};

    int i = 0;
    while(i < 3 && levels[i] != level)
        i++;
    (this->*ptr[i])();
}

Aform* sh( void )
{
    AForm* form = new ShrubberyCreationForm(target);
    return form;
}
Aform* ro( void )
{
    AForm* form = new RobotomyRequestForm(target);
    return form;
}
Aform* pr( void )
{
    AForm* form = new PresidentialPardonForm(target);
    return form;
}
Aform* other( void )
{
    AForm* form = NULL;
    std::cout << "" << std::endl;
    return form;
}