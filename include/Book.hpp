#ifndef BOOK_H
#define BOOK_H

#include "Media.hpp"
#include "Ps2Game.hpp"
#include "Vinyl.hpp"

class Ps2Game;
class Vinyl;

class Book : public Media
{
private:
    std::string title_of_this;
    std::string author_of_this;
    std::string isbn_of_this;
    int pages_of_this;
    int edition_of_this; 
public: 
    using Media::operator!=;
    using Media::operator==; 
    Book(const std::string &title, const std::string &author,
        const std::string &isbn, int pages, int edition);
    Book(const Book& other);
    Book(Book&& other); 
    ~Book() = default;
    const std::string& getTitle() const override ;
    const std::string& getAuthor() const ;
    const std::string& getIsbn() const ;
    int getPages() const ;
    int getEdition() const ;
    std::string prettyPrint() const override;
    bool operator==(const Book &other) const;
    bool operator!=(const Book &other) const; 
    Book& operator=(const Book &other);
    Book& operator=(Book &&other);
    
};

#endif