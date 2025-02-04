#include "ScalarConverter.class.hpp"
#include <string>
#include <cstdlib>

s_data_types get_value(std::string str)
{
    size_t i = 0;
    while(i < str.size())
    {
        if (std::isalpha(str[i]) > 0)
            return(undefined_type);
        else if (str[i] == '-' || std::isdigit(str[i]) > 0 )
            i++;
        else if (str[i] == '.')
        {
            i++;
            while(std::isdigit(str[i]) > 0)
            {
                i++;
                if (str[i] == 'f'&& i+1 == str.size())
                    return(float_type);
                else if (i == str.size())
                    return(double_type);                    
            }
            return(undefined_type);
        }
    }
    std::cout << "i will probably do mess when typecasing, cus i accept non printable shit" << std::endl;
    return(int_type);
}

s_data_types get_type(std::string argument)
{
    if (argument.length() == 1 && std::isalpha(argument[0]) > 0)
        return (char_type);
    else if (argument == "-inff")
        return (inff_minus);
    else if (argument == "+inff")
        return (inff_plus);
    else if (argument == "nanf")
        return (nanf_type);
    else if (argument == "-inf")
        return (inf_minus);
    else if (argument == "+inf")
        return (inf_plus);
    else if (argument == "nan")
        return (nan_type);
    else
        return(get_value(argument));
}

s_data_values type_conversion(s_data_types type, std::string argument)
{
    s_data_values values;
    switch(type)
    {
        case(int_type):
            values.int_value = std::atoi(argument.c_str());
            break;
        case(float_type):
            std::cout << "we are processsing fucking float" << std::endl;
            values.float_value = (float)std::atof(argument.c_str());
            break;
        case(double_type):
            values.double_value = std::atof(argument.c_str());
            break;
        case(char_type):
            values.char_value = argument.c_str();
            break;
        default:
            std::cout << "dance dance dance" << std::endl;
    }
    return values;
}

