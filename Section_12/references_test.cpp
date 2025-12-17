/*
    Author: Juan M Lagostena
    Dec 2, 2025
*/

#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

void print_vector(const vector<string> str) {
    for (auto const &s: str) {
        cout << s << endl;
    }

    cout << "----------------" << endl << endl;
}

int main() {

    vector<string> stooges { "Larry", "Moe", "Curly" };


    print_vector(stooges);

    // En este ejemplo, str es una COPIA de los elementos de stooges, por lo que no va a modificar el vector original.
    for (auto str: stooges) {
        str = "Funny";
    }

    print_vector(stooges);

    // Ahora, str es una REFERENCIA a los elementos, por lo que modificara el contenido del vector.
    for (auto &str: stooges) {
        str = "Funny";
    }

    print_vector(stooges);

    cout << endl;
    return 0;
}