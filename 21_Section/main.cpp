/*
    Author: Juan M. Lagostena
    Dec 18, 2025
*/

#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> nums { 1, 3, 76, 12, 4, 8 };

    std::sort(nums.begin(), nums.end(), [] (int a, int b) {
        return a < b;
    });

    for (auto n: nums)
    {
        cout << n << " " << endl;
    }

    return 0;
}