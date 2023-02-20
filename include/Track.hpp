#ifndef TRACK_H
#define TRACK_H

#include "Media.hpp"

class Vinyl;

class Track 
{
private:
    std::string name_of_this;
    Time length_of_this; 
public:
    Track(const std::string &name, const Time &length);
    Track(const Track& other);
    const std::string &getName() const;
    const Time &getLength() const ;
    bool operator==(const Track& other) const;
    bool operator!=(const Track& other) const;
    Track& operator=(const Track& other);
    std::string prettyPrint() const;
};

#endif