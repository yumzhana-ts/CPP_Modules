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


void read_and_process_file(BitcoinExchange &btc, std::string file, char delimeter)
{
    std::ifstream ifs(file.c_str());
    if (!ifs.is_open())
    {
        std::cerr << "\033[31mError: Error opening original file.\033[0m" << std::endl;
        exit(1);
    }
    else
    {
        if (file == "files/data.csv")
            store_db(ifs, delimeter, btc);
        else
            evaluate_prices(ifs, delimeter, btc);
    }
    ifs.close();    
}


inline bool is_valid_date(const std::string &str)
{
    std::tm t;
    memset(&t, 0, sizeof(t));
    std::stringstream ss(str);
    char dash_1, dash_2;
    if (!(ss >> t.tm_year >> dash_1 >> t.tm_mon >> dash_2 >> t.tm_mday) || (dash_1 != '-' || dash_2 != '-'))
        return false;
    else if (t.tm_year < 1900 || t.tm_year > 2100)
        return false;
    else if (t.tm_mon < 1 || t.tm_mon > 12)
        return false;
    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (t.tm_year % 4 == 0 && (t.tm_year % 100 != 0 || t.tm_year % 400 == 0))
        days_in_month[1] = 29;
    if (t.tm_mday < 1 || t.tm_mday > days_in_month[t.tm_mon - 1])
        return false;
    return true;
}

void store_db(std::ifstream &ifs, char c, BitcoinExchange &btc)
{
    std::string line;
    while (std::getline(ifs, line))
    {
        std::stringstream ss(line);
        std::string date, value;
        
        if (std::getline(ss, date, c) && std::getline(ss, value))
        {
            float num = static_cast<float>(atof(value.c_str()));
            if (!date.empty() && !value.empty() &&
                (num >= 0 && num < __FLT_MAX__) &&
                is_valid_date(date))
            {
                btc.get_map().insert(std::make_pair(date, value));
            }
        }
    }
    //std::cout << btc;
}

void evaluate_prices(std::ifstream &ifs, char c, BitcoinExchange &btc)
{
    std::string line;
    std::getline(ifs, line);
    while (std::getline(ifs, line))
    {
        process_line(line, c, btc);
    }
}


void process_line(const std::string &line, char c, BitcoinExchange &btc)
{
    std::stringstream ss(line);
    std::string date, value;
    
    if (!std::getline(ss, date, c) || !std::getline(ss, value) || date.empty() || value.empty() || !is_valid_date(date))
    {
        std::cout << "Error: bad input => " << line << std::endl;
        return;
    }
    
    float num = static_cast<float>(std::atof(value.c_str()));
    if (num < 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return;
    }
    if (num > 1000)
    {
        std::cout << "Error: too large a number." << std::endl;
        return;
    }
    (void)btc;
    evaluate_price(date, num, btc.get_map());
}

void evaluate_price(const std::string &date, float num, const std::map<std::string, std::string> &data)
{
    try
    {
        std::time_t input_time = string_to_time(date);
        double min_diff = std::numeric_limits<double>::max();
        float price = 0.0f;
        std::string exchange_date;
        
        for (std::map<std::string, std::string>::const_iterator it = data.begin(); it != data.end(); ++it) 
        {
            time_t data_time = string_to_time(it->first);
            if (data_time <= input_time) 
            {
                double diff = std::difftime(input_time, data_time);
                if (diff < min_diff) 
                {
                    min_diff = diff;
                    price = static_cast<float>(std::atof(it->second.c_str()));
                    exchange_date = it->first;
                }
            }
        }
        std::cout << date << " => " << num << " = " << num * price;
        //std::cout << " (" << exchange_date << ")" << std::endl;
        std::cout << std::endl;
    }
    catch(BitcoinExchange::Exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}



std::time_t string_to_time(const std::string &str)
{
    std::tm t = {};
    std::istringstream ss(str);
    char dash_1, dash_2;
    if (!(ss >> t.tm_year >> dash_1 >> t.tm_mon >> dash_2 >> t.tm_mday) || (dash_1 != '-' || dash_2 != '-'))
        throw std::invalid_argument("incorrect format: " + str);
    t.tm_year -= 1900;
    t.tm_mon -= 1;
    time_t result = std::mktime(&t);
    if (result == -1)
        throw std::runtime_error("incorrect conversion: " + str);
    return result;
}
