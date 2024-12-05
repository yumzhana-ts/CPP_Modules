/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:16 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/12/03 03:12:54 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.class.hpp"
#include "Bureaucrat.class.hpp"

/****************************************************/
/*                    Constructor                   */
/****************************************************/

Form::Form(std::string n, int gs, int ge): name(n), grade_to_sign(gs), grade_to_execute(ge)
{
    this->is_signed = false;
    if (this->grade_to_sign > 150 || this->grade_to_execute > 150)
        throw GradeTooLowException();
    else if (this->grade_to_sign < 1 || this->grade_to_execute < 1)
        throw GradeTooHighException();
    if (DEBUG){ std::cout << GREEN << "[Form] Default Constructor called" << RESET_COLOR << std::endl;}
}

Form::Form(const Form& src): name(src.name), is_signed(src.is_signed), grade_to_sign(src.grade_to_sign), grade_to_execute(src.grade_to_execute)
{
    if (DEBUG){std::cout << GREEN << "[Form] Copy Constructor called" << RESET_COLOR << std::endl;}
}

/****************************************************/
/*                    Destructor.                   */
/****************************************************/

Form::~Form(void) 
{
    if (DEBUG){std::cout << GREEN << "[Form] Destructor called" << RESET_COLOR << std::endl;}
}

/****************************************************
*                    Overload                      *
****************************************************/


Form& Form::operator=(const Form& rhs) 
{
    if (DEBUG){std::cout << GREEN << "[Form] Copy assignment operator called" << RESET_COLOR << std::endl;}
    if (this != &rhs)
    {
        this->is_signed = rhs.get_signed_state();
    }
    return (*this);
}

/****************************************************
*                 Memeber Functions                *
****************************************************/

const char* Form::GradeTooHighException::what() const throw()
{
    return("Error: Grade out of range, must be more then 1");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return("Error: Grade out of range, must be less then 150");
}

std::ostream &operator<<(std::ostream & o, Form const &rhs)
{
    o << "Form name: " << rhs.get_name() << "\nForm state: " << rhs.get_signed_state() << "\nPermission to execute: " << rhs.get_grade_to_execute() << "\nPermission to sign: " << rhs.get_grade_to_sign() << std::endl;
    return o;
}

void Form::be_signed(Bureaucrat const &person)
{
    if (person.get_grade() > this->get_grade_to_sign())
        throw GradeTooLowException();
    else
        this->is_signed = true;
}