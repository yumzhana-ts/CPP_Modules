# ifndef _movies_
#define _movies_
#include <vector>
#include <string>
#include "movie.hpp"

class Movies
{
private:
    std::vector<Movie> movies;
public:
    Movies();
    ~Movies();

    bool add_movie(std::string name, std::string rating, int count);
   //bool increment_watched(const std::string &name);
    void display() const;
};

#endif
