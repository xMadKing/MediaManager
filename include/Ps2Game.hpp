#ifndef PS2GAME_H
#define PS2GAME_H

#include "Media.hpp"
#include "Vinyl.hpp"
#include "Book.hpp"

class Vinyl;
class Book;

class Ps2Game : public Media
{
private:
    std::string title_of_this; 
    std::string studio_of_this; 
    int year_of_this; 
public:
    using Media::operator!=;
    using Media::operator==; 
    Ps2Game(const std::string& title, const std::string& studio, int year);
    Ps2Game(const Ps2Game& other);
    Ps2Game(Ps2Game&& other); 
    ~Ps2Game() = default;
    std::string prettyPrint() const override;
    const std::string& getTitle() const override; 
    const std::string& getStudio() const ;
    int getYear() const ;
    bool operator==(const Ps2Game &other) const;
    bool operator!=(const Ps2Game &other) const; 
    Ps2Game& operator=(const Ps2Game& other); 
    Ps2Game& operator=(Ps2Game&& other); 
};

#endif