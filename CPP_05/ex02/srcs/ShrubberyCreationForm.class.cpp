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

#include "ShrubberyCreationForm.class.hpp"

/****************************************************/
/*                    Constructor                   */
/****************************************************/

ShrubberyCreationForm::ShrubberyCreationForm(std::string t): target(t), AForm("Shrubbery", 145, 137) 
{
    if (DEBUG){ std::cout << GREEN << "[ShrubberyCreationForm] Default Constructor called" << RESET_COLOR << std::endl;}
}
//ShrubberyCreationForm(std::string n = "Unkown"): name(n)

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src): target(src.target), AForm("Shrubbery", 145, 137)
{
    if (DEBUG){std::cout << GREEN << "[ShrubberyCreationForm] Copy Constructor called" << RESET_COLOR << std::endl;}
    //*this = src;
}

/****************************************************/
/*                    Destructor.                   */
/****************************************************/

ShrubberyCreationForm::~ShrubberyCreationForm(void) 
{
    if (DEBUG){std::cout << GREEN << "[ShrubberyCreationForm] Destructor called" << RESET_COLOR << std::endl;}
}

/****************************************************
*                    Overload                      *
****************************************************/


ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs) 
{
    //if (DEBUG){std::cout << GREEN << "[ShrubberyCreationForm] Copy assignment operator called" << std::endl;}

    return (*this);
}

/****************************************************
*                 Memeber Functions                *
****************************************************/
