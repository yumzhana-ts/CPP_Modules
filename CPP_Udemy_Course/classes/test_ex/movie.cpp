#include "movie.hpp"
#include <string>
#include <iostream>

//constructor
Movie::Movie(std::string name, std::string rating, int count)
    : movie_name(name), movie_rating(rating), watched(count){}

//copy constructor
/* Movie::Movie(const Movie &source)
    : Movie(source.movie_name, source.movie_rating, source.watched){} */

//desctructor
Movie::~Movie(){}

void Movie::display() const 
{
    std::cout << movie_name << " , " << movie_rating << " , " << watched << std::endl;
}
