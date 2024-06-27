#include "movies.hpp"
#include "movie.hpp"
#include <iostream>

// constructor
Movies::Movies()
{
}

// destructor
Movies::~Movies()
{
}

bool Movies::add_movie(std::string name, std::string rating, int watched)
{
    for (std::vector<Movie>::const_iterator it = movies.begin(); it != movies.end(); ++it)
    {
        if (it->get_name() == name)
            return false;
    }
    Movie temp(name, rating, watched);
    movies.push_back(temp);
    return (true);
}
/* 
bool Movies::increment_watched(const std::string &name)
{
    for (std::vector<Movie>::iterator it = movies.begin(); it != movies.end(); ++it)
    {
        if (it->get_name() == name)
        {
            it->increment_watched();
            return true;
        }
    }
    return false;
} */

void Movies::display() const
{
    if (movies.size() == 0)
    {
        std::cout << "Sorry, no movies to display\n"
                  << std::endl;
    }
    else
    {
        std::cout << "\n===================================" << std::endl;
        for (std::vector<Movie>::const_iterator it = movies.begin(); it != movies.end(); ++it)
            it->display();
        std::cout << "\n===================================" << std::endl;
    }
}
