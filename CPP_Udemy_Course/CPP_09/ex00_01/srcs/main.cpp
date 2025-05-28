/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:41:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2025/04/01 00:07:22 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void test_orth()
{
    BitcoinExchange obj1("q","q"); // Default Constructor called
    BitcoinExchange obj2(obj1); // Copy Constructor called
    BitcoinExchange obj3("q","q");
    obj3 = obj2; // Copy Assignment Operator called
}

int main(int argc, char** argv)
{
    if (argc == 2) 
    {
        std::vector<BitcoinExchange> db;
        read_and_process_file(db, "files/data.csv", ',');
        read_and_process_file(db, argv[1], '|');
    }
    else
    {
        std::cout << "Error: could not open file." << std::endl;
    }
    return (0);
}