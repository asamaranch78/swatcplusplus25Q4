/*
    Author: Juan M. Lagostena.
    Dec, 01 2025
*/

#include <iostream>
#include <vector>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

bool allow_duplicates {false};

char print_menu();
void print_vector(const vector<int> &v);
void add_number(const bool &duplicates, vector<int> &v);
double calculate_mean(const vector<int> &v);
int get_smallest(const vector<int> &v);
int get_largest(const vector<int> &v);
int find_number(const vector<int> &v, const int &n);
int find_duplicate(const vector<int> &v);
void clear_list(vector<int> &v);

inline bool get_allow_duplicates() { return allow_duplicates; };
inline void set_allow_duplicates() { allow_duplicates = !allow_duplicates; };

// Menu
char print_menu() {
    char option{};

    cout << "-----------------------------------" << endl;
    cout << " Select an option" << endl;
    cout << "-----------------------------------" << endl;
    cout << " P - Print numbers" << endl;
    cout << " A - Add a number" << endl;
    cout << " M - Display mean of the numbers" << endl;
    cout << " S - Display the smallest number" << endl;
    cout << " L - Display the largest number" << endl << endl;
    cout << "   ----- Extra -----" << endl;
    cout << " D - Allow duplicates (" << get_allow_duplicates() <<")" << endl;
    cout << " N - Search for a number" << endl;
    cout << " C - Clear list" << endl << endl;
    cout << "-----------------------------------" << endl;
    cout << " Q - Quit" << endl;
    cout << "-----------------------------------" << endl << endl;
    cout << " Enter your choice: ";
    cin >> option;

    return option;
}

// For displaying vector contents.
void print_vector(const vector<int> &v) {
    if (v.size() == 0) {
        cout << "[] - the list is empty" << endl << endl;
    } else {
        cout << "[";
        for (auto n: v) {
            cout << " " << n;
        }
        cout << " ]" << endl << endl;
    }
}

// Adds a number to collection.
void add_number(const bool &duplicates, vector<int> &v) {

    bool exists {false};
    int numInput {};
    
    do {
        cout << "   Enter an integer: ";
        cin >> numInput;

        if (!duplicates) {

            exists = false;

            for (auto n: v) {
                if (n == numInput) {
                    exists = true;
                    cout << "   " << numInput << " is already in the list. Please, try again." << endl;
                    break;
                }
            }

        }
    } while (exists && !duplicates);

    v.push_back(numInput);
    cout << "   " << numInput << " added to collection" << endl << endl;

}

double calculate_mean(const vector<int> &v) {

    int sum {};

    for (auto n: v) {
        sum += n;
    }

    return (static_cast<double>(sum) / v.size());
}

int get_smallest(const vector<int> &v) {
    
    int smallest {v.at(0)};

    for (auto n: v) {
        smallest = (n < smallest) ? n : smallest;
    }

    return smallest;
}

int get_largest(const vector<int> &v) {

    int largest {v.at(0)};

    for (auto n: v) {
        largest = (n > largest) ? n : largest;
    }

    return largest;
}

int find_number(const vector<int> &v, const int &num) {
    
    int position {-1};
    int pos {};

    for (auto n: v) {
        if (n == num) {
            position = pos;
            break;
        }
        ++pos;
    }

    return position;
}

int find_duplicate(const vector<int> &v) {

    int position {-1};

    for (int i {0}; i < v.size(); ++i) {

        for (int j {i + 1}; j < v.size(); ++j) {
        
            if (v.at(i) == v.at(j)) {

                position = j;
                break;

            }
        
        }

    }

    return position;
}

int main() {

    vector<int> vec { 1, 34, 23, 9 };
    char option{};
    bool duplicates {false};

    cout << std::boolalpha;

    do {

        // Prints menu and get user option.
        option = print_menu();
        duplicates = get_allow_duplicates();

        // Just a frame to display result.
        cout << "\n\n=========== Output ================" << endl << endl;
        cout << "   ";

        if (option == 'p' || option == 'P') {
            // Displays vector contents.
            print_vector(vec);
        
        } else if (option == 'a' || option == 'A') {
            
            bool exists {false};
            (duplicates) ? cout << "Duplicates allowed" << endl : cout << "Duplicates NOT allowed" << endl;

            add_number(duplicates, vec);

        } else if (option == 'm' || option == 'M') {

            if (vec.size() > 0) {

                cout << "Average: " << calculate_mean(vec) << endl << endl;
                
            } else {
                
                cout << "Unable to calculate the mean - no data" << endl << endl;
            }

        } else if (option == 's' || option == 'S') {

            if (vec.size() > 0) {

                cout << "The smallest number is " << get_smallest(vec) << endl << endl;

            } else {

                cout << "Unable to determine the smallest number - list is empty" << endl << endl;

            }

        } else if (option == 'l' || option == 'L') {

            if (vec.size() > 0) {

                cout << "The largest number is " << get_largest(vec) << endl << endl;

            } else {

                cout << "Unable to determine the largest number - list is empty" << endl << endl;

            }

        } else if (option == 'n' || option == 'N') {

            int numInput {};
            int pos {};

            if (vec.size() == 0) {

                cout << "Unable to search - list is empty" << endl << endl;

            } else {

                cout << "Enter an integer to search for: ";
                cin >> numInput;

                pos = find_number(vec, numInput);

                if (pos > -1) {
                    cout << "   Number " << numInput << " found in the list at position " << pos << endl << endl;
                } else {
                    cout << "   Number " << numInput << " not found in the list" << endl << endl;
                }
            }

        } else if (option == 'c' || option == 'C') {

            char sure {};

            if (vec.size() == 0)
            {

                cout << "Unable to clear the list - no data" << endl << endl;

            } else {

                cout << "Are you sure? (y/n) ";
                cin >> sure;

                if (sure == 'y' || sure == 'Y') {

                    vec.clear();
                    cout << "   List cleared!" << endl << endl;

                } else if (sure == 'n' || sure == 'N') {

                    cout << "   Aborted" << endl << endl;

                } else {

                    cout << "   Invalid option - action ignored" << endl << endl;
                }
            }

        } else if (option == 'd' || option == 'D') {
            
            set_allow_duplicates();
            
            duplicates = get_allow_duplicates();
            (duplicates) ? cout << "Duplicates are allowed" : cout << "Duplicates are forbidden";

            if (!duplicates) {

                int duplicateAt {find_duplicate(vec)};

                if (duplicateAt > -1) {

                    cout << "   Found duplicate at position " << duplicateAt << ". List will be erased." << endl;
                    vec.clear();

                }

            }

            cout << endl << endl;

        } else if (option == 'q' || option == 'Q') {

            cout << "Goodbye" << endl << endl;
            cout << "===================================" << endl << endl;
            break;

        } else {

            cout << "Unknown selection, please try again." << endl;

        }

        cout << "===================================" << endl << endl;


    } while (true);

    return 0;
}