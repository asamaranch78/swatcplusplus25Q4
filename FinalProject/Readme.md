
# Final project 

Create a C++ application that manages different types of vehicles (e.g., Car, Bike, Truck) using Object-Oriented Programming principles.
The system should allow users to add, list, sort, filter, and compute fuel efficiency for vehicles. 
Additionally, implement data persistence in textfile (csv) (saving/loading) and leverage modern C++ features like STL containers, and lambdas. Extra bonus: smart pointers

## Core Objectives - OOP Design

- Base Class:
- Vehicle
  - Common attributes: brand, model, year, fuelType, weight.
  - Common methods: info(), fuelEfficiency().
- Derived Classes:
  - Car, Bike, Truck...
    - Specialized attributes:
    - Car: numDoors, trunkCapacity, etc.
    - Bike: type (e.g., mountain, road), hasCarrier, etc.
    - Truck: payloadCapacity, numAxles, etc.
- Use virtual methods for info() and fuelEfficiency().
- Override methods: fuelEfficiency() and info() for each type.

More detail design later
   
## Data Management
  
Use std::map or std::unordered_set for indexing of vehicles by ID or brand.
Enums:
Define enums for fixed values like FuelType { Petrol, Diesel, Electric }.
Sample Data:
Preload a few vehicles for testing.

## Mandatory Actions

- Add Vehicle:
  - Prompt user for type and details.
  - Create appropriate derived object and store in the container.
- List Vehicles:
  - Display all vehicles using polymorphic info().
- Sort Vehicles:
  - Sort by fuelEfficiency or year using lambdas and std::sort.
- Filter Vehicles:
  - Filter by brand, fuel type, or year (and/or year range) using STL algorithms.
-  Compute Fuel Efficiency:
  - Each derived class implements its own formula.
- Save/Load Data:
  - Save vehicle list to a file (e.g., CSV).
  - Load data back into memory.
- Search by ID or Brand (optional):
  - Implement quick lookup using std::map.
- Each methods must to have Exception Handling:
  - Handle invalid input.

## Class diagram

```mermaid
classDiagram
	Vehicle <|-- Car
	Vehicle <|-- Truck
	Car <|-- ElectricCar
	Vehicle <|-- Motorbike
	
	class Vehicle {
		+string manufacturer
		+string model
		+uint year
		+uint weight
		+float fuelEfficiency
		+enum fueltype
		+enum type

		+fuelEfficiencyCalc(uint16_t, double) void
        +getFuelType() string
        +getType() string
        +getSpecial() string = 0
        +getYaml() YAML::node
        +loadYaml(YAML::node) void
	}

	class Car {
		+uint doors
		+uint trunkCapacity

        +getSpecial() string = 0
        +getYaml() YAML::node
        +loadYaml(YAML::node) void
	}

	class ElectricCar {
		+uint range

		+fuelEfficiencyCalc(uint16_t, double) void
        +getSpecial() string = 0
        +getYaml() YAML::node
        +loadYaml(YAML::node) void
	}

	class Truck {
		+uint axles
		+uint payloadCapacity

        +getSpecial() string = 0
        +getYaml() YAML::node
        +loadYaml(YAML::node) void
	}

	class Motorbike {
		+uint seats

        +getSpecial() string = 0
        +getYaml() YAML::node
        +loadYaml(YAML::node) void
	}
```

This will be the four different type of classes, they will all have and info and fuel efficiency method. Info will display the data on the cli, fuel efficiency will calculate the fuel efficiency and save it. Fuel efficiency on gasoline and diesel cars will be calculated in l/100 km, on electric in miles per charge hour.

### Data

In order to handle the data a data class will be create, this will store shared pointers to all the vehicle class instances using a vector.

```mermaid
classDiagram
class DataSet {
    + vector Vehicle* dataSet
    + vector Vehicle* fileteredData
    + vector Vehicle* displayedData
    + bool filtering

    - importCar(YAML::Node) void
    - importTruck(YAML::Node) void
    - importMotorbike(YAML::Node) void
    + addVehicle(Vehicle*) void
    + deleteVehicle(Vehicle*) void
    + deleteAllData() void
    + getDisplayData() vector Vechicle*
    + clearFilter() void
    + preFilter void
    + filterByYear(uint, uint) void
    + filterByManufacturer (string) void
    + filterByType(enum) void
    + exportToYaml(string) void
    + importFromYaml(string) void
}
```

### TUI - Ncurses

```mermaid
classDiagram
    Window <-- PopUpWindow
    Window <-- MainWindow
    PopUpWindow <-- FormWindow
    FormDriver <-- FormWindow
    PopUpWindow <-- SelectionList
    class Window {
        + WINDOW* window
        + int width
        + int height
        + int centerY
        + int centerX 
        + print(x, y, str, color) void
        + printBlankLine(line) void
        + removeColor(int color) void
        + changeColor(int color) void
        + refresh() void
    }
    class PopUpWindow {
        + PANEL *panel
        + WINDOW *mainWindow
        + close() void
        + refresh() void
        + putOnTop() void
        + hide() void
        + show() void
    }
    class MainWindow {
        + PANEL *panel
        + int pressedKey
        + int dataLines
        + int menuLine
        + int centerX
        + int centerY
        + int separatorLine
        + int cursor
        + int cursorMax
        + int cursorMin
        + listenKeyboard() bool
        + cursorDown() void
        + cursorUp() void
        + refresh() void
        + drawConstantPart() void
        + clearDisplayData() void
        + drawDisplayData(begin, end) void
    }
    class FormDriver {
        + int key
        + FORM *form
        + WINDOW *window
        + createForm(FIELD* [], sting) void
        + handleForm() void
        + destroyForm() void
    }
    class FormWindow {
        + FIELD *[]
        + vector string inputNames
    }
    class SelectionList {
        + Vector* string options
        + int cursor
        + int size
        + int key
        
        + cursorDown() void
        + cursorUp() void
        + handleList() int 
        + drawList() void
        + printOption() void
    }

```

All of the following classes will inherit from FromWindow, and will be use to get inputs form the user. If the data is impcomplete or wrongly formatted will get an error.

- AddCarWindow
- AddTruckWindow
- AddElectricWindow
- AddMotorbikeWindow
- YearWindow
- ManufacturerWindow
- PathWindow
- ElecFuelWindow
- fuelWindow

This classes are compose jsut by a contructor what sets up the fields, and a series of function that get the data from the form after saving by the user.
