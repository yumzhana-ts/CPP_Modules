        /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/07/06 12:37:40 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RobotomyRequestForm_CLASS_H
#define RobotomyRequestForm_CLASS_H

#include <iostream>
#include "AForm.class.hpp"

class RobotomyRequestForm: public AForm
{
private:
    std::string target;
public:
    RobotomyRequestForm(std::string target);
    ~RobotomyRequestForm(void);
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

    std::string get_target(void) const {return (this->target);}
    void execute() const;
};


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