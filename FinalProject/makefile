## Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -lncurses -lpanel
NOLINK = -c

# Default mode is release
MODE ?= release

ifeq ($(MODE),debug)
    CXXFLAGS += -g -O0
    BUILD_MSG = "Building in DEBUG mode"
else ifeq ($(MODE),release)
    CXXFLAGS += -O2
    BUILD_MSG = "Building in RELEASE mode"
else
    $(error Unknown MODE '$(MODE)'. Use MODE=debug or MODE=release)
endif

$(info $(BUILD_MSG))


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
NCURSES_OBJ = $(BIN)/window.o $(BIN)/mainWindow.o
VEHICLE_OBJ = $(BIN)/vehicle.o $(BIN)/truck.o $(BIN)/car.o
OTHER_OBJ = $(BIN)/menucli.o $(BIN)/messages.o $(BIN)/dataSet.o $(BIN)/constants.o
OBJECTS = $(NCURSES_OBJ) $(VEHICLE_OBJ) $(OTHER_OBJ)

# Build rule
$(TARGET): $(SRC)/main.cpp $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $(TARGET) $(SRC)/main.cpp $(BIN)/*

$(BIN)/menucli.o: $(SRC)/menucli.cpp $(SRC)/menucli.h
	$(CXX) $(NOLINK) $(CXXFLAGS) $(INCLUDE) -o $(BIN)/menucli.o $(SRC)/menucli.cpp

$(BIN)/dataSet.o: $(SRC)/dataSet.cpp $(SRC)/dataSet.h
	$(CXX) $(NOLINK) $(CXXFLAGS) $(INCLUDE) -o $(BIN)/dataSet.o $(SRC)/dataSet.cpp

$(BIN)/constants.o: $(SRC)/constants.cpp $(SRC)/constants.h
	$(CXX) $(NOLINK) $(CXXFLAGS) $(INCLUDE) -o $(BIN)/constants.o $(SRC)/constants.cpp

$(BIN)/messages.o: $(SRC)/messages.cpp $(SRC)/messages.h
	$(CXX) $(NOLINK) $(CXXFLAGS) $(INCLUDE) -o $(BIN)/messages.o $(SRC)/messages.cpp

$(BIN)/vehicle.o: $(VEHICLE)/vehicle.cpp $(VEHICLE)/vehicle.h
	$(CXX) $(NOLINK) $(CXXFLAGS) $(INCLUDE) -o $(BIN)/vehicle.o $(VEHICLE)/vehicle.cpp

$(BIN)/car.o: $(VEHICLE)/car.cpp $(VEHICLE)/car.h $(BIN)/vehicle.o
	$(CXX) $(NOLINK) $(CXXFLAGS) $(INCLUDE) -o $(BIN)/car.o $(VEHICLE)/car.cpp

$(BIN)/truck.o: $(VEHICLE)/truck.cpp $(VEHICLE)/truck.h $(BIN)/vehicle.o
	$(CXX) $(NOLINK) $(CXXFLAGS) $(INCLUDE) -o $(BIN)/truck.o $(VEHICLE)/truck.cpp

$(BIN)/window.o: $(NCURSES)/window.cpp $(NCURSES)/window.h
	$(CXX) $(NOLINK) $(CXXFLAGS) $(INCLUDE) -o $(BIN)/window.o $(NCURSES)/window.cpp

$(BIN)/mainWindow.o: $(NCURSES)/mainWindow.cpp $(NCURSES)/mainWindow.h $(BIN)/window.o
	$(CXX) $(NOLINK) $(CXXFLAGS) $(INCLUDE) -o $(BIN)/mainWindow.o $(NCURSES)/mainWindow.cpp

# Run rule
run: $(TARGET)
	./$(TARGET)

# Clean rule
clean:
	rm -f $(BIN)/*
	rm -f project.app

