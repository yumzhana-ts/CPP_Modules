#include "ScalarConverter.class.hpp"
#include <string>

std::string get_value(std::string str)
{
    size_t i = 0;
    while(i < str.size())
    {
        if (std::isalpha(str[i]) > 0)
            return("undefined_type");
        else if (str[i] == '-' || std::isdigit(str[i]) > 0 )
            i++;
        else if (str[i] == '.')
        {
            i++;
            while(std::isdigit(str[i]) > 0)
            {
                i++;
                if (str[i] == 'f'&& i+1 == str.size())
                    return("float_type");
                else if (i == str.size())
                    return("double_type");                    
            }
            return("undefined");
        }
    }
    std::cout << "i will probably do mess when typecasing, cus i accept non printable shit" << std::endl;
    return("int_type");
}

std::string get_type(std::string argument)
{
    if (argument.length() == 1 && std::isalpha(argument[0]) > 0)
        return ("char_type");
    else if (argument == "-inff" || argument == "+inff" || argument == "-inf" || argument == "+inf" || argument == "nan")
        return(argument);
    else
        return(get_value(argument));
}

/*void type_conversion(enum Types type, std::string argument)
{
    switch(type)
    {
        case(int_type):
            int num = std::stoi(argument);
            return (int)num;
            break;
    }
}*/
