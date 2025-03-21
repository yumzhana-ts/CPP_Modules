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
            values.int_value = std::atoi(argument.c_str());
            std::cout << "converted type: "<< typeid(values.int_value).name();
            break;
        case(float_type):

            std::cout << "converted type: "<< typeid(values.float_value).name();
            values.float_value = static_cast<float>(std::atof(argument.c_str()));
            break;
        case(double_type):
            values.double_value = std::atof(argument.c_str());
            break;
        case(char_type):
            std::cout << "converted type: "<< typeid(values.char_value).name();
            values.char_value = *(const_cast<char *>(argument.c_str()));
            break;
        case(inff_plus):
            std::cout << "converted type: "<< typeid(values.float_value).name();
            values.float_value = std::numeric_limits<float>::infinity();
            break;
        case(inff_minus):
            std::cout << "converted type: "<< typeid(values.float_value).name();
            values.float_value = -std::numeric_limits<float>::infinity();
            break;
        case(inf_plus):
            std::cout << "converted type: "<< typeid(values.double_value).name();
            values.double_value = std::numeric_limits<double>::infinity();
            break;
        case(inf_minus):
            std::cout << "converted type: "<< typeid(values.double_value).name();
            values.double_value = -std::numeric_limits<double>::infinity();
            break;
        case(nanf_type):
            std::cout << "converted type: "<< typeid(values.float_value).name();
            values.float_value = std::numeric_limits<float>::quiet_NaN();;
            break;
        case(nan_type):
            std::cout << "converted type: "<< typeid(values.double_value).name();
            values.double_value = std::numeric_limits<double>::quiet_NaN();;
            break;
        case(undefined_type):
            break;
        default:
            std::cout << "dance dance dance" << std::endl;
    }
    return values;
}


void print_conversion(s_data data)
{
    std::cout << GREEN "\n--- conversions ---\n" << RESET_COLOR;
    if (!data.c)
        std::cout << "char: Impossible" << std::endl;
    else if (data.c >= 33 && data.c <= 126)
        std::cout << "char: '" << data.c << "'" << std::endl;
    else 
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << data.i << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << data.f << "f\n";
    std::cout << "double: " << std::fixed << std::setprecision(1) << data.d << '\n';
}

void print_conversion_edge_cases(s_data data)
{
    std::cout << GREEN "\n--- conversions ---\n" << RESET_COLOR;
    std::cout << "char: Impossible" << std::endl;
    std::cout << "int: Impossible" << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << data.f << "f\n";
    std::cout << "double: " << std::fixed << std::setprecision(1) << data.d << '\n';
}
