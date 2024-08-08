/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/08/07 23:29:52 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_CLASS_H
#define CHARACTER_CLASS_H

#include <iostream>
#include "ICharacter.class.hpp"
#include "MateriaSource.class.hpp"
#include "AMateria.class.hpp"

class Character: public ICharacter
{
private:
    std::string name;
    AMateria* inventory[4];
    static AMateria* floor[3];
public:
    Character(std::string name);
    ~Character(void);
    Character(const Character& other);
    Character& operator=(const Character& other);


    virtual std::string const & get_name() const{return(this->name);}
    virtual void equip(AMateria* m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter& target);
    void print_inventory() const;
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