/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:16 by ytsyrend          #+#    #+#             */
/*   Updated: 2025/03/31 19:59:30 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/****************************************************/
/*                    Constructor                   */
/****************************************************/

BitcoinExchange::BitcoinExchange() 
{
    if (DEBUG){ std::cout << GREEN << "[BitcoinExchange] Default Constructor called" << RESET_COLOR << std::endl;}
}


BitcoinExchange::BitcoinExchange(const BitcoinExchange& src)
{
    this->btc = src.btc;
    if (DEBUG){std::cout << GREEN << "[BitcoinExchange] Copy Constructor called" << RESET_COLOR << std::endl;}
}

/****************************************************/
/*                    Destructor.                   */
/****************************************************/

BitcoinExchange::~BitcoinExchange(void) 
{
    if (DEBUG){std::cout << GREEN << "[BitcoinExchange] Destructor called" << RESET_COLOR << std::endl;}
}

/****************************************************
*                    Overload                      *
****************************************************/


BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs) 
{
    if (DEBUG){std::cout << GREEN << "[BitcoinExchange] Copy assignment operator called" << std::endl;}
    if (this != &rhs)
    {
        this->btc = rhs.btc;
    }
    return (*this);
}

/****************************************************
*                 Memeber Functions                *
****************************************************/

std::ostream &operator<<(std::ostream & o, BitcoinExchange &rhs)
{
    std::map<std::string, std::string>::iterator it = rhs.get_map().begin();
    for (; it != rhs.get_map().end(); it++)
    {
        o << "{" << it->first << ", " << it->second << "}" << std::endl;
    }
    return o;
}

