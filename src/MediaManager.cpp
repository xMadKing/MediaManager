#include "MediaManager.hpp"
#include <iostream>


// =+=+=+=+==+=+=+=+==+=+=+=+==+=+=+=+==+=+=+=+==+=+=+=+==+=+=+=+=
// MediaManager CLASS
// =+=+=+=+==+=+=+=+==+=+=+=+==+=+=+=+==+=+=+=+==+=+=+=+==+=+=+=+=

//SUPPORT FUNCTIONS
void resize(Media **&medias, int size, int fSize)
{
    Media **temp_arr = new Media *[fSize];
    for (int i = 0; i < size; i++)
    {
        temp_arr[i] = medias[i];
    }
    delete[] medias; 
    medias = new Media *[fSize];
    for (int i = 0; i < size; i++)
    {
        medias[i] = temp_arr[i];
    }
    delete[] temp_arr; 
}

//CLASS FUNCTIONS
void MediaManager::addMedia(Media *media)
{
    Ps2Game *game = dynamic_cast<Ps2Game *>(media);
    if(game != nullptr){
        addPs2Game(*game); 
    }
    else
    {
        Book *book = dynamic_cast<Book *>(media);
        if(book != nullptr){
            addBook(*book);
        }
        else
        {
            Vinyl *vinyl = dynamic_cast<Vinyl*>(media);
            if(vinyl != nullptr)
            {
                addVinyl(*vinyl);
            }
        }
    }
}

void MediaManager::addBook(const Book &book)
{
    if (size == 0)
    {
        size++;
        delete[] medias; 
        medias = new Media *[size];
        medias[0] = new Book(book);
    }
    else
    {
        resize(medias, size, size + 1);
        medias[size] = new Book(book);
        size++;
    }
}

void MediaManager::addVinyl(const Vinyl &vinyl)
{
    if (size == 0)
    {
        size++;
        delete[] medias; 
        medias = new Media *[size];
        medias[0] = new Vinyl(vinyl);
    }
    else
    {
        resize(medias, size, size + 1);
        medias[size] = new Vinyl(vinyl);
        size++;
    }
}

void MediaManager::addPs2Game(const Ps2Game &game)
{
    if (size == 0)
    {
        size++;
        delete[] medias; 
        medias = new Media *[size];
        medias[0] = new Ps2Game(game);
    }
    else
    {
        resize(medias, size, size + 1);
        medias[size] = new Ps2Game(game);
        size++;
    }
}

std::vector<Book> MediaManager::getBooks() const
{
    std::vector<Book> book_vec;
    if (size == 0)
    {
        return book_vec;
    }
    for (int i = 0; i < size; i++)
    {
        Book *book = dynamic_cast<Book*>(medias[i]);
        if (book != nullptr)
        {
            book_vec.push_back(*book);
        }
    }
    return book_vec;
}

std::vector<Vinyl> MediaManager::getVinyls() const
{
    std::vector<Vinyl> vinyl_vec;
    if (size == 0)
    {
        return vinyl_vec;
    }
    for (int i = 0; i < size; i++)
    {
        Vinyl *vinyl(dynamic_cast<Vinyl*>(medias[i]));
        if (vinyl != nullptr)
        {
            vinyl_vec.push_back(*vinyl);
        }
    }
    return vinyl_vec;
}

std::vector<Ps2Game> MediaManager::getPs2Games() const
{
    std::vector<Ps2Game> game_vec;
    if (size == 0)
    {
        return game_vec;
    }
    for (int i = 0; i < size; i++)
    {
        Ps2Game *game = dynamic_cast<Ps2Game *>(medias[i]);
        if (game!= nullptr)
        {
            game_vec.push_back(*game);
        }
    }
    return game_vec;
}
Media** MediaManager::getMedias() const{
    return medias; 
} 

std::string MediaManager::printMedia() const
{
    std::string str; 
    std::vector<Book> books = getBooks(); 
    std::vector<Ps2Game> games = getPs2Games(); 
    std::vector<Vinyl> vinyls = getVinyls();
    
    for(int i = 0; i < books.size(); i++){
        str += books[i].prettyPrint(); 
    }
    for(int i = 0; i < games.size(); i++){
        str += games[i].prettyPrint();
    }
    for(int i = 0; i < vinyls.size(); i++){
        str += vinyls[i].prettyPrint();
    }

    return str; 
}

//CLASS CONSTROCTORS
MediaManager::MediaManager()
{
    medias = new Media*[0];
    size = 0;
}
MediaManager::MediaManager(int number){
    medias = new Media*[number];
    size = 0;
}
MediaManager::MediaManager(const MediaManager &other) : medias(other.medias), size(other.size) {}

//CLASS DESTRUCTOR
MediaManager::~MediaManager()
{
    for(int i = 0; i < size; i++){
        delete medias[i]; 
    }
    delete[] medias;
}

//CLASS OPERATOR OVERLOAD
bool MediaManager::operator==(const MediaManager &other) const
{

    if (getBooks() != other.getBooks())
    {
    return false;
    }
    if (getVinyls() != other.getVinyls())
    {
        return false; 
    }
    if (getPs2Games() != other.getPs2Games())
    {
        return false; 
    }
    return true;
}
bool MediaManager::operator!=(const MediaManager& other) const{
    if (getBooks() != other.getBooks())
    {
    return true;
    }
    if (getVinyls() != other.getVinyls())
    {
        return true; 
    }
    if (getPs2Games() != other.getPs2Games())
    {
        return true; 
    }
    return false;
}

MediaManager &MediaManager::operator=(const MediaManager &other)
{
    if (this == &other)
    {
        return *this;
    }
    delete[] medias;
    medias = new Media *[other.size];
    for (int j = 0; j < other.size; j++)
    {
        medias[j] = other.medias[j];
    }
    return *this;
}