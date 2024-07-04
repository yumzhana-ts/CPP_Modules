#include <iostream>
#include <fstream>
#include <string>

void read_file(std::ifstream &ifs) 
{
    std::string line;
    while (std::getline(ifs, line)) 
    {
        std::cout << line << std::endl;
    }
}

int copy_and_replace(std::ifstream &ifs, std::string search, std::string replace)
{
    std::ofstream ofs("test.replace");
    if (!ofs.is_open())
        return (1);
    else
    {
        ifs.clear(); // Clear the EOF find
        ifs.seekg(0, std::ios::beg); // Seek to the beginning of the file
        int f_size = search.length();

        std::cout << "\033[31m...copying file...\033[0m" << std::endl; 
        std::string line;
        bool find = false; 
        while (std::getline(ifs, line))
        {
            size_t position = line.find(search);
            if (position != std::string::npos) 
            {
                find = true;
                line.erase(position, f_size);
                line.insert(position, replace);
            }
            ofs << line << std::endl;
        }
        if(find == true)
            std::cout << "\033[31m...string is replaced from '" << search << "' to '" << replace << "'...\033[0m" << std::endl;
        else
            std::cout << "\033[31m...string to replace was not found...\033[0m" << std::endl;        
        ofs.close();
    }
    return (0);
}

int main()
{
    std::cout << "\033[31m...reading original file...\033[0m" << std::endl; 
    std::ifstream ifs("test.out");
    if (!ifs.is_open()) 
    {
        std::cerr << "\033[31mError: Error opening original input file.\033[0m" << std::endl;
        return (1);
    }
    else
        read_file(ifs);

    if (copy_and_replace(ifs, "love", "marshmellow"))
    {
        std::cerr << "\033[31mError: Error opening output file.\033[0m" << std::endl;
        return (1);
    }
    std::cout << "\033[31m...reading copied file...\033[0m" << std::endl;
    std::ifstream ifsr("test.replace");
    if (!ifs.is_open()) 
    {
        std::cerr << "\033[31mError: Error opening original input file.\033[0m" << std::endl;
        return (1);
    }
    else
        read_file(ifsr);
    
    ifs.close();
    ifsr.close();
    return(0);
}