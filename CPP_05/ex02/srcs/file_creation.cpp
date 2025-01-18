#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>

void read_file(std::ifstream &ifs) 
{
    std::string line;
    while (std::getline(ifs, line)) 
    {
        std::cout << line << std::endl;
    }
}


int create_file(std::string target, int length)
{
    const char* str2 = "_shubbery";
    const char* str1 = target.c_str();
    char name[100];

    std::strcpy(name, str1);
    std::strcat(name, str2);

    std::ofstream ofs(name);
    if (!ofs.is_open())
        return (1);
    else
    {
        int count = 0;
        int space = length / 2;
        int cases = 1; 
        while(count <= (length/2 + 1))
        {
            int d = 0;
            while(d <= space)
            {
                ofs << " ";
                d++;
            }
            int c = 1;
            while(c <= cases)
            {
                ofs << static_cast<char>((rand() % 15) + 33);
                c++;
            }
            count++;
            space--;
            cases = cases + 2;
            ofs << std::endl;
        }
    }
    ofs.close();
    std::ifstream ifs(name);
    if (!ifs.is_open()) 
    {
        std::cerr << "\033[31mError: Error opening original input file.\033[0m" << std::endl;
        return (1);
    }
    else
        read_file(ifs);
    return (0);
}
