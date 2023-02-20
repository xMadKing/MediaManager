#include "Track.hpp"


// =+=+=+=+==+=+=+=+==+=+=+=+==+=+=+=+==+=+=+=+==+=+=+=+==+=+=+=+= 
// TRACK CLASS
// =+=+=+=+==+=+=+=+==+=+=+=+==+=+=+=+==+=+=+=+==+=+=+=+==+=+=+=+= 

//CLASS CONSTRUCTORS

Track::Track(const std::string &name, const Time &length) : length_of_this(length) {
    name_of_this = name;
}

Track::Track(const Track& other) : name_of_this(other.getName()), 
length_of_this(other.length_of_this)
{}

//CLASS FUNCTIONS 

const std::string &Track::getName() const 
{
    return name_of_this;
}
const Time &Track::getLength() const 
{
    return length_of_this;
}

std::string Track::prettyPrint() const {
    std::string str;
    str = "The name of this track is " + name_of_this + " and it is " + getLength().print() + " Long.\n" ;
    return str;
}

//CLASS OPERATOR OVERLOADS

bool Track::operator==(const Track &other) const {
    return (name_of_this == other.getName() && length_of_this == other.getLength());
}
bool Track::operator!=(const Track &other) const {
    return !(name_of_this == other.getName() && length_of_this == other.getLength());
}

Track& Track::operator=(const Track& other){
    name_of_this = other.getName();
    length_of_this = other.getLength();
    return *this;
}
