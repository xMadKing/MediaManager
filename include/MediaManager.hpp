
#ifndef MEDIAMANAGER_H
#define MEDIAMANAGER_H

#include "Book.hpp"
#include "Ps2Game.hpp"
#include "Vinyl.hpp"


class MediaManager
{
private:
    Media** medias;
    int size; 
public:
    MediaManager();
    MediaManager(int num);
    MediaManager(const MediaManager& other);
    MediaManager(const MediaManager&& other) = delete; 
    ~MediaManager();
    void addMedia(Media* media);
    void addBook(const Book& book);
    void addVinyl(const Vinyl& vinyl);
    void addPs2Game(const Ps2Game& game);
    std::string printMedia() const;
    std::vector<Book> getBooks() const;
    std::vector<Vinyl> getVinyls() const ;
    std::vector<Ps2Game> getPs2Games() const ;
    Media** getMedias() const; 
    bool operator==(const MediaManager& other) const;
    bool operator!=(const MediaManager& other) const;
    MediaManager& operator=(const MediaManager& other);
};

#endif

