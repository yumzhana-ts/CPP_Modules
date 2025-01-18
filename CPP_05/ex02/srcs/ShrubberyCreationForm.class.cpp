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

ShrubberyCreationForm::ShrubberyCreationForm(std::string t): AForm("Shrubbery", 145, 137), target(t)
{
    if (DEBUG){ std::cout << GREEN << "[ShrubberyCreationForm] Default Constructor called" << RESET_COLOR << std::endl;}
}
//ShrubberyCreationForm(std::string n = "Unkown"): name(n)

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src): AForm("Shrubbery", 145, 137), target(src.target) 
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
    if (DEBUG){std::cout << GREEN << "[ShrubberyCreationForm] Copy assignment operator called" << RESET_COLOR << std::endl;}
    if (this != &rhs)
    {
        this->target= rhs.get_target();
    }
    return (*this);
}

/****************************************************
*                 Memeber Functions                *
****************************************************/

int create_file(std::string target, int length);

void ShrubberyCreationForm::execute() const
{
    create_file(this->target, 31);
}



