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
    BitcoinExchange obj1;
    BitcoinExchange obj2(obj1);
    BitcoinExchange obj3;
    obj3 = obj2;
}

int main(int argc, char** argv)
{
    test_orth();
    if (argc == 2) 
    {
        BitcoinExchange btc;
        read_and_process_file(btc, "files/data.csv", ',');
        read_and_process_file(btc, argv[1], '|');
    }
    else
    {
        std::cout << "Error: could not open file." << std::endl;
    }
    return (0);
}