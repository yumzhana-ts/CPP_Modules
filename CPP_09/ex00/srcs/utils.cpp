#include "BitcoinExchange.hpp"

void read_and_process_file(std::vector<BitcoinExchange> &data, std::string file, char delimeter)
{
    std::ifstream ifs(file);
    if (!ifs.is_open())
    {
        std::cerr << "\033[31mError: Error opening original file.\033[0m" << std::endl;
        exit(1);
    }
    else
    {
        //TODO: better logic here
        if (file == "files/data.csv")
            store_db(ifs, delimeter, data);
        else
            evaluate_prices(ifs, delimeter, data);
    }
    ifs.close();
}

void print_vec(std::vector<BitcoinExchange> &super_test_vec)
{
    for (size_t i = 0; i < super_test_vec.size(); i++)
    {
        std::cout << super_test_vec[i];
    }
}

bool is_valid_date(const std::string &str)
{
    std::tm t;
    std::memset(&t, 0, sizeof(t));
    std::stringstream ss(str);
    char dash_1, dash_2;
    if (!(ss >> t.tm_year >> dash_1 >> t.tm_mon >> dash_2 >> t.tm_mday) || (dash_1 != '-' || dash_2 != '-'))
        return false;
    //|| !ss.eof()
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

void store_db(std::ifstream &ifs, char c, std::vector<BitcoinExchange> &super_test_vec)
{
    std::string line;
    while (std::getline(ifs, line))
    {
        std::stringstream ss(line);
        std::string date, value;
        
        if (std::getline(ss, date, c) && std::getline(ss, value))
        {
            float num = static_cast<float>(std::atof(value.c_str()));
            if (!date.empty() && !value.empty() &&
                (num >= 0 && num < __FLT_MAX__) &&
                is_valid_date(date))
            {
                BitcoinExchange pair(date, value);
                super_test_vec.push_back(pair);
            }
        }
    }
    //print_vec(super_test_vec);
}


void process_line(const std::string &line, char c, const std::vector<BitcoinExchange> &data)
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
    evaluate_price(date, num, data);
}

void evaluate_price(const std::string &date, float num, const std::vector<BitcoinExchange> &data)
{
    try
    {
        std::time_t input_time = string_to_time(date);
        double min_diff = std::numeric_limits<double>::max();
        float price = 0.0f;
        std::string exchange_date;
        
        for (std::vector<BitcoinExchange>::const_iterator it = data.begin(); it != data.end(); ++it) 
        {
            time_t data_time = string_to_time(it->get_date());
            if (data_time <= input_time) 
            {
                double diff = std::difftime(input_time, data_time);
                if (diff < min_diff) 
                {
                    min_diff = diff;
                    price = static_cast<float>(std::atof(it->get_value().c_str()));
                    exchange_date = it->get_date();
                }
            }
        }
        std::cout << date << " => " << num << " = " << num * price;
        std::cout << " (" << exchange_date << ")" << std::endl;
    }
    catch(BitcoinExchange::Exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

void evaluate_prices(std::ifstream &ifs, char c, const std::vector<BitcoinExchange> &data)
{
    std::string line;
    while (std::getline(ifs, line))
    {
        process_line(line, c, data);
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