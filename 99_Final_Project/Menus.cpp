#include "Menus.h"

using std::cout;
using std::cin;
using std::endl;

void print_filter_menu()
{
    system("clear");
    cout << "=============================================" << endl;
    cout << "                   FILTER                    " << endl;
    cout << "=============================================" << endl;
    cout << " (1) By vehicle type" << endl;
    cout << " (2) By brand" << endl;
    cout << " (3) By model" << endl;
    cout << " (4) By year" << endl;
    cout << " (5) By years range" << endl;
    cout << " (6) By fuel type" << endl;
    cout << "=============================================" << endl;
    cout << " (0) Exit" << endl;
    cout << "=============================================" << endl;
    cout << endl;       
}

void print_sort_menu()
{
    system("clear");
    cout << "=============================================" << endl;
    cout << "                    SORT                     " << endl;
    cout << "=============================================" << endl;
    cout << " (1) By year" << endl;
    cout << " (2) By brand" << endl;
    cout << " (3) By model" << endl;
    cout << " (4) By efficiency" << endl;
    cout << " (5) By fuel type" << endl;
    cout << "=============================================" << endl;
    cout << " (0) Exit" << endl;
    cout << "=============================================" << endl;
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
        8 Each method must to have Exception Handling: - Handle invalid input.
    */

    system("clear");
    cout << "=============================================" << endl;
    cout << "               VEHICLES MANAGER              " << endl;
    cout << "=============================================" << endl;
    cout << " (1) Add Vehicle" << endl;
    cout << " (2) List Vehicles" << endl;
    cout << " (3) Search Vehicle" << endl;
    cout << " (4) Sort Vehicles" << endl;
    cout << " (5) Filter Vehicles" << endl;
    cout << " (6) Save Data" << endl;
    cout << " (7) Load Data" << endl;
    cout << "=============================================" << endl;
    cout << " (0) Exit" << endl;
    cout << "=============================================" << endl;
    cout << endl;
}

std::string ask_string(const std::string &question)
{
    while (true)
    {
        cout << question << ": ";
        std::string answer;
        std::getline(cin, answer);
        
        try
        {
            if (answer.empty())
            {
                throw EmptyArgumentException();
            }

            return answer;
        }
        catch (const EmptyArgumentException &e)
        {
            std::cerr << e.what() << endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}

int ask_int(const std::string &question, int maxValue, bool isLimited)
{
    while (true)
    {
        cout << question << ": ";
        std::string answer;
        std::getline(cin, answer);

        try
        {
            int num = std::stoi(answer);

            if (num < 0 || 
                (isLimited && num > maxValue))
            {
                throw InvalidOptionException();
            }

            return num;
        }
        catch (const InvalidOptionException &e)
        {
            std::cerr << e.what() << endl;
        }
        catch (...)
        {
            std::cerr << "Invalid input, try again." << endl;
        }
    }
}

double ask_double(const std::string &question, double maxValue, bool isLimited)
{
    while (true)
    {
        cout << question << ": ";
        std::string answer;
        std::getline(cin, answer);

        try
        {
            double num = std::stod(answer);

            if (num < 0 ||
                (isLimited && num > maxValue))
            {
                throw InvalidOptionException();
            }

            return std::stod(answer);
        }
        catch (const InvalidOptionException &e)
        {
            std::cerr << e.what() << endl;
        }
        catch(...)
        {
            std::cerr << "Invalid input, try again." << endl;
        }
    }
}