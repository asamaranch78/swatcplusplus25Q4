// Challenge

/* 
    Frank's Carpet Cleaning Service
    Charges:
        $25 per small room
        $35 per large room
    Sales tax rate is 6%
    Estimates are valid for 30 days

    Prompt the user for the number of small and large rooms they would like cleaned
    and provide an estimate such as:
     
Estimate for carpet cleaning service
Number of small rooms: 3
Number of large rooms: 1
Price per small room: $25
Price per large room: $35
Cost : $110
Tax: $6.6
===============================
Total estimate: $116.6
This estimate is valid for 30 days
*/

#include <iostream>

using namespace std;

int main() {
    
    const float priceSmallRoom = 25;
    const float priceLargeRoom = 35;
    const float saleTax = 0.06;
    const float estimateValidity = 30;

    int smallRoom, largeRoom;

    //Prompt the user
    cout << "Frank's Carpet Cleaning Service" << endl;
    cout << "Charges:" << endl;
    cout << "    $" << priceSmallRoom << " per small room" << endl;
    cout << "    $" << priceLargeRoom << " per large room" << endl;
    cout << "Sales tax rate is " << saleTax << "%" << endl;
    cout << "Estimates are valid for " << estimateValidity << " days" << endl;
    cout << "=========================================" << endl;

    cout << "How many small room?" << endl;
    cin >> smallRoom;
    cout << "How many large room?" << endl;
    cin >> largeRoom;

    //Calculate estimate
    float cost = 0;
    cost = smallRoom * priceSmallRoom;
    cost = cost + largeRoom * priceLargeRoom;

    float tax;
    tax = cost * saleTax;

    float estimate;
    estimate = cost + tax;

    //Output
    cout << "Estimate for carpet cleaning service" << endl;
    cout << "Number of small rooms: " << smallRoom << endl;
    cout << "Number of large rooms: " << largeRoom << endl;
    cout << "Price per small room: $" << priceSmallRoom << endl;
    cout << "Price per large room: $" << priceLargeRoom << endl;
    cout << "Cost : $" << cost << endl;
    cout << "Tax: $" << tax << endl;
    cout << "===============================" << endl;
    cout << "Total estimate: $" << estimate << endl;
    cout << "This estimate is valid for " << estimateValidity << " days" << endl;
    
    cout << endl;
    return 0;
}
