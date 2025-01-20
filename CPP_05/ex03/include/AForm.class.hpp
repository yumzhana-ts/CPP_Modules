/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  AForm.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/12/03 02:58:56 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_CLASS_H
#define AForm_CLASS_H

#include <iostream>
#include "Bureaucrat.class.hpp"

class Bureaucrat;

class AForm
{
private:
    const       std::string name;
    bool        is_signed;
    const int   grade_to_sign;
    const int   grade_to_execute;
public:
    AForm(std::string n, int gs, int ge);
    virtual ~AForm(void);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);

    //get&set
    std::string get_name(void) const {return (this->name);}
    bool get_signed_state(void) const {return (this->is_signed);}
    int get_grade_to_sign(void) const {return (this->grade_to_sign);}
    int get_grade_to_execute(void) const {return (this->grade_to_execute);}
    int be_signed(Bureaucrat &person);
    int is_executable(Bureaucrat &person);
    virtual void execute() const = 0;
};

std::ostream &operator<<(std::ostream & o,AForm const &rhs);

#define DEBUG 1
// Define ANSI escape sequences for colors
#define RESET_COLOR "\033[0m"
#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define BLUE "\033[0;34m"
#define WHITE "\033[0;37m"
#define BOLD_BLACK "\033[1;30m"
#define BG_WHITE "\033[0;47m"
#endif