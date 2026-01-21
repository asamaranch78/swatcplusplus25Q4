## Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -lform -lncurses -lpanel
NOLINK = -c

# Default mode is release
MODE ?= release

ifeq ($(MODE),debug)
    CXXFLAGS += -g -O0
    BUILD_MSG = Building in DEBUG mode
else ifeq ($(MODE),release)
    CXXFLAGS += -O2
    BUILD_MSG = Building in RELEASE mode
else
    $(error Unknown MODE '$(MODE)'. Use MODE=debug or MODE=release)
endif

$(info $(BUILD_MSG))


# Traget file
TARGET = project.app

# Source files
SRC = src
VEHICLE = $(SRC)/vehicle
WINDOW = $(SRC)/windows
ADD_WIN = $(WINDOW)/addWindows
FILTER_WIN = $(WINDOW)/filterWindows
MISC = $(SRC)/misc
AUX = $(SRC)/aux

# Header files
INCLUDE = -I$(VEHICLE) -I$(WINDOW) -I$(MISC) -I$(ADD_WIN) -I$(AUX) -I$(FILTER_WIN)

# Binary files
BIN = bin

# Objects to build
ADD_WIN_OBJ = $(BIN)/addCarWindow.o $(BIN)/addTruckWindow.o
FILTER_WIN_OBJ = $(BIN)/yearWindow.o $(BIN)/manufacturerWindow.o
POP_WIN_OBJ = $(BIN)/selectionList.o
WINDOW_OBJ = $(BIN)/window.o $(BIN)/mainWindow.o $(BIN)/popUpWindow.o $(POP_WIN_OBJ) $(FILTER_WIN_OBJ)
VEHICLE_OBJ = $(BIN)/vehicle.o $(BIN)/truck.o $(BIN)/car.o
MISC_OBJ = $(BIN)/dataSet.o $(BIN)/constants.o $(BIN)/enums.o
AUX_OBJ = $(BIN)/addActions.o $(BIN)/filterActions.o
OBJECTS = $(WINDOW_OBJ) $(VEHICLE_OBJ) $(MISC_OBJ) $(ADD_WIN_OBJ)

# Build rule
# Main
$(TARGET): $(SRC)/main.cpp $(OBJECTS) $(AUX_OBJ)
	@echo "Building main"
	@$(CXX) $(CXXFLAGS) $(INCLUDE) -o $(TARGET) $(SRC)/main.cpp $(BIN)/*

$(BIN)/addActions.o: $(AUX)/addActions.cpp $(AUX)/addActions.h $(OBJECTS)
	@echo "Building add actions"
	@$(CXX) $(NOLINK) $(CXXFLAGS) $(INCLUDE) -o $(BIN)/addActions.o $(AUX)/addActions.cpp

$(BIN)/filterActions.o: $(AUX)/filterActions.cpp $(AUX)/filterActions.h $(OBJECTS)
	@echo "Building filter actions"
	@$(CXX) $(NOLINK) $(CXXFLAGS) $(INCLUDE) -o $(BIN)/filterActions.o $(AUX)/filterActions.cpp

# Miscelaneous module
$(BIN)/dataSet.o: $(MISC)/dataSet.cpp $(MISC)/dataSet.h
	@echo "Building data set"
	@$(CXX) $(NOLINK) $(CXXFLAGS) $(INCLUDE) -o $(BIN)/dataSet.o $(MISC)/dataSet.cpp

$(BIN)/constants.o: $(MISC)/constants.cpp $(MISC)/constants.h
	@echo "Building constants"
	@$(CXX) $(NOLINK) $(CXXFLAGS) $(INCLUDE) -o $(BIN)/constants.o $(MISC)/constants.cpp

$(BIN)/enums.o: $(MISC)/enums.cpp $(MISC)/enums.h
	@echo "Building enums"
	@$(CXX) $(NOLINK) $(CXXFLAGS) $(INCLUDE) -o $(BIN)/enums.o $(MISC)/enums.cpp

# Vehicle module
$(BIN)/vehicle.o: $(VEHICLE)/vehicle.cpp $(VEHICLE)/vehicle.h $(MISC_OBJ)
	@echo "Building vehicle"
	@$(CXX) $(NOLINK) $(CXXFLAGS) $(INCLUDE) -o $(BIN)/vehicle.o $(VEHICLE)/vehicle.cpp

$(BIN)/car.o: $(VEHICLE)/car.cpp $(VEHICLE)/car.h $(BIN)/vehicle.o $(MISC_OBJ)
	@echo "Building car"
	@$(CXX) $(NOLINK) $(CXXFLAGS) $(INCLUDE) -o $(BIN)/car.o $(VEHICLE)/car.cpp

$(BIN)/truck.o: $(VEHICLE)/truck.cpp $(VEHICLE)/truck.h $(BIN)/vehicle.o $(MISC_OBJ)
	@echo "Building truck"
	@$(CXX) $(NOLINK) $(CXXFLAGS) $(INCLUDE) -o $(BIN)/truck.o $(VEHICLE)/truck.cpp

# Window module
$(BIN)/window.o: $(WINDOW)/window.cpp $(WINDOW)/window.h $(MISC_OBJ)
	@echo "Building window"
	@$(CXX) $(NOLINK) $(CXXFLAGS) $(INCLUDE) -o $(BIN)/window.o $(WINDOW)/window.cpp

$(BIN)/mainWindow.o: $(WINDOW)/mainWindow.cpp $(WINDOW)/mainWindow.h $(BIN)/window.o $(MISC_OBJ)
	@echo "Building Main Window"
	@$(CXX) $(NOLINK) $(CXXFLAGS) $(INCLUDE) -o $(BIN)/mainWindow.o $(WINDOW)/mainWindow.cpp

$(BIN)/popUpWindow.o: $(WINDOW)/popUpWindow.cpp $(WINDOW)/popUpWindow.h $(BIN)/window.o $(MISC_OBJ)
	@echo "Building pop up window"
	@$(CXX) $(NOLINK) $(CXXFLAGS) $(INCLUDE) -o $(BIN)/popUpWindow.o $(WINDOW)/popUpWindow.cpp

# Add menus
$(BIN)/addCarWindow.o: $(ADD_WIN)/addCarWindow.cpp $(ADD_WIN)/addCarWindow.h $(BIN)/formWindow.o $(MISC_OBJ)
	@echo "Building add car window"
	@$(CXX) $(NOLINK) $(CXXFLAGS) $(INCLUDE) -o $(BIN)/addCarWindow.o $(ADD_WIN)/addCarWindow.cpp

$(BIN)/addTruckWindow.o: $(ADD_WIN)/addTruckWindow.cpp $(ADD_WIN)/addTruckWindow.h $(BIN)/formWindow.o $(MISC_OBJ)
	@echo "Building add truck window"
	@$(CXX) $(NOLINK) $(CXXFLAGS) $(INCLUDE) -o $(BIN)/addTruckWindow.o $(ADD_WIN)/addTruckWindow.cpp

# Filter menus
$(BIN)/yearWindow.o: $(FILTER_WIN)/yearWindow.cpp $(FILTER_WIN)/yearWindow.h $(BIN)/formWindow.o $(MISC_OBJ)
	@echo "Building ask for year interval window"
	@$(CXX) $(NOLINK) $(CXXFLAGS) $(INCLUDE) -o $(BIN)/yearWindow.o $(FILTER_WIN)/yearWindow.cpp

$(BIN)/manufacturerWindow.o: $(FILTER_WIN)/manufacturerWindow.cpp $(FILTER_WIN)/manufacturerWindow.h $(BIN)/formWindow.o $(MISC_OBJ)
	@echo "Building ask for manufacturer window"
	@$(CXX) $(NOLINK) $(CXXFLAGS) $(INCLUDE) -o $(BIN)/manufacturerWindow.o $(FILTER_WIN)/manufacturerWindow.cpp

# Pop up menus
$(BIN)/formDriver.o: $(WINDOW)/formDriver.cpp $(WINDOW)/formDriver.h $(MISC_OBJ)
	@echo "Building form driver"
	@$(CXX) $(NOLINK) $(CXXFLAGS) $(INCLUDE) -o $(BIN)/formDriver.o $(WINDOW)/formDriver.cpp

$(BIN)/selectionList.o: $(WINDOW)/selectionList.cpp $(WINDOW)/selectionList.h $(MISC_OBJ)
	@echo "Building selection list"
	@$(CXX) $(NOLINK) $(CXXFLAGS) $(INCLUDE) -o $(BIN)/selectionList.o $(WINDOW)/selectionList.cpp

$(BIN)/formWindow.o: $(WINDOW)/formWindow.cpp $(WINDOW)/formWindow.h $(BIN)/popUpWindow.o $(BIN)/formDriver.o $(MISC_OBJ)
	@echo "Building form window"
	@$(CXX) $(NOLINK) $(CXXFLAGS) $(INCLUDE) -o $(BIN)/formWindow.o $(WINDOW)/formWindow.cpp

# Run rule
run: $(TARGET)
	./$(TARGET)

# Clean rule
clean:
	rm -f $(BIN)/*
	rm -f project.app

