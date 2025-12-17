#include <iostream>
#include <vector>
#include <limits>

//using namespace std;
using std::cout;
using std::cin;
using std::endl;
using std::string;

class Movie {

    private:
    std::string name;
    std::string peggy;
    int watched;

    public:
    Movie(std::string name_val, std::string peggy_val, int watched_val = 0)
    : name{name_val}, peggy{peggy_val}, watched{watched_val} {
    };

    ~Movie() {};

    // Copy constructor.
    Movie(const Movie &source)
    : Movie { source.name, source.peggy, source.watched } {}

    inline std::string get_name() const { return this->name; }
    inline void increment_watched() { watched++; }

    void display() const;
};

void Movie::display() const {
    std::cout << " " << name << ", Rate: " << peggy << ", Viewed: " << watched << " times." << std::endl;
}

class Movies {

    private:
    std::vector<Movie> movies;

    public:
    
    int find_movie(std::string name) const;
    bool add_movie(std::string name, std::string peggy, int watched = 0);
    bool increment_watched(std::string name);
    //bool delete_movie(std::string name);
    
    void display_all_movies() const;
    void display_movie(int index) const;

};

// Returns index of a movie in collection, -1 when not found or -2 when collection is empty.
int Movies::find_movie(std::string name) const {

    int idx {-1};
    
    idx = (movies.size() == 0) ? -2 : idx;

    for (size_t i {0}; i < movies.size(); ++i) {
        if (movies.at(i).get_name() == name) {
            idx = i;
            break;
        }
    }

    return idx;
}

bool Movies::add_movie(std::string name, std::string peggy, int watched) {

    int idx {-1};

    idx = find_movie(name);

    if (idx < 0) {
        this->movies.push_back(Movie{ name, peggy, watched });
    }

    return (idx < 0);
}

bool Movies::increment_watched(std::string name) {

    int idx {-1};

    idx = find_movie(name);

    if (idx >= 0) {
        movies.at(idx).increment_watched();
        return true;
    }

    return false;
}

void Movies::display_all_movies() const {
    
    std::cout << "=========================" << std::endl;
    
    if (movies.size() > 0) {
        for (auto m: movies) {
            m.display();
        }
    } else {
        cout << " Collection is empty." << endl;
    }
    
    std::cout << "=========================" << std::endl << std::endl;
}

void Movies::display_movie(int idx) const {
    movies.at(idx).display();
}

void print_menu() {

    cout << endl;
    cout << "=========================" << endl;
    cout << "     MOVIES MANAGER" << endl;
    cout << "=========================" << endl;
    cout << " (1) Display movies" << endl;
    cout << " (2) Add movie" << endl;
    cout << " (3) Notify watched" << endl;
    cout << " (4) Delete movie (PENDING)" << endl;
    cout << " (5) Search movie" << endl;
    cout << "=========================" << endl;
    cout << " (0) Quit" << endl;
    cout << "=========================" << endl;
    cout << endl;
}

int get_menu_option() {

    int user_option {-1};
    
    print_menu();
    cout << " Select option: ";
    cin >> user_option;

    return user_option;
}

void get_user_input_spaces(string question, string *str_answer) {
    
    cout << endl;
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    cout << " " << question << ": ";
    getline(cin, *str_answer);
}

void get_user_input(string question, string *str_answer) {

    cout << endl;
    cout << " " << question << ": ";
    cin >> *str_answer;    
}

void get_user_input(string question, int *int_answer) {

    cout << endl;
    cout << " " << question << ": ";
    cin >> *int_answer;
}

void menu_add_movies(Movies *mvs) {

    string mv_name;
    string rating;
    string another;

    int watchs {};

    do {
        get_user_input_spaces("Movie name", &mv_name);
        get_user_input("Rating", &rating);
        get_user_input("Watchs until date", &watchs);

        bool success = mvs->add_movie(mv_name, rating, watchs);

        if (success) {
            cout << "\n Movie " << mv_name << " added to collection." << endl;
        }

        get_user_input("Add another (y/n)", &another);

    } while (another == "y" || another == "Y");

}

void menu_notify_watched(Movies *mvs) {
    
    string mv_name;

    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    get_user_input_spaces("Movie watched", &mv_name);

    if (mvs->increment_watched(mv_name)) {
        cout << "\n Movie '" <<  mv_name  << "' watchs incremented" << endl;
    } else {
        std::cout << "\n Movie " << mv_name << " does not exist in collection." << std::endl;
    }
}

void menu_find_movie(Movies *mvs) {
    
    string mv_name;
    int idx {-1};

    get_user_input_spaces("Movie name", &mv_name);
    idx = mvs->find_movie(mv_name);

    if (idx >= 0) {
        cout << "\n Movie '" << mv_name << "' found at position " << idx << endl;
        mvs->display_movie(idx);
    } else if (idx == -1) {
        cout << "\n Movie not found in collection." << endl;
    } else if (idx == -2) {
        cout << "\n Movies collection is empty." << endl;
    }
}

int main() {

    bool quit_program {false};
    int option {};

    Movies movies;

    do {

        option = get_menu_option();

        switch (option) {
            case 0:
                quit_program = true;
                break;

            case 1:
                movies.display_all_movies();
                break;

            case 2:
                menu_add_movies(&movies);
                break;

            case 3:
                menu_notify_watched(&movies);
                break;

            case 4:
                cout << "\n Unavailable." << endl;
                break;

            case 5:
                menu_find_movie(&movies);
                break;

            default:
                cout << "\n Invalid option." << endl;
        }

    } while (!quit_program);

    return 0;
}