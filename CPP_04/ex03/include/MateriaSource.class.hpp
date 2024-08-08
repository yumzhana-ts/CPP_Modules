/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.class.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/08/07 21:53:33 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_CLASS_H
#define MATERIASOURCE_CLASS_H
#include "IMateriaSource.class.hpp"

#include <iostream>

class MateriaSource: public IMateriaSource
{
private:
    AMateria* materia_array[4];
public:
    MateriaSource(void);
    ~MateriaSource(void);
    MateriaSource(const MateriaSource& other);
    MateriaSource& operator=(const MateriaSource& other);


    virtual void learn_materia(AMateria*);
    virtual void print_materia();
    virtual AMateria* create_Materia(std::string const & type);
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