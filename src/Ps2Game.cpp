#include "Ps2Game.hpp"

// =+=+=+=+==+=+=+=+==+=+=+=+==+=+=+=+==+=+=+=+==+=+=+=+==+=+=+=+= 
// Ps2Game CLASS
// =+=+=+=+==+=+=+=+==+=+=+=+==+=+=+=+==+=+=+=+==+=+=+=+==+=+=+=+= 

//CLASS FUNCTIONS

std::string Ps2Game::prettyPrint() const {
    std::string resulting_str;
    resulting_str = "The tile of the game is: " + title_of_this + " the game was made by " 
    + studio_of_this + " \nDATE OF RELEASE: " + std::to_string(year_of_this) + "\n"; 
    return resulting_str;
}

const std::string& Ps2Game::getTitle() const {
    return title_of_this;
}

const std::string& Ps2Game::getStudio() const {
    return studio_of_this; 
}

int Ps2Game::getYear() const {
    return year_of_this; 
}
//CLASS CONSTRUCTORS: 
Ps2Game::Ps2Game(const std::string& title, const std::string& studio, int year) : 
title_of_this(title) ,studio_of_this(studio), year_of_this(year){}

Ps2Game::Ps2Game(const Ps2Game& other) : title_of_this(other.title_of_this), studio_of_this(other.studio_of_this),
year_of_this(other.year_of_this){   }

Ps2Game::Ps2Game(Ps2Game&& other) : title_of_this(other.title_of_this), studio_of_this(other.studio_of_this),
year_of_this(other.year_of_this)
{
    *this = other; 
}

//CLASS OPERATOR OVERLOADS
bool Ps2Game::operator==(const Ps2Game& other) const {
    return (title_of_this == other.getTitle() && studio_of_this == other.getStudio() 
    && year_of_this == other.getYear());
}
bool Ps2Game::operator!=(const Ps2Game& other) const {
    return !(title_of_this == other.getTitle() && studio_of_this == other.getStudio() 
    && year_of_this == other.getYear());
}

Ps2Game& Ps2Game::operator=(const Ps2Game& other) {
    studio_of_this = other.getStudio();
    title_of_this = other.getTitle();
    year_of_this = other.getYear();
    return *this;
}

Ps2Game& Ps2Game::operator=(Ps2Game&& other) {
    studio_of_this = other.getStudio();
    title_of_this = other.getTitle();
    year_of_this = other.getYear();
    *this = other;
    return *this;
}