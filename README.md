En este repositorio esta el desarrollo del proyecto final. El cual pedía lo siguiente: 



Overview



Create a C++ application that manages different types of vehicles (e.g., Car, Bike, Truck) using Object-Oriented Programming principles. The system should allow users to add, list, sort, filter, and compute fuel efficiency for vehicles. Additionally, implement data persistence in textfile (csv) (saving/loading) and leverage modern C++ features like STL containers, and lambdas. Extra bonus: smart pointers



Core Objectives OOP Design Base Class: Vehicle Common attributes: brand, model, year, fuelType, weight. Common methods: info(), fuelEfficiency(). Derived Classes: Car, Bike, Truck... Specialized attributes: Car: numDoors, trunkCapacity, etc. Bike: type (e.g., mountain, road), hasCarrier, etc. Truck: payloadCapacity, numAxles, etc. Use virtual methods for info() and fuelEfficiency(). Override methods: fuelEfficiency() and info() for each type.



Data Management



Use std::map or std::unordered\_set for indexing of vehicles by ID or brand.

Enums:

Define enums for fixed values like FuelType { Petrol, Diesel, Electric }.

Sample Data:

Preload a few vehicles for testing.

Mandatory Actions 1 Add Vehicle: - Prompt user for type and details. - Create appropriate derived object and store in the container. 2 List Vehicles: - Display all vehicles using polymorphic info(). 3 Sort Vehicles: - Sort by fuelEfficiency or year using lambdas and std::sort. 4 Filter Vehicles: - Filter by brand, fuel type, or year (and/or year range) using STL algorithms. 5 Compute Fuel Efficiency: - Each derived class implements its own formula. 6 Save/Load Data: - Save vehicle list to a file (e.g., CSV). - Load data back into memory. 7 Search by ID or Brand (optional): - Implement quick lookup using std::map. 8 Each methods must to have Exception Handling: - Handle invalid input.





-----------------------------------------------------------------------------------------------



Se han cumplido todos los requerimientos solicitados, los voy nombrando punto a punto:



1\. OOP – Diseño orientado a objetos

Clase base Vehicle

•	Atributos comunes:

&nbsp;		id, brand, model, year, fuelType, weight

•	Métodos virtuales:

o	info()

o	fuelEfficiency()

o	toCsvRow()

•	Destructor virtual 





2\. Clases derivadas

Se Implementó más de las pedidas:

Clase	Atributos específicos	Override

Car	puertas, maletero	

Truck	payload, ejes	

Bike	tipo, carrier	

Motorcycle	cilindrada, sidecar	





3\. Polimorfismo real

•	std::vector<std::unique\_ptr<Vehicle>>

•	Llamadas virtuales:

o	info()

o	fuelEfficiency()

•	Sin dynamic\_cast

•	Sin if(type)



4\. Eficiencia de combustible 

&nbsp;	NO se ingresa por el usuario

&nbsp;	NO se guarda como atributo

&nbsp;	Se calcula automáticamente a partir de los parámetros

&nbsp;	Cada tipo tiene su propia fórmula:

&nbsp;	double fuelEfficiency() const override;



5\. STL containers + lambdas

Se usó:

•	std::vector

•	std::unique\_ptr

•	std::sort con lambdas

•	std::copy\_if

•	std::any\_of

•	std::find\_if



6\. Acciones obligatorias

Requisito	Estado

Add vehicle	hecho

List vehicles   hecho

Sort vehicles	hecho

Filter vehicles	hecho

Compute efficiency	hecho

Search by ID	hecho

Exception handling	hecho





7\. Persistencia (CSV)

&nbsp;Guardar a CSV

&nbsp;Cargar desde CSV

&nbsp;Reconstrucción correcta por tipo



8\. Smart pointers 

•	std::unique\_ptr

•	Ownership claro

•	Sin memory leaks

•	Sin new / delete manual



9\. Menú interactivo

&nbsp;Menú CLI

&nbsp;Validación de entrada

&nbsp;Separación en clase Menu

&nbsp;main.cpp limpio





