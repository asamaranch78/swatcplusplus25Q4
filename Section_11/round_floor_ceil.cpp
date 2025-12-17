/*
    Author: Juan M. Lagostena
    Nov 28, 2025
*/

#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::floor;
using std::round;
using std::ceil;

int main() {

    double userNumber{};

    double floorResult{};
    double roundResult{};
    double ceilResult{};

    // floor, round and ceil tests.
    cout << " Enter a number: ";
    cin >> userNumber;

    floorResult = floor(userNumber);
    roundResult = round(userNumber);
    ceilResult = ceil(userNumber);

    cout << endl;
    cout << " floor: " << floorResult << " Entero mas cercano y menor." << endl;
    cout << " round: " << roundResult << " Entero mas cercano (menor o mayor)." << endl;
    cout << " ceil : " << ceilResult << " Entero mas cercano y mayor." << endl;
    cout << endl;

    return 0;
}