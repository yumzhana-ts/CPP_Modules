/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pmerge_me.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:16 by ytsyrend          #+#    #+#             */
/*   Updated: 2025/04/24 13:56:23 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pmerge_me.class.hpp"

/****************************************************/
/*                    Constructor                   */
/****************************************************/

PmergeMe::SingleNumber::SingleNumber(int n) : number(n) 
{
    if (DEBUG == 1)
    {
        std::cout << GREEN << "[PmergeMe] Constructor called" << RESET_COLOR << std::endl;
    }
}

PmergeMe::SingleNumber::SingleNumber(const PmergeMe::SingleNumber &other)
    : number(other.number), position(other.position)
{
    if (DEBUG == 1)
    {
        std::cout << GREEN << "[PmergeMe] Copy Constructor called" << RESET_COLOR << std::endl;
    }
}

/****************************************************/
/*                    Destructor                    */
/****************************************************/

PmergeMe::SingleNumber::~SingleNumber(void)
{
    if (DEBUG == 1)
    {
        std::cout << GREEN << "[PmergeMe] Destructor called" << RESET_COLOR << std::endl;
    }
}

/****************************************************/
/*                    Overload                      */
/****************************************************/

PmergeMe::SingleNumber &PmergeMe::SingleNumber::operator=(const PmergeMe::SingleNumber &rhs)
{
    if (DEBUG == 1)
    {
        std::cout << GREEN << "[PmergeMe] Copy assignment operator called" << RESET_COLOR << std::endl;
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

std::vector<PmergeMe::SingleNumber>::iterator PmergeMe::SingleNumber::get_position() const
{
    return position;
}

void PmergeMe::SingleNumber::set_position(std::vector<SingleNumber>::iterator it)
{
    position = it;
}

std::ostream& operator<<(std::ostream& os, const PmergeMe::SingleNumber& sn)
{
    os << sn.get_number();
    return os;
}

/****************************************************/
/*                Functions to save numbers         */
/****************************************************/

void save_numbers_to_vector(int argc, char **argv, std::vector<PmergeMe::SingleNumber> &vec)
{
    add_numbers_to_vector(argc, argv, vec);
    link_elements(vec);
    print_linked_list(vec);
}


void print_linked_list(const std::vector<PmergeMe::SingleNumber>& vec)
{
	std::cout << RED << "original vector " << RESET_COLOR;
    for (size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i].get_number();
        if (i < vec.size() - 1) 
        {
            std::cout << " -> ";
        }
    }
    std::cout <<  std::endl;
}

void link_elements(std::vector<PmergeMe::SingleNumber>& vec)
{
    for (size_t i = 0; i < vec.size(); ++i)
    {
        if (i > 0)
        {
            vec[i].set_position(vec.begin() + i);
        }

        if (i < vec.size() - 1)
        {
            vec[i].set_position(vec.begin() + i);
        }
    }
}

void add_numbers_to_vector(int argc, char **argv, std::vector<PmergeMe::SingleNumber>& vec)
{
    if (argc == 2)
    {
        std::string string;
        std::stringstream ss(argv[1]);

        while (std::getline(ss, string, ' '))
        {
            int num = std::atol(string.c_str());
            if (num >= 0 && num < INT_MAX)
            {
                vec.push_back(PmergeMe::SingleNumber(num));
            }
        }
    }
    else
    {
        std::cout << RED << "Error: Invalid input" << RESET_COLOR << std::endl;
    }
}

/****************************************************/
/*         Functions to make and sort pairs         */
/****************************************************/

