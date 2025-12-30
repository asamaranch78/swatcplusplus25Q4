#include "Menus.h"

using std::cout;
using std::cin;
using std::endl;

void pause_menu(const char *message)
{
    cout << endl << message << endl;
    cin.get();
}

void print_filter_menu()
{
    system("clear");
    cout << "============================================================" << endl;
    cout << "                           FILTER                           " << endl;
    cout << "============================================================" << endl;
    cout << " (1) By vehicle type" << endl;
    cout << " (2) By brand" << endl;
    cout << " (3) By model" << endl;
    cout << " (4) By year" << endl;
    cout << " (5) By years range" << endl;
    cout << " (6) By fuel type" << endl;
    cout << "============================================================" << endl;
    cout << " (0) Exit" << endl;
    cout << "============================================================" << endl;
    cout << endl;       
}

void print_sort_menu()
{
    system("clear");
    cout << "============================================================" << endl;
    cout << "                            SORT                            " << endl;
    cout << "============================================================" << endl;
    cout << " (1) By year" << endl;
    cout << " (2) By brand" << endl;
    cout << " (3) By model" << endl;
    cout << " (4) By efficiency" << endl;
    cout << " (5) By fuel type" << endl;
    cout << "============================================================" << endl;
    cout << " (0) Exit" << endl;
    cout << "============================================================" << endl;
    cout << endl;    
}

void print_menu()
{
    /*
        Mandatory Actions 
        1 Add Vehicle: - Prompt user for type and details. - Create appropriate derived object and store in the container. 
        2 List Vehicles: - Display all vehicles using polymorphic info(). 
        3 Sort Vehicles: - Sort by fuelEfficiency or year using lambdas and std::sort. 
        4 Filter Vehicles: - Filter by brand, fuel type, or year (and/or year range) using STL algorithms. 
        5 Compute Fuel Efficiency: - Each derived class implements its own formula. 
        6 Save/Load Data: - Save vehicle list to a file (e.g., CSV). - Load data back into memory. 
        7 Search by ID or Brand (optional): - Implement quick lookup using std::map. 
        8 Each methods must to have Exception Handling: - Handle invalid input.
    */

    system("clear");
    cout << "============================================================" << endl;
    cout << "                     VEHICLES MANAGER" << endl;
    cout << "============================================================" << endl;
    cout << " (1) Add Vehicle" << endl;
    cout << " (2) List Vehicles" << endl;
    cout << " (3) Search Vehicle" << endl;
    cout << " (4) Sort Vehicles" << endl;
    cout << " (5) Filter Vehicles" << endl;
    cout << " (6) Save Data" << endl;
    cout << " (7) Load Data" << endl;
    cout << "============================================================" << endl;
    cout << " (0) Exit" << endl;
    cout << "============================================================" << endl;
    cout << endl;
}

int get_menu_option(int maxValue)
{
    std::string user_line {};

    while (true)
    {
        cin.clear();
        cout << " Choose an option: ";

        // Avoid EOF errors, cin buffer errors and Ctrl+Z input in console.
        if (!getline(cin, user_line))
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            cout << "Invalid input. Please, try again." << endl << endl;
            continue;
        }

        if (user_line.size() == 1 && std::isdigit(static_cast<unsigned char>(user_line[0])))
        {
            int result = user_line[0] - '0';

            if (result <= maxValue)
            {
                return result;
            }
        }
                
        cout << "Please, enter a number between 0 and " << maxValue << endl << endl;
    }
}
