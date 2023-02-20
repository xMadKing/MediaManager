#include "Book.hpp"

// =+=+=+=+==+=+=+=+==+=+=+=+==+=+=+=+==+=+=+=+==+=+=+=+==+=+=+=+=
// BOOK CLASS
// =+=+=+=+==+=+=+=+==+=+=+=+==+=+=+=+==+=+=+=+==+=+=+=+==+=+=+=+=

//CLASS FUNCTIONS:
std::string Book::prettyPrint() const
{
    std::string resulting_str;
    resulting_str = "The " + title_of_this + " is a book written by " + author_of_this + " the books is " + std::to_string(pages_of_this) + 
    " pages long. \nISBN: " + isbn_of_this + ", Edition: " + std::to_string(edition_of_this) + "\n";
    return resulting_str;
}

const std::string &Book::getTitle() const
{
    return title_of_this;
}

const std::string &Book::getAuthor() const
{
    return author_of_this;
}

const std::string &Book::getIsbn() const
{
    return isbn_of_this;
}

int Book::getPages() const
{
    return pages_of_this;
}

int Book::getEdition() const
{
    return edition_of_this;
}

//CLASS CONSTRUCTORS:
Book::Book(const std::string &title, const std::string &author,
           const std::string &isbn, int pages, int edition) : title_of_this(title), author_of_this(author), isbn_of_this(isbn),
           pages_of_this(pages), edition_of_this(edition) {}

Book::Book(const Book& other) : title_of_this(other.title_of_this), author_of_this(other.author_of_this),
           isbn_of_this(other.isbn_of_this), pages_of_this(other.pages_of_this),
           edition_of_this(other.edition_of_this) {}
Book::Book(Book&& other) : title_of_this(other.title_of_this), author_of_this(other.author_of_this),
           isbn_of_this(other.isbn_of_this), pages_of_this(other.pages_of_this),
           edition_of_this(other.edition_of_this)
{
    *this = other;
}

//CLASS OPERATOR OVERLOADS
bool Book::operator==(const Book &other) const 
{
    return (title_of_this == other.getTitle() && author_of_this == other.getAuthor() && isbn_of_this == other.getIsbn()
    && pages_of_this == other.getPages() && edition_of_this == other.getEdition());
}
bool Book::operator!=(const Book &other) const {
    return !(title_of_this == other.getTitle() && author_of_this == other.getAuthor() && isbn_of_this == other.getIsbn()
    && pages_of_this == other.getPages() && edition_of_this == other.getEdition());
}

Book& Book::operator=(const Book &other)
{
    title_of_this = other.getTitle();
    author_of_this = other.getAuthor();
    isbn_of_this = other.getIsbn();
    pages_of_this = other.getPages();
    edition_of_this = other.getEdition();
    
    return *this;
}

Book& Book::operator=(Book &&other)
{
    *this = other;
    title_of_this = other.getTitle();
    author_of_this = other.getAuthor();
    isbn_of_this = other.getIsbn();
    pages_of_this = other.getPages();
    edition_of_this = other.getEdition();
    return *this; 
}
