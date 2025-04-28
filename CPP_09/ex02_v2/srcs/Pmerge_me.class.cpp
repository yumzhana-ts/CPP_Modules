/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pmerge_me.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:16 by ytsyrend          #+#    #+#             */
/*   Updated: 2025/04/15 15:49:34 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pmerge_me.class.hpp"

/****************************************************/
/*                    Constructor                   */
/****************************************************/

Pmerge_me::Pmerge_me(int n) : number(n), it()
{
    if (DEBUG == 1)
    {
        std::cout << GREEN << "[Pmerge_me] Default Constructor called" << RESET_COLOR << std::endl;
    }
}
// Pmerge_me(std::string n = "Unkown"): name(n)

Pmerge_me::Pmerge_me(const Pmerge_me &src) : number(src.number), it(src.it)
{
    if (DEBUG == 1)
    {
        std::cout << GREEN << "[Pmerge_me] Copy Constructor called" << RESET_COLOR << std::endl;
    }
}

/****************************************************/
/*                    Destructor.                   */
/****************************************************/

Pmerge_me::~Pmerge_me(void)
{
    if (DEBUG == 1)
    {
        std::cout << GREEN << "[Pmerge_me] Destructor called" << RESET_COLOR << std::endl;
    }
}

/****************************************************
 *                    Overload                      *
 ****************************************************/

Pmerge_me &Pmerge_me::operator=(const Pmerge_me &rhs)
{
    if (DEBUG == 1)
    {
        std::cout << GREEN << "[Pmerge_me] Copy assignment operator called" << std::endl;
    }
    if (this != &rhs)
    {
        this->number = rhs.number;
        this->it = rhs.it;
    }
    return (*this);
}

/****************************************************
 *                 Memeber Functions                *
 ****************************************************/


int Pmerge_me::get_pair_index(std::vector<Pmerge_me> &chain)
{
    return(this->get_iterator() - chain.begin());
}

void debug(const std::string& str)
{
    if(DEBUG == 2)
    {
        std::cout << GREEN << "[DEBUG] " << str << RESET_COLOR << std::endl;
    }
}