#include <iostream> //input and output library
#include <vector>

int main()
{
    std::vector <int> vector1;
    std::vector <int> vector2;

    vector1.push_back(10);
    vector1.push_back(20);
    std::cout << vector1.at(0) << " " << vector1.at(1) << "size" << vector1.size() << std::endl;

    vector2.push_back(100);
    vector2.push_back(200);
    std::cout << vector2.at(0) << " " << vector2.at(1) << "size" << vector1.size() << std::endl;

    std::vector <std::vector <int> > vector2d;
    vector2d.push_back(vector1);
    vector2d.push_back(vector2);

    vector1.at(0) = 1000;

    std::cout << "vector2s" << vector2d.at(0).at(0) << std::endl;
    std::cout << "vector2s" << vector2d.at(0).at(1) << std::endl;
    std::cout << "vector2s" << vector2d.at(1).at(0) << std::endl;
    std::cout << "vector2s" << vector2d.at(1).at(1) << std::endl;

    std::cout << vector1.at(0) << std::endl;
    std::cout << vector1.at(1) << std::endl;

    std::vector <char> vec;
    vec.push_back('a');
    vec.push_back('e');

    int i = 0;
    bool found = false;
    do
    {
        if(vec.size() == 0)
            break;
        if (vec[i] == 'a' || vec[i] == 'e' || vec[i] == 'i' || vec[i] == 'o' || vec[i] == 'u')
        {
            found = true;
            std::cout << "Vowel found: " << vec[i] << std::endl;
        };
        i++;
    }
    while(i <= (int)vec.size() && found == false);
    if(found == false)
        std::cout << "No vowel was found";
}
