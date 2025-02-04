#include "ScalarConverter.class.hpp"

s_data_types get_value(std::string str)
{
    size_t i = 0;
    while(i < str.size())
    {
        if (std::isprint(str[i]) > 0 && !std::isdigit(str[i]) && str[i] != '-' &&  str[i] != '.')
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
    return(int_type);
}


s_data_types get_type(std::string argument)
{
    std::cout << "step 1: processing argument\n";
    if (argument.length() == 1 && std::isprint(argument[0]) > 0 && !std::isdigit(argument[0]))
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
            std::cout << "step 2. converting to int type\n";
            values.int_value = std::atoll(argument.c_str());
            break;
        case(float_type):
            std::cout << "step 2. converting to float type\n"; 
            //ranges or edge cases 
            values.float_value = static_cast<float>(std::atof(argument.c_str()));
            break;
        case(double_type):
            std::cout << "step 2. converting to double type\n";
            //ranges or edge cases 
            values.double_value = std::atof(argument.c_str());
            break;
        case(char_type):
            std::cout << "step 2. converting to char type\n";
            //ranges or edge cases
            values.char_value = *(const_cast<char *>(argument.c_str()));
            break;
        case(inff_plus):
            std::cout << "step 2. converting to inff+ type\n";
            values.float_value = std::numeric_limits<float>::infinity();
            break;
        case(undefined_type):
            std::cout << "step 2. converting undefined type\n";
            return (values);
        default:
            std::cout << "dance dance dance" << std::endl;
    }
    return values;
}


void print_conversion(s_data data)
{
    std::cout << GREEN "\n--- conversions ---\n" << RESET_COLOR;
    if(data.c)
        std::cout << "char: '" << data.c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << data.i << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << data.f << "f\n";
    std::cout << "double: " << std::fixed << std::setprecision(1) << data.d << '\n';
}
