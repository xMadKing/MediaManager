#ifndef MEDIA_H
#define MEDIA_H

#include <string>
#include <vector>

#include "Time.hpp"
#include "Track.hpp"

class Book;
class Ps2Game;
class Vinyl;

class Media
{
public:
    virtual std::string prettyPrint() const = 0;
    virtual const std::string& getTitle() const = 0; 
    virtual ~Media() = default;
    virtual bool operator==(const Media& other) const;
    virtual bool operator!=(const Media& other) const;
};

#endif