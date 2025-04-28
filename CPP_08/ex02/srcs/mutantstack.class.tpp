/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.class.tpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:16 by ytsyrend          #+#    #+#             */
/*   Updated: 2025/03/27 23:37:18 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/****************************************************/
/*                    Constructor                   */
/****************************************************/

#include "mutantstack.class.hpp"

template <typename T>
MutantStack<T>::MutantStack(void) : std::stack<T>()
{
    if (DEBUG){ std::cout << GREEN << "[MutantStack] Default Constructor called" << RESET_COLOR << std::endl;}
}
//MutantStack(std::string n = "Unkown"): name(n)


template <typename T>
MutantStack<T>::MutantStack(const MutantStack& other) : std::stack<T>(other)
{
    if (DEBUG){std::cout << GREEN << "[MutantStack] Copy Constructor called" << RESET_COLOR << std::endl;}
    *this = other;
}

/****************************************************/
/*                    Destructor.                   */
/****************************************************/
template <typename T>
MutantStack<T>::~MutantStack(void) 
{
    if (DEBUG){std::cout << GREEN << "[MutantStack] Destructor called" << RESET_COLOR << std::endl;}
}

/****************************************************
*                    Overload                      *
****************************************************/

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T>& rhs) 
{
    if (DEBUG){std::cout << GREEN << "[MutantStack] Copy assignment operator called" << RESET_COLOR << std::endl;}
    if (this != &rhs)
    {
        
    }
    return (*this);
}

/****************************************************
*                 Memeber Functions                *
****************************************************/
