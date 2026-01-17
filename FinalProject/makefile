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
MISC = $(SRC)/misc

# Header files
INCLUDE = -I$(VEHICLE) -I$(NCURSES) -I$(SRC) -I$(MISC)

# Binary files
BIN = bin

# Objects to build
POP_WIN_OBJ = $(BIN)/formDriver.o $(BIN)/addCarWindow.o
NCURSES_OBJ = $(BIN)/window.o $(BIN)/mainWindow.o $(BIN)/popUpWindow.o $(POP_WIN_OBJ)
VEHICLE_OBJ = $(BIN)/vehicle.o $(BIN)/truck.o $(BIN)/car.o
OTHER_OBJ = $(BIN)/dataSet.o $(BIN)/constants.o
OBJECTS = $(NCURSES_OBJ) $(VEHICLE_OBJ) $(OTHER_OBJ)

# Build rule
# Main
$(TARGET): $(SRC)/main.cpp $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $(TARGET) $(SRC)/main.cpp $(BIN)/*

# Vehicle module
$(BIN)/vehicle.o: $(VEHICLE)/vehicle.cpp $(VEHICLE)/vehicle.h
	$(CXX) $(NOLINK) $(CXXFLAGS) $(INCLUDE) -o $(BIN)/vehicle.o $(VEHICLE)/vehicle.cpp

$(BIN)/car.o: $(VEHICLE)/car.cpp $(VEHICLE)/car.h $(BIN)/vehicle.o
	$(CXX) $(NOLINK) $(CXXFLAGS) $(INCLUDE) -o $(BIN)/car.o $(VEHICLE)/car.cpp

$(BIN)/truck.o: $(VEHICLE)/truck.cpp $(VEHICLE)/truck.h $(BIN)/vehicle.o
	$(CXX) $(NOLINK) $(CXXFLAGS) $(INCLUDE) -o $(BIN)/truck.o $(VEHICLE)/truck.cpp

# Miscelaneous module
$(BIN)/dataSet.o: $(MISC)/dataSet.cpp $(MISC)/dataSet.h
	$(CXX) $(NOLINK) $(CXXFLAGS) $(INCLUDE) -o $(BIN)/dataSet.o $(MISC)/dataSet.cpp

$(BIN)/constants.o: $(MISC)/constants.cpp $(MISC)/constants.h
	$(CXX) $(NOLINK) $(CXXFLAGS) $(INCLUDE) -o $(BIN)/constants.o $(MISC)/constants.cpp

# Window module
$(BIN)/window.o: $(NCURSES)/window.cpp $(NCURSES)/window.h
	$(CXX) $(NOLINK) $(CXXFLAGS) $(INCLUDE) -o $(BIN)/window.o $(NCURSES)/window.cpp

$(BIN)/mainWindow.o: $(NCURSES)/mainWindow.cpp $(NCURSES)/mainWindow.h $(BIN)/window.o
	$(CXX) $(NOLINK) $(CXXFLAGS) $(INCLUDE) -o $(BIN)/mainWindow.o $(NCURSES)/mainWindow.cpp

$(BIN)/popUpWindow.o: $(NCURSES)/popUpWindow.cpp $(NCURSES)/popUpWindow.h $(BIN)/window.o
	$(CXX) $(NOLINK) $(CXXFLAGS) $(INCLUDE) -o $(BIN)/popUpWindow.o $(NCURSES)/popUpWindow.cpp

# Pop up menus
$(BIN)/addCarWindow.o: $(NCURSES)/addCarWindow.cpp $(NCURSES)/addCarWindow.h $(BIN)/popUpWindow.o $(BIN)/formDriver.o
	$(CXX) $(NOLINK) $(CXXFLAGS) $(INCLUDE) -o $(BIN)/addCarWindow.o $(NCURSES)/addCarWindow.cpp

$(BIN)/formDriver.o: $(NCURSES)/formDriver.cpp $(NCURSES)/formDriver.h
	$(CXX) $(NOLINK) $(CXXFLAGS) $(INCLUDE) -o $(BIN)/popUpWindow.o $(NCURSES)/popUpWindow.cpp

# Run rule
run: $(TARGET)
	./$(TARGET)

# Clean rule
clean:
	rm -f $(BIN)/*
	rm -f project.app

