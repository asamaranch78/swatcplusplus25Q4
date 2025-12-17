/*
    Author: Juan M. Lagostena
    Dec 3, 2025
*/

#include <iostream>

using std::cout;
using std::endl;

void print_array(const int *const, const size_t);
int *apply_all(const int *const, const size_t, const int *const, const size_t);

void print_array(const int *ptr, const size_t size) {

    cout << "\n--------------------------" << endl;
    cout << "\n[";
    for (int i {0}; i < size; ++i) {
        cout << " " << ptr[i];
    }
    cout << " ]\n";
    cout << "\n--------------------------" << endl;

}

int *apply_all(const int *arr1, const size_t size1, const int *arr2, const size_t size2) {

    int *arr_result = new int[size1 * size2];

    for (int i {0}; i < size1; ++i) {
        for (int j {0}; j < size2; ++j) {
            *(arr_result + (i + (j * size1))) = *(arr1 + i) * *(arr2 + j);
        }
    }

    return arr_result;
}

int main() {

    const int arr1[] { 1, 3, 2, 5, 8 };
    const int arr2[] { 3, 7, 12 };

    int *arr3 = apply_all(arr1, 5, arr2, 3);

    print_array(arr1, 5);
    print_array(arr2, 3);
    print_array(arr3, 15);

    cout << endl;
    return 0;
}
