/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pmerge_me.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:16 by ytsyrend          #+#    #+#             */
/*   Updated: 2025/04/17 01:04:48 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pmerge_me.class.hpp"

/****************************************************/
/*                    Constructor                   */
/****************************************************/

Pmerge_me::Pmerge_me(int n) : number(n)
{
    if (DEBUG == 1)
    {
        std::cout << GREEN << "[Pmerge_me] Default Constructor called" << RESET_COLOR << std::endl;
    }
}

Pmerge_me::Pmerge_me(const Pmerge_me &other)
    : number(other.number), position(other.position)
{
    if (DEBUG == 1)
    {
        std::cout << GREEN << "[Pmerge_me] Copy Constructor called" << RESET_COLOR << std::endl;
    }
}

/****************************************************/
/*                    Destructor                    */
/****************************************************/

Pmerge_me::~Pmerge_me(void)
{
    if (DEBUG == 1)
    {
        std::cout << GREEN << "[Pmerge_me] Destructor called" << RESET_COLOR << std::endl;
    }
}

/****************************************************/
/*                    Overload                      */
/****************************************************/

Pmerge_me &Pmerge_me::operator=(const Pmerge_me &rhs)
{
    if (DEBUG == 1)
    {
        std::cout << GREEN << "[Pmerge_me] Copy assignment operator called" << RESET_COLOR << std::endl;
    }
    if (this != &rhs)
    {
        this->number = rhs.number;
        this->position = rhs.position;
    }
    return (*this);
}

/****************************************************/
/*                Member Functions                  */
/****************************************************/

std::vector<Pmerge_me>::iterator Pmerge_me::get_position() const
{
    return position;
}

void Pmerge_me::set_position(std::vector<Pmerge_me>::iterator it)
{
    position = it;
}


std::ostream& operator<<(std::ostream& os, const Pmerge_me& pm)
{
    os << pm.get_number();
    return os;
}