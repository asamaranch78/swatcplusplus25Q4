
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
	Vehicle <|-- ElectricCar
	Vehicle <|-- Motorbike
	
	class Vehicle {
		+string manufacturer
		+string model
		+uint year
		+uint weight
		+float fuelEfficiency
		+enum fueltype
		+enum type
		+info() void
		+fuelEfficiency() float
        +saveToFile(file) void
	}

	class Car {
		+uint doors
		+uint trunkCapacity
		+info() void
		+fuelEfficiency() float
        +saveToFile(file) void
	}

	class ElectricCar {
		+uint doors
		+uint trunkCapacity
		+uint range
		+info() void
		+fuelEfficiency() float
        +saveToFile(file) void
	}

	class Truck {
		+uint axles
		+uint payloadCapacity
		+info() void
		+fuelEfficiency(): float
        +saveToFile(file) void
	}

	class Motorbike {
		+uint seats
		+info() void
		+fuelEfficiency(): float
        +saveToFile(file) void
	}
```

This will be the four different type of classes, they will all have and info and fuel efficiency method. Info will display the data on the cli, fuel efficiency will calculate the fuel efficiency and save it. Fuel efficiency on gasoline and diesel cars will be calculated in l/100 km, on electric in miles per charge hour.

### Data

In order to handle the data a data class will be create, this will store shared pointers to all the vehicle class instances using a vector.
The data class will have the methods to import data from files and export it to files.

```mermaid
classDiagram
class DataSet {
    + vector *Vehivle dataSet
    + addVehicle(*Vehicle) void
    + numOfVehicle() uint
    + saveToFile(path) void
    + loadFromFile(path) void
    + readVehicle(id) *Vehicle
    + deleteAllData() void
}
```

### Menu - CLI

All the code to handle the menu will be encapsulated in a menu class to organise the code.

```mermaid
classDiagram
class Menu {
	- string [] menuMessage
	- char selectedOption
    + vector *Vehicle activeSet
	+ askForSelection ()
	+ handleSelected ()
	- addVehicle()
	- listVehicles()
	- filterVehicle()
	- filterByType() 
	- filterByBrand()
	- filterByYearRange()
	- computeFuelEfficiency()
	- exportData()
	- eraseData() 
	- importData()
	
}
```

The method on this class will be responsible of asking for the input from the user and call the necessary methods.

### TUI - Ncurses (Later)

```mermaid
classDiagram
    Window <-- PopUpWindow
    class Window {
        + WINDOW* window
        + int width
        + int height
        + int centerY
        + int centerX 
        + print(x, y, str, color)
        }
    class PopUpWindow {
        + close()
        }
```


## Class details

Details on the necessary methods

### Menu

Menu is the class that handle UI on the cli mode. Two methods one ask for a letter to select and operation from the user the other runs the operation. All menu messages are stored in const string, in the future this can be loaded from text adding multilanguage support.

This are the options to be selected by the user, all of them are coded by letter.

| Letter | Action |
| --- | --- |
| A | Add vehicles |
| F | Filter vehicles |
| L | List all vehicles |
| C | Calculate fuel efficiency |
| X | Export data |
| E | Erase data |
| I | Import data |

#### Add vechile

```mermaid
flowchart TD
A(["Ask for common data"])
B{"Switch Type"}
C["Ask for car data"]
D["Ask for electricCar data"]
E["Ask for truck data"]
F["Ask for motorbike data"]
G["Create vehicle object with the data"]
H["Add new object to dataSet"]
I(["Return 0"])
A --> B
B -- "car" --> C
B -- "electricCar" --> D
B -- "truck" --> E
B -- "motorbike" --> F
C --> G
D --> G
E --> G
F --> G
G --> H
H --> I
```

Each time user inputs data check validity and throw exception if invalid

#### Filter vehicle

```mermaid
flowchart TD
A(["Ask for type of filter"])
B{"Switch Filter"}
C["Ask Type"]
D{"for vhc type?"}
E["Display"]
F["Do nothing"]
G(["return 0"])
H["Ask year range"]
I["Ask brand"] 
J["Make loop"]
K["Make loop"]
L(["return 0"])
M(["return 0"])

A --> B 
B -- "type" --> C
C --> D
D -- "loopdone"--> G
D --"yes"--> E
D --"no"--> F
E --> D 
F --> D 
B --"year"--> H 
B --"brand"--> I 
H --> J
I --> K
J --> L
K --> M
```

#### List all vehicles

Loop through the entire dataset vector executing info method for each datapoint.

#### Calculate Fuel efficiency


#### Export data

```mermaid
flowchart TD
A(["Ask for directory to save"])
B{"if file conflict"}
C{"ask for replace"}
G(["Create csv header"])
H(["Execute save to csv in each data point"])
E(["return 0"])
F(["return 1"])

A --> B 
B --"yes"--> C 
B --"no"--> G
C --"no"--> F
C --"yes"--> G
G --> H
H --> E
```

#### Erase data

Loop through data set delete each object from memory and removing it from the data set vector

#### Import data

```mermaid
flowchart TD
A(["Ask for directory to load"])
B["throw and exception if no file"]
C{"for each line in csv"}
D["check type"]
E["check valid data"]
F["create object of type with data"]
G["add object to data set"]

A --> B
B --> C
C --> D 
D --> E
E --> F
F --> G
G --> C
