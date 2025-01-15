/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  AAForm.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:16 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/12/03 03:12:54 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.class.hpp"
#include "Bureaucrat.class.hpp"

/****************************************************/
/*                    Constructor                   */
/****************************************************/

AForm::AForm(std::string n, int gs, int ge): name(n), grade_to_sign(gs), grade_to_execute(ge)
{
    this->is_signed = false;
    if (this->grade_to_sign > 150 || this->grade_to_execute > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (this->grade_to_sign < 1 || this->grade_to_execute < 1)
        throw Bureaucrat::GradeTooHighException();
    if (DEBUG){ std::cout << GREEN << "[AForm] Default Constructor called" << RESET_COLOR << std::endl;}
}

AForm::AForm(const AForm& src): name(src.name), is_signed(src.is_signed), grade_to_sign(src.grade_to_sign), grade_to_execute(src.grade_to_execute)
{
    if (DEBUG){std::cout << GREEN << "[AForm] Copy Constructor called" << RESET_COLOR << std::endl;}
}

/****************************************************/
/*                    Destructor.                   */
/****************************************************/

AForm::~AForm(void) 
{
    if (DEBUG){std::cout << GREEN << "[AForm] Destructor called" << RESET_COLOR << std::endl;}
}

/****************************************************
*                    Overload                      *
****************************************************/


AForm&AForm::operator=(const AForm& rhs) 
{
    if (DEBUG){std::cout << GREEN << "[AForm] Copy assignment operator called" << RESET_COLOR << std::endl;}
    if (this != &rhs)
    {
        this->is_signed = rhs.get_signed_state();
    }
    return (*this);
}

/****************************************************
*                 Memeber Functions                *
****************************************************/

std::ostream &operator<<(std::ostream & o,AForm const &rhs)
{
    o << "AForm name: " << rhs.get_name() << "\nAForm state: " << rhs.get_signed_state() << "\nPermission to execute: " << rhs.get_grade_to_execute() << "\nPermission to sign: " << rhs.get_grade_to_sign() << std::endl;
    return o;
}

int AForm::be_signed(Bureaucrat &person)
{
    if (person.get_grade() > this->get_grade_to_sign())
    {
        throw Bureaucrat::GradeTooLowException();
        return (0);
    }
    else
    {
        this->is_signed = true;
    }
    return(1);
}