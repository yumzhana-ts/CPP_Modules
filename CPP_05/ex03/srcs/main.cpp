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
    orthodox_test();
    AForm* form_1 = new ShrubberyCreationForm("home");
    AForm* form_2 = new RobotomyRequestForm("home");
    AForm* form_3 = new PresidentialPardonForm("home");
    Bureaucrat Eva(1, "Eva");

    std::cout << "\nTest 2: Form is not signed" << std::endl;
    Eva.execute_form(*form_1);

    Bureaucrat Paula(140, "Paula");
    std::cout << "\nTest 3: Level of Bueraucrat is not high enough" << std::endl;
    Paula.sign_form(*form_2);
    Paula.execute_form(*form_2);

    std::cout << "\nTest 3: execute all 3 forms" << std::endl;
    Eva.sign_form(*form_1);
    Eva.execute_form(*form_1);
    Eva.sign_form(*form_2);
    Eva.execute_form(*form_2);
    Eva.sign_form(*form_3);
    Eva.execute_form(*form_3);
    delete form_1;
    delete form_2;
    delete form_3;
    return (0);
}