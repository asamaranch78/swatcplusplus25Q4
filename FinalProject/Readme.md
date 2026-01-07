# Final project 

Create a C++ application that manages different types of vehicles (e.g., Car, Bike, Truck) using Object-Oriented Programming principles.
The system should allow users to add, list, sort, filter, and compute fuel efficiency for vehicles. 
Additionally, implement data persistence in textfile (csv) (saving/loading) and leverage modern C++ features like STL containers, and lambdas. Extra bonus: smart pointers

## Core Objectives

- OOP Design
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

'''mermaid
A --> B
'''
