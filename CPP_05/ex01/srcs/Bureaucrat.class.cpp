/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:16 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/12/01 22:51:46 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.class.hpp"
#include "Form.class.hpp"

/****************************************************/
/*                    Constructor                   */
/****************************************************/

Bureaucrat::Bureaucrat(int g, const std::string n) : name(n), grade(g)
{
    if (DEBUG)
    {
        std::cout << GREEN << "[Bureaucrat] Default Constructor called" << RESET_COLOR << std::endl;
    }
    if (this->grade > 150)
        throw GradeTooLowException();
    else if (this->grade < 1)
        throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : name(src.name), grade(src.grade) // Copy both members directly
{
    if (DEBUG)
    {
        std::cout << GREEN << "[Bureaucrat] Copy Constructor called" << RESET_COLOR << std::endl;
    }
}

/****************************************************/
/*                    Destructor.                   */
/****************************************************/

Bureaucrat::~Bureaucrat(void)
{
    if (DEBUG)
    {
        std::cout << GREEN << "[Bureaucrat] Destructor called" << RESET_COLOR << std::endl;
    }
}

/****************************************************
 *                    Overload                      *
 ****************************************************/

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
    if (DEBUG)
    {
        std::cout << GREEN << "[Bureaucrat] Copy assignment operator called" RESET_COLOR << std::endl;
    }
    if (this != &rhs)
    {
        this->grade = rhs.get_grade();
    }
    return (*this);
}

/****************************************************
 *                 Memeber Functions                *
 ****************************************************/

void Bureaucrat::increment_grade()
{
    this->grade -= 1;
    if (this->grade <= 1)
    {
        this->grade = 1;
        throw GradeTooHighException();
    }
    std::cout << BLUE "Bureaucrat is successfully leveled up" RESET_COLOR << std::endl;
}

void Bureaucrat::decrement_grade()
{
    this->grade += 1;
    if (this->grade > 150)
    {
        this->grade = 150;
        throw GradeTooLowException();
    }
    std::cout << BLUE "Bureaucrat is successfully leveled down" RESET_COLOR << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return (RED"Error: Grade out of range, must be more then 1"RESET_COLOR);
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return (RED"Error: Grade out of range, must be less then 150"RESET_COLOR);
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs)
{
    o << rhs.get_name() << ", bureaucrat grade " << rhs.get_grade();
    return o;
}

void Bureaucrat::sign_form(Form &form)
{
    try
    {
        form.be_signed(*this);
        std::cout << this->name << " signed " << form.get_name() << std::endl;
    }
    catch(Bureaucrat::GradeTooLowException &e)
    {
        std::cout << this->name << " couldnt sign " << form.get_name() <<  " because of ";
        std::cout << e.what() << std::endl;
    }  
}