// Edit this class as you choose. The main function below is just there to make
// sure the project compiles!
#include "Book.hpp"
#include "Media.hpp"
#include "MediaManager.hpp"
#include "Time.hpp"
#include "Track.hpp"
#include "Vinyl.hpp"
#include <iostream>
#include <string>


void printBook(MediaManager& manager){
    std::vector<Book> vec = manager.getBooks(); 
    for(int i = 0; i < vec.size(); i++){
        std::cout << vec[i].prettyPrint(); 
    }
}
void printGame(MediaManager& manager){
    std::vector<Ps2Game> vec = manager.getPs2Games(); 
    for(int i = 0; i < vec.size(); i++){
        std::cout << vec[i].prettyPrint(); 
    }
}
void printVinyl(MediaManager& manager){
    std::vector<Vinyl> vec = manager.getVinyls(); 
    for(int i = 0; i < vec.size(); i++){
        std::cout << vec[i].prettyPrint(); 
    }
}
void addBook(MediaManager& manager){
    std::cout << "So you wish to add a book? Well simple!" << std::endl; 
    std::cout << "\nTitle: ";
    std::string title;
    std::cin >> title;
    std::cout << "\nAuthor: ";
    std::string author;
    std::cin >> author;
    std::cout << "\nIsbn: ";
    std::string isbn;
    std::cin >> isbn;
    std::cout << "\nNumber of pages: ";
    std::string pages;
    std::cin >> pages;
    std::cout << "\nEdition: "; 
    std::string edition;
    std::cin >> edition;
    try
    {
        int page_amount = std::stoi(pages);
        int edition_number = std::stoi(edition);
        Book book = Book(title, author, isbn, page_amount, edition_number); 
        manager.addBook(book);
        std::cout << "\nADDED!"; 
    }
    catch(const std::exception& e)
    {
        std::cout << "\nINVALID INPUT. CANCELED! (Make sure that the number of pages/edition only contain integers.)";
    }
}

void addGame(MediaManager& manager){
    std::cout << "So you wish to add a game? Well simple!" << std::endl; 
    std::cout << "\nTitle: ";
    std::string title;
    std::cin >> title;
    std::cout << "\nStudio: ";
    std::string studio;
    std::cin >> studio;
    std::cout << "\nYear: ";
    std::string year; 
    std::cin >> year; 
    try
    {
        int year_int = std::stoi(year); 
        Ps2Game game = Ps2Game(title, studio, year_int);
        manager.addPs2Game(game);
        std::cout << "\nADDED!"; 
    }
    catch(const std::exception& e)
    {
        std::cout << "\nINVALID INPUT. CANCELED! (Make sure that the number of the year only contain integers.)";
    }
}

void addVinyl(MediaManager& manager){
    std::cout << "So you wish to add a Vinyl? Well simple!" << std::endl; 
    std::cout << "\nTitle: ";
    std::string title;
    std::cin >> title;
    std::cout << "\nType of vinyl (EXTENDED, LONG) make sure you enter it fully capitalized and properly spelled: ";
    std::string name_of_type;
    std::cin >> name_of_type; 
    std::cout << "\nName of artist: ";
    std::string artist;
    std::cin >> artist; 
    std::cout << "\nRelease year: ";
    std::string year; 
    std::cin >> year;
    std::cout << "\nRuntime (00 00) make sure you sperate the minutes/seconds with a space: "; 
    std::string minutes;
    std::string seconds; 
    std::cin >> minutes >> seconds; 
    try
    {
        VinylTypes type_of_vinyl;
        if(name_of_type == "EXTENDED"){
            type_of_vinyl = VinylTypes::EXTENDED_PLAY;
        }
        else if(name_of_type == "LONG"){
            type_of_vinyl = VinylTypes::LONG_PLAY; 
        } else {std::cout << "INVALID INPUT! DEFAULTING TO LONG_PLAY";
            type_of_vinyl = VinylTypes::LONG_PLAY;}

        int year_int = std::stoi(year);
        int minutes_int = std::stoi(minutes);
        int seconds_int = std::stoi(seconds);
        Time time = Time(minutes_int, seconds_int); 
        Vinyl vinyl(title, type_of_vinyl, year_int, artist, time);
        std::cout << "\nDo you wish to add tracks to the vinyl? (Enter 'Y' to continue anything else to finish)";
        std::string answer;
        std::cin >> answer;
        if (answer == "Y"){
            std::cout << "\nHow many tracks do you wish to add? ";
            std::string tracks_num;
            std::cin >> tracks_num; 
            int tracks_int = std::stoi(tracks_num); 
            for(int i = 0; i < tracks_int; i++){
                std::cout << "\n Title of Track: ";
                std::string track_title; 
                std::cin >> track_title;
                std::cout << "\nLength (00 00) make sure you sperate the minutes/seconds with a space: "; 
                std::string minutes_of_track;
                std::string seconds_of_track; 
                std::cin >> minutes_of_track >> seconds_of_track;
                int int_of_track_minutes = std::stoi(minutes_of_track);
                int int_of_track_seconds = std::stoi(seconds_of_track);
                vinyl.addTrack(Track(track_title, Time(int_of_track_minutes, int_of_track_seconds))); 
            }
            manager.addVinyl(vinyl);
            std::cout << "\nADDED!";
        } else {
            manager.addVinyl(vinyl);
            std::cout << "\nADDED!";
        }
    }
    catch(const std::exception& e)
    {
        std::cout << "\nERROR: INVALID INPUT!"; 
    }
}

enum cases{
    ListAllMedia, ListBooks, ListGames, ListVinyls, AddBook, AddGame, AddVinyl, Exit, Bad_INPUT
};

int command_number(std::string command){
    try
    {
        int number = std::stoi(command); 
        return number;
    }
    catch(const std::exception& e)
    {
        std::cout << "\nINVALID INPUT";
        int number = Bad_INPUT; //Set the number of command to 9 to skip all commands and ask the user for a different command. 
        return number;
    }
}

int main() {
    std::cout << "Hello and welcome to MediaManager™ What do you wish to do? \n"<< ListAllMedia << ". List all medias \n"<< ListBooks << ". List books" 
    << "\n"<< ListGames << ". List Playstation 2 games \n"<< ListVinyls << ". List vinyls \n"<< AddBook<< ". Add a book \n"<< AddGame << ". Add a Playstation 2 game \n"<<
    AddVinyl << ". Add a vinyl \n"<< Exit << ". Exit the program" << std::endl; 
    bool running = true; 
    MediaManager manager; 
    while (running){
        std::cout << "\nPlease enter the number of the command you wish to execute: "; 
        std::string command; 
        std::cin >> command; 
        int number = command_number(command); 
        if(number > Bad_INPUT || number < ListAllMedia){
            std::cout << "Please enter a valid command.\n"; 
        }
        switch (number)
        {
        case ListAllMedia:
            std::cout << manager.printMedia() << std::endl;
            break;
        case ListBooks:
            printBook(manager); 
            break;
        case ListGames:
            printGame(manager);
            break; 
        case ListVinyls:
            printVinyl(manager); 
            break;
        case AddBook:
            addBook(manager); 
            break;
        case AddGame:
            addGame(manager);
            break;
        case AddVinyl:
            addVinyl(manager);
            break;
        case Exit:
            std::cout << "\nTERMINATING THE PROGRAM!" << std::endl;
            running = false;
            break; 
        case Bad_INPUT:
            //this does nothing. It is here to make sure that the user does not lose their information when they enter an invalid input. 
            break; 
        }
    }
}