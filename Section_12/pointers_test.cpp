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

void pointers_sample_1();
void swap_pointers(int *, int *);

void pointers_sample_1() {

    int scores[] { 10, 25, 658 };
    int *scores_ptr {scores};

    cout << "scores: " << scores << ", scores_ptr: " << scores_ptr << endl;
    cout << "scores[0]: " << scores[0] << ", scores_ptr[0]: " << scores_ptr[0] << endl;
    cout << "scores[1]: " << scores[1] << ", scores_ptr[1]: " << scores_ptr[1] << endl;
    cout << "scores[2]: " << scores[2] << ", scores_ptr[2]: " << scores_ptr[2] << endl;
    
    cout << "-----------------------------------" << endl;
    
    cout << "scores: " << scores << ", scores_ptr: " << scores_ptr << endl;
    cout << "&scores[1]: " << &scores[1] << ", (scores_ptr + 1): " << (scores_ptr + 1) << endl;
    cout << "&scores[2]: " << &scores[2] << ", (scores_ptr + 2): " << (scores_ptr + 2) << endl;

    cout << "-----------------------------------" << endl;

    *(scores_ptr + 1) = 3;
    cout << "scores[1]: " << scores[1] << ", scores_ptr[1]: " << scores_ptr[1] << endl;
}

void reverse_array(int* arr, int size) {
    //-- Write your code below this line 
    int i {0};
    int max {size - 1};
    
    while (i < (size / 2)) { // size = 5 => 1 < 2, 2 < 2 -- STOP
        // Swap
        
        *(arr + i) = *(arr + i) + *(arr + max);
        *(arr + max) = *(arr + i) - *(arr + max);
        *(arr + i) = *(arr + i) - *(arr + max);
        
        --max;
        ++i;
    }
    //-- Write your code above this line
}

string reverse_string(const string &str) {
    string reversed (str.size(), ' ');

    cout << str.size() << endl;

    // Write your code below this line 
    for (int i {str.size() - 1}; i >= 0; --i) {

        reversed.at((str.size() - 1) - i) = str[i];
        //cout << ((str.size() - 1) - i) << ", " << i << endl;

    }
    // Write your code abocve this line
    return reversed;
}

int main() {

    //pointers_sample_1();

    /*
    int arr [] { 1, 2, 3, 4 };
    int *ptr {arr};

    string phrase {"Hello"};
    string reverse {reverse_string(phrase)};

    cout << "phrase: " << phrase << endl;
    cout << "reverse: " << reverse << endl;
    cout << "-------------------" << endl;

    reverse_array(ptr, 4);

        for (auto n: arr) {
        cout << n << endl;
    }
    */

    int *data = new int[5];
 
    for (int i = 0; i<5; i++)
    *(data + i) = i*2;
    
    for (int i = 0; i<=4; i++)
    cout << data[i] << " " ;
    cout << endl;   
    
    delete [] data;

    cout << endl;
    return 0;
}