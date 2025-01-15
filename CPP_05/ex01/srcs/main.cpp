/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:41:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/12/01 23:00:42 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.class.hpp"
#include "Form.class.hpp"

int main() 
{
    std::cout << BLUE << "\nTest 1: Testing Orthodox Canonical Form" << RESET_COLOR <<std::endl;
    Form banana_sticker("Chiquita", 1, 1);
    std::cout << banana_sticker;
    Form scam_sticker(banana_sticker);
    std::cout << scam_sticker;
    Form sticker_overload("Aloha", 1, 1);
    sticker_overload = banana_sticker;
    std::cout << sticker_overload;
    std::cout << LINE << std::endl;

    std::cout << BLUE << "\nTest 2: Incorrect grades of forms"<< RESET_COLOR << std::endl;
    try
    {
        Form too_high_sign("test_sign", 0, 1);
    }
    catch(Bureaucrat::GradeTooHighException &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Form too_low_sign("test_not_sign", 0, 3000);
    }
    catch(Bureaucrat::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Form too_high_exec("test_exec", 0, 1);
    }
    catch(Bureaucrat::GradeTooHighException &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Form too_low_exec("test_not_exec", 3000, 1);
    }
    catch(Bureaucrat::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << BLUE <<  "\nTest 3: Grade of bureaucrat is not high enough" << RESET_COLOR << std::endl;
    Form random("test_not_exec", 1, 1);
    Bureaucrat old_clerk(150, "Ben");
    try
    {
        old_clerk.sign_form(random);
    }
    catch(Bureaucrat::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << BLUE << "\nTest 4: Form is signed by Bureaucrat" << RESET_COLOR << std::endl;
    Form ran("agreement", 2, 2);
    Bureaucrat clerk(1, "Alex");
    clerk.sign_form(ran);
}