## Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -lncurses -lpanel
NOLINK = -c

# Traget file
TARGET = project.app

# Source files
SRC = src
VEHICLE = $(SRC)/vehicle
NCURSES = $(SRC)/ncurses

# Header files
INCLUDE = -I$(VEHICLE) -I$(NCURSES) -I$(SRC)

# Binary files
BIN = bin

# Objects to build
NCURSES_OBJ = 
VEHICLE_OBJ = $(BIN)/vehicle.o $(BIN)/truck.o $(BIN)/car.o
OTHER_OBJ = $(BIN)/menucli.o $(BIN)/messages.o $(BIN)/dataSet.o $(BIN)/constants.o
OBJECTS = $(NCURSES_OBJ) $(VEHICLE_OBJ) $(OTHER_OBJ)

# Build rule
$(TARGET): $(SRC)/main.cpp $(OBJECTS) DIRS
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $(TARGET) $(SRC)/main.cpp $(BIN)/*

$(BIN)/menucli.o: $(SRC)/menucli.cpp $(SRC)/menucli.h DIRS
	$(CXX) $(NOLINK) $(CXXFLAGS) $(INCLUDE) -o $(BIN)/menucli.o $(SRC)/menucli.cpp

$(BIN)/dataSet.o: $(SRC)/dataSet.cpp $(SRC)/dataSet.h DIRS
	$(CXX) $(NOLINK) $(CXXFLAGS) $(INCLUDE) -o $(BIN)/dataSet.o $(SRC)/dataSet.cpp

$(BIN)/constants.o: $(SRC)/constants.cpp $(SRC)/constants.h DIRS
	$(CXX) $(NOLINK) $(CXXFLAGS) $(INCLUDE) -o $(BIN)/constants.o $(SRC)/constants.cpp

$(BIN)/messages.o: $(SRC)/messages.cpp $(SRC)/messages.h DIRS
	$(CXX) $(NOLINK) $(CXXFLAGS) $(INCLUDE) -o $(BIN)/messages.o $(SRC)/messages.cpp

$(BIN)/vehicle.o: $(VEHICLE)/vehicle.cpp $(VEHICLE)/vehicle.h DIRS
	$(CXX) $(NOLINK) $(CXXFLAGS) $(INCLUDE) -o $(BIN)/vehicle.o $(VEHICLE)/vehicle.cpp

$(BIN)/car.o: $(VEHICLE)/car.cpp $(VEHICLE)/car.h $(BIN)/vehicle.o DIRS
	$(CXX) $(NOLINK) $(CXXFLAGS) $(INCLUDE) -o $(BIN)/car.o $(VEHICLE)/car.cpp

$(BIN)/truck.o: $(VEHICLE)/truck.cpp $(VEHICLE)/truck.h $(BIN)/vehicle.o DIRS
	$(CXX) $(NOLINK) $(CXXFLAGS) $(INCLUDE) -o $(BIN)/truck.o $(VEHICLE)/truck.cpp

#Ensure directories exist
DIRS:
	mkdir -p bin

# Run rule
run: $(TARGET)
	./$(TARGET)

# Clean rule
clean:
	rm -f $(BIN)/*
	rm -f project.app

