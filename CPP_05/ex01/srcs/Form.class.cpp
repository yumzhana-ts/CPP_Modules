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

/****************************************************/
/*                    Constructor                   */
/****************************************************/

Form::Form(std::string n, bool s, int gs, int ge): name(n), is_signed(s), grade_to_sign(gs), grade_to_execute(ge)
{
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
    if (DEBUG){std::cout << GREEN << "[Form] Copy assignment operator called" << std::endl;}
    if (this != &rhs)
        this->value = rhs.get_value();
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
    o << rhs.get_name() << ", bureaucrat grade " << rhs.get_grade();
    return o;
}