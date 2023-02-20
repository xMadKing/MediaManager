#ifndef VINYL_H
#define VINYL_H

#include "Ps2Game.hpp"
#include "Book.hpp"

class Book;
class Ps2Game;

enum class VinylTypes
{
    LONG_PLAY,
    EXTENDED_PLAY
};

class Vinyl : public Media
{
private:
    std::string title_of_this;
    VinylTypes type_of_this;
    int year_of_this;
    std::string artist_of_this;
    Time run_time_of_this;
    std::vector<Track> vector_to_return;

public:
    using Media::operator!=;
    using Media::operator==; 
    Vinyl(const std::string &title, VinylTypes type, int year,
          const std::string &artist, const Time &runtime);
    Vinyl(const Vinyl& other);
    Vinyl(Vinyl&& other);
    ~Vinyl();
    std::string prettyPrint() const override;
    void addTrack(const Track &track);
    const std::string &getTitle() const override;
    int getYear() const ;
    VinylTypes getType() const ; 
    const std::string &getArtist() const ;
    const Time &getRuntime() const ;
    const std::vector<Track> &getTracks() const ;
    bool operator==(const Vinyl &other) const;
    bool operator!=(const Vinyl &other) const;
    Vinyl& operator=(const Vinyl& other);
    Vinyl& operator=(Vinyl&& other);
};

#endif