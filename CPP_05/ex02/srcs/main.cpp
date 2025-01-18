/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:41:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/07/13 03:54:02 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.class.hpp"
#include "RobotomyRequestForm.class.hpp"
#include "PresidentialPardonForm.class.hpp"
#include "AForm.class.hpp"

void orthodox_test()
{
    std::cout << "\nTest 1: Testing Orthodox Canonical Form" << std::endl;
    AForm* form = new ShrubberyCreationForm("home");
    AForm* form_c = new ShrubberyCreationForm(*static_cast<ShrubberyCreationForm*>(form));
    AForm* form_copy = new ShrubberyCreationForm("home");
    *static_cast<ShrubberyCreationForm*>(form_copy) = *static_cast<ShrubberyCreationForm*>(form);
    delete form;
    delete form_copy;
    delete form_c;
}

int main() 
{
    //orthodox_test();
    AForm* form_1 = new ShrubberyCreationForm("home");
    form_1->execute();
    AForm* form_2 = new RobotomyRequestForm("home");
    form_2->execute();
    AForm* form_3 = new PresidentialPardonForm("home");
    form_3->execute();

    delete form_1;
    delete form_2;
    delete form_3;
    return (0);
}