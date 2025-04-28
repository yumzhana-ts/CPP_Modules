/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2025/04/01 21:10:52 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BitcoinExchangeLASS_H
#define BitcoinExchangeLASS_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <utility>

//TODO:parsing, verification, processing

//TODO: remove exception
//TODO: make !ss.eof() work
//TODO: make path better

class BitcoinExchange
{
private:
    std::string date;
    std::string value;
    BitcoinExchange(void);
public:
    BitcoinExchange(std::string d, std::string v);
    ~BitcoinExchange(void);
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);

    class Exception : public std::exception
    {
    private:
        const char* message;
    public:
        Exception(const char* msg) : message(msg){}
        const char* what() const throw() { return message; }
    };

    std::string get_date(void) const {return (this->date);}
    std::string get_value(void) const {return (this->value);}
};


bool is_valid_date(const std::string &str);
void read_and_process_file(std::vector<BitcoinExchange> &data, std::string file, char delimeter);
void store_db(std::ifstream &ifs, char c, std::vector<BitcoinExchange> &super_test_vec);
void evaluate_prices(std::ifstream &ifs, char c, const std::vector<BitcoinExchange> &data);
std::time_t string_to_time(const std::string &str);
void evaluate_price(const std::string &date, float num, const std::vector<BitcoinExchange> &data);
void process_line(const std::string &line, char c, const std::vector<BitcoinExchange> &data);

std::ostream &operator<<(std::ostream & o, BitcoinExchange const &rhs);


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