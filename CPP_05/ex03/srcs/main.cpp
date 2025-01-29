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
#include "Intern.class.hpp"

int main() 
{
    std::cout << "Test case 1: Form not found" << std::endl;
    Intern someRandonIntern;
    AForm *rrf;
    rrf = someRandonIntern.make_form("bad_type", "Bender");

    std::cout << "Test case 2: Create Shrubbery Form" << std::endl;
    AForm *sh;
    sh = someRandonIntern.make_form("shrubbery", "Bender");

    std::cout << "Test case 3: Create Robotopmy Form" << std::endl;
    AForm *ro;
    ro = someRandonIntern.make_form("robotomy", "Bender");

    std::cout << "Test case 4: Create Presidential Form" << std::endl;
    AForm *pr;
    pr = someRandonIntern.make_form("presidential", "Bender");

    delete rrf;
    delete sh;
    delete ro;
    delete pr;
    return (0);
}