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

AForm* Intern::make_form(std::string form_type, std::string target) 
{
    std::string form_types[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm* (*form_creators[4])(std::string form_type) = {&sh, &rob, &pr, &other};

    int i = 0;
    while(i < 3 && form_types[i] != form_type)
        i++;
    (this->*form_creators[i](target));
    std::cout <<
    return NULL;
}

AForm* sh( void )
{
    return new ShrubberyCreationForm(target);
}
AForm* ro( void )
{
    return new RobotomyRequestForm(target);  
}
AForm* pr( void )
{
    return new PresidentialPardonForm(target);
}
AForm* other( void )
{
    std::cout << "Form not found. Try shrubbery creation, robotomy request, presidential pardon" << std::endl;
    return NULL;
}