/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/08/07 21:53:33 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_CLASS_H
#define AMATERIA_CLASS_H

#include <iostream>

class AMateria
{
protected:
    std::string type;
public:
    AMateria(std::string const &type);
    virtual ~AMateria(void);
    //AMateria(const AMateria& other);
    //AMateria& operator=(const AMateria& other);

    //get&set
    std::string const& get_type() const{return this->type;} //Returns the metria type
    virtual AMateria* clone() const = 0;
    //virtual void use(ICharacter& target);
};


#define DEBUG 0
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