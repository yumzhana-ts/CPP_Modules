# ifndef movie
#define movie
#include <string>

class Movie
{
private:
    std::string movie_name;   // the name of the movie
    std::string movie_rating;   // the movie rating G,PG, PG-13, R
    int watched;          // the number of times you've watched the movie
public:
    // Constructor - expects all 3 movie attributes
    Movie(std::string name, std::string rating, int watched);
    
    // Copy constructor 
    //Movie(const Movie &source); 
    
    // Destructor
    ~Movie();
    
    // Basic getters and setters for private attributes

    void set_name(std::string movie_name) {this->movie_name = movie_name; }
    std::string get_name() const { return movie_name; }
    
    void set_rating(std::string movie_rating) {this->movie_rating = movie_rating; }
    std::string get_rating() const { return movie_rating; }
    
    void set_watched(int watched) {this->watched = watched; }
    int get_watched() const { return watched; }
    
    // Simply increment the watched attribute by 1
    //void increment_watched() { ++watched; }
    
    // simply displays the movie information ex.) Big, PG-13, 2
    void display() const;
};

#endif
