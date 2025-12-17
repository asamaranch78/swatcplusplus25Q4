hello World, 

Este es el repositorio para subir las practicas. podeis crearos una o más ramas para subir las diferentes práctica.

Crearos una rama siguiendo estas indicaciones:

✅ Opción 2: Usando GitHub UI (sin consola)

Ve al repositorio vacío en GitHub.
En la vista de código, usa el selector de ramas (Branch: main <-- arriba izquierda) y escribe el nombre de la nueva rama para crear y cambiar a esa rama.



practica final enunciado:

**Overview**

Create a C++ application that manages different types of vehicles (e.g., Car, Bike, Truck) using Object-Oriented Programming principles. The system should allow users to add, list, sort, filter, and compute fuel efficiency for vehicles. Additionally, implement data persistence (saving/loading) and leverage modern C++ features like smart pointers, STL containers, and lambdas.

**Core Objectives**
OOP Design

Base Class:
Vehicle

Common attributes: brand, model, year, fuelType, weight.
Common methods: info(), fuelEfficiency().

Derived Classes:
Car, Bike, Truck,...

Specialized attributes:
Car: numDoors, trunkCapacity, etc.
Bike: type (e.g., mountain, road), hasCarrier, etc.
Truck: payloadCapacity, numAxles, etc.

Override fuelEfficiency() and info() for each type.

Use virtual methods for info() and fuelEfficiency().
Override fuelEfficiency() and info() for each type.

Data Management

Use std::map or std::unordered_set for indexing of vehicles by ID or brand.

Enums:
Define enums for fixed values like FuelType { Petrol, Diesel, Electric }.

Sample Data:
Preload a few vehicles for testing.

**Operations**

Add Vehicle:
- Prompt user for type and details.
- Create appropriate derived object and store in the container.

List Vehicles:
- Display all vehicles using polymorphic info().

Sort Vehicles:
- Sort by fuelEfficiency or year using lambdas and std::sort.

Filter Vehicles:
- Filter by brand, fuel type, or year (and/or year range) using STL algorithms.

Compute Fuel Efficiency:
- Each derived class implements its own formula.

Save/Load Data:
- Save vehicle list to a file (e.g., CSV).
- Load data back into memory.

Search by ID or Brand (optional):
- Implement quick lookup using std::map.

Exception Handling (optional):
- Handle invalid input.
