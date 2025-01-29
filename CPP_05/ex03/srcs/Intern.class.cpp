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

AForm* sh(std::string targe);
AForm* ro(std::string targe);
AForm* pr(std::string targe);

const char *Intern::Incorrect_form::what() const throw()
{
    return (RED"Error: Form not found for Bender Try shrubbery creation, robotomy request, presidential pardon"RESET_COLOR);
}

AForm* Intern::make_form(std::string form_type, std::string target) 
{
    std::string form_types[3] = {"shrubbery", "robotomy", "presidential"};
    AForm* (*form_creators[4])(std::string) = {&sh, &ro, &pr};

    int i = 0;
    while(i < 3 && form_types[i] != form_type)
        i++;
    try
    {
        if(i >= 3)
            throw Intern::Incorrect_form();
        return form_creators[i](target);
    }
    catch(Intern::Incorrect_form &e)
    {
        std::cout << e.what() << std::endl;
        return NULL;
    }
}

AForm* sh(std::string target)
{
    return new ShrubberyCreationForm(target);
}
AForm* ro(std::string target)
{
    return new RobotomyRequestForm(target);
}
AForm* pr(std::string target)
{
    return new PresidentialPardonForm(target);
}
