#include <iostream> //input and output library
#include <vector>

int main()
{
    char m;

    std::vector<int> vec;
    bool loop = true;
    while (loop == true)
    {
        std::cout << "Enter choice: " << std::endl;
        std::cin >> m;
        switch (m)
        {
        case 'p':
        case 'P':
            if (vec.size() > 0)
            {
                std::cout << "[";
                for (int i = 0; i < (int)vec.size(); i++)
                    std::cout << vec[i] << " ";
                std::cout << "]" << std::endl;
            }
            else
                std::cout << "[] - the list is empty" << std::endl;
            break;
        case 'a':
        case 'A':
            int n;
            std::cout << "Enter number: ";
            std::cin >> n;
            vec.push_back(n);
            std::cout << n << " is added" << std::endl;
            break;
        case 'm':
        case 'M':
            if (vec.size() > 0)
            {
                int result = 0;
                for (int i = 0; i < (int)vec.size(); i++)
                    result += vec[i];
                std::cout << (result / vec.size()) << std::endl;
            }
            else
                std::cout << "Unable to calculate mean - no data";
            break;
        case 's':
        case 'S':
            if (vec.size() > 0)
            {
                int smallest = vec[0];
                for (int i = 0; i < (int)vec.size(); i++)
                {
                    if (vec[i] <= smallest)
                        smallest = vec[i];
                }
                std::cout << "Smallest number: " << smallest << std::endl;
            }
            else
                std::cout << "Unable to find smallest - no data";
            break;
        case 'l':
        case 'L':
            if (vec.size() > 0)
            {
                int largest = vec[0];
                for (int i = 0; i < (int)vec.size(); i++)
                {
                    if (vec[i] >= largest)
                        largest = vec[i];
                }
                std::cout << "Largest number: " << largest << std::endl;
            }
            else
                std::cout << "Unable to find largest - no data";
            break;
        case 'q':
        case 'Q':
            loop = false;
            break;
        case 'v':
            if (vec.size() > 0)
            {
                int n;
                int o = 0;
                std::cout << "Enter number to find occurance" << std::endl;
                std::cin >> n;
                for (int i = 0; i < (int)vec.size(); i++)
                {
                    if (vec[i] == n)
                        o++;
                }
                std::cout << "occurance of " << n << "is " << o << std::endl;
            }
            else
                std::cout << "no data";
            break;
        case 'e':
            if (vec.size() > 0)
            {
                vec.clear();
                std::cout << "list is empty" << std::endl;
            }
            else
                std::cout << "no data";
            break;
        default:
            std::cout << "Unknown" << std::endl;
            break;
        }
    }
}
