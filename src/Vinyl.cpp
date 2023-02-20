#include "Vinyl.hpp"
#include <iostream>

// =+=+=+=+==+=+=+=+==+=+=+=+==+=+=+=+==+=+=+=+==+=+=+=+==+=+=+=+= 
// VINYL CLASS
// =+=+=+=+==+=+=+=+==+=+=+=+==+=+=+=+==+=+=+=+==+=+=+=+==+=+=+=+= 

//CLASS FUNCTIONS

std::string Vinyl::prettyPrint() const {
    std::string resulting_str;
    resulting_str = " This record is by " + artist_of_this + " and is titled " + title_of_this 
    + ". This record was published in " + std::to_string(year_of_this) + ". \n" + " This record contains the following tracks: \n";
    for(int i  = 0; i < getTracks().size(); i++){
        resulting_str += getTracks()[i].prettyPrint(); 
    }
    return resulting_str;
}


void Vinyl::addTrack(const Track &track)
{
    vector_to_return.push_back(track);
}

const std::string &Vinyl::getTitle() const 
{
    return title_of_this;
}

int Vinyl::getYear() const 
{
    return year_of_this;
}

VinylTypes Vinyl::getType() const 
{
    return type_of_this;
}

const std::string &Vinyl::getArtist() const 
{
    return artist_of_this;
}

const Time &Vinyl::getRuntime() const 
{
    return run_time_of_this;
}

const std::vector<Track>& Vinyl::getTracks() const 
{
    return vector_to_return;
}

//CLASS CONSTRUCTORS
Vinyl::Vinyl(const std::string &title, VinylTypes type, int year,
const std::string &artist, const Time &runtime) : title_of_this(title), type_of_this(type), year_of_this(year),
artist_of_this(artist), run_time_of_this(runtime)
{   }

Vinyl::Vinyl(const Vinyl& other): title_of_this(other.title_of_this), type_of_this(other.type_of_this),
year_of_this(other.year_of_this), artist_of_this(other.artist_of_this), run_time_of_this(other.run_time_of_this),
vector_to_return(other.vector_to_return)
{   }
Vinyl::Vinyl(Vinyl&& other) :
title_of_this(other.title_of_this), type_of_this(other.type_of_this),
year_of_this(other.year_of_this), artist_of_this(other.artist_of_this), run_time_of_this(other.run_time_of_this),
vector_to_return(other.vector_to_return)
{
    *this = other; 
}

//CLASS DESTRUCTOR
Vinyl::~Vinyl(){
}

//CLASS OPERATOR OVERLOADS
bool Vinyl::operator==(const Vinyl &other) const {
    return (title_of_this == other.getTitle() && type_of_this == other.getType()
    && year_of_this == other.getYear() && artist_of_this == other.getArtist()
    && run_time_of_this == other.getRuntime() && this->getTracks() == other.getTracks());
}

bool Vinyl::operator!=(const Vinyl &other) const {
    return !(title_of_this == other.getTitle() && type_of_this == other.getType()
    && year_of_this == other.getYear() && artist_of_this == other.getArtist()
    && run_time_of_this == other.getRuntime() && this->getTracks() == other.getTracks());
}


Vinyl& Vinyl::operator=(const Vinyl& other) {

    artist_of_this = other.getArtist();
    type_of_this = other.getType();
    run_time_of_this = other.getRuntime();
    title_of_this = other.getTitle();
    year_of_this = other.getYear();
    vector_to_return =  other.getTracks();

    return *this;
}

Vinyl& Vinyl::operator=(Vinyl&& other) {

    artist_of_this = other.getArtist();
    type_of_this = other.getType();
    run_time_of_this = other.getRuntime();
    title_of_this = other.getTitle();
    year_of_this = other.getYear();
    vector_to_return =  other.getTracks();
    *this = other; 
    return *this;
}

