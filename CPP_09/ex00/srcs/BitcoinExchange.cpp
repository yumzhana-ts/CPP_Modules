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

BitcoinExchange::BitcoinExchange(void) 
{
    if (DEBUG){ std::cout << GREEN << "[BitcoinExchange] Default Constructor called" << RESET_COLOR << std::endl;}
}

BitcoinExchange::BitcoinExchange(std::string d, std::string v): date(d), value(v)
{
    if (DEBUG){ std::cout << GREEN << "[BitcoinExchange] Default Constructor called" << RESET_COLOR << std::endl;}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src): date(src.date), value(src.value)
{
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
        this->date = rhs.date;
        this->value = rhs.value;
    }
    return (*this);
}

/****************************************************
*                 Memeber Functions                *
****************************************************/

std::ostream &operator<<(std::ostream & o, BitcoinExchange const &rhs)
{
    o << rhs.get_date() << " | " << rhs.get_value() << std::endl;
    return o;
}

