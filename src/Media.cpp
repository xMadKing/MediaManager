#include <Media.hpp>

bool Media::operator!=(const Media& other) const    {
    return !(typeid(*this) == typeid(other) && this->getTitle() == other.getTitle() && this->prettyPrint() == other.prettyPrint());
}
bool Media::operator==(const Media& other) const {
        return (typeid(*this) == typeid(other) && this->getTitle() == other.getTitle() && this->prettyPrint() == other.prettyPrint());
    } 
/* bool Media::operator==(const Book& other) const{

}
bool Media::operator==(const Ps2Game& other) const{

}
bool Media::operator==(const Vinyl& other) const{

}
bool Media::operator!=(const Book& other) const{

}
bool Media::operator!=(const Ps2Game& other) const{

}
bool Media::operator!=(const Vinyl& other) const{

} */