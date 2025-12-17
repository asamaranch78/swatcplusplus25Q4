/*
    Author: Juan M. Lagostena
    Dec 16, 2025
*/

#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>

class Song 
{
    private:
        friend std::ostream &operator<<(std::ostream &os, const Song &s);
        std::string name;
        std::string artist;
        int rating;

    public:
        Song() = default;
        Song(std::string name, std::string artist, int rating)
                : name{name}, artist{artist}, rating{rating} {}

        inline std::string get_name() const { return name; }
        inline std::string get_artist() const { return artist; }
        inline int get_rating() const { return rating; }
        
        bool operator<(const Song &rhs) const  {
            return this->name < rhs.name;
        }
        
        bool operator==(const Song &rhs) const  {
            return this->name == rhs.name;
        }
};

std::ostream &operator<<(std::ostream &os, const Song &s) 
{
    os << std::setw(20) << std::left << s.name
       << std::setw(30) << std::left << s.artist
       << std::setw(2) << std::left << s.rating;
    
    return os;
}

void display_menu() 
{
    std::cout << "\nF - Play First Song" << std::endl;
    std::cout << "N - Play Next song" << std::endl;
    std::cout << "P - Play Previous song" << std::endl;
    std::cout << "A - Add and play a new Song at current location" << std::endl;
    std::cout << "L - List the current playlist" << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << "Enter a selection (Q to quit): ";
}

void play_current_song(const Song &song) 
{
    // This function should display 
    // Playing: followed by the song that is playing
    std::cout << "--- NOW PLAYING ---------------------------------------" << std::endl;
    std::cout << song << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
    //std::cout << "You implement this function"<< std::endl;
}

void display_playlist(const std::list<Song> &playlist, const Song &current_song) 
{
    // This function should display the current playlist 
    // and then the current song playing.

    std::cout << "=== PLAYLIST ==========================================" << std::endl;
    for (const auto s: playlist)
    {
        std::cout << s << std::endl;
    }
    std::cout << "=======================================================" << std::endl;
    std::cout << std::endl;

    play_current_song(current_song);
}

int main() 
{

    std::list<Song> playlist 
    {
        {"A Doomed Lover", "My Dying Bride", 5},
        {"Western Rust", "Blume", 4 },
        {"Avfard", "Sagor Som Leder Mot Slutet", 5},
        {"Drive", "Wires & Lights", 5 },
        {"After The Thaw", "Collapse Under The Empire", 5 },
        {"Nemesis", "Arch Enemy", 5 }
    };
    
    std::list<Song>::iterator current_song = playlist.begin();
    
    unsigned char opt {};
    do
    {
        do
        {
            display_menu();
            std::cin >> opt;
            std::cout << std::endl;
            /* code */
        } while (!std::isalpha(opt));

        switch (std::toupper(opt))
        {
            case 'F':
                current_song = playlist.begin();
                play_current_song(*current_song);
                break;

            case 'N':
                current_song++;
                if (current_song == playlist.end())
                {
                    current_song = playlist.begin();
                }
                play_current_song(*current_song);
                break;

            case 'P':
                if (current_song == playlist.begin())
                {
                    current_song = playlist.end();
                }
                current_song--;
                play_current_song(*current_song);
                break;

            case 'A':
            {
                std::string song_name {};
                std::string artist {};
                int rating {};

                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                
                std::cout << "Song name: ";
                std::getline(std::cin, song_name);
                std::cout << "Artist: ";
                std::getline(std::cin, artist);
                std::cout << "Rating: ";
                std::cin >> rating;

                playlist.insert(current_song, Song{song_name, artist, rating});
                current_song--;
                play_current_song(*current_song);
                break;
            }

            case 'L':
                display_playlist(playlist, *current_song);
                break;

            case 'Q':
                std::cout << "Thanks for listening!" << std::endl;
                break;

            default:
                std::cout << "Invalid option" << std::endl;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        /* code */
    } while (!std::isalpha(opt) || toupper(opt) != 'Q');

    return 0;
}