## Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -lncurses -lpanel
NOLINK = -c

# Traget file
TARGET = project.app

# Source files
SRC = src/

# Binary files
BIN = bin/

# Objects to build
OBJECTS0 = $(BIN)/menucli.o $(BIN)/vehicle.o $(BIN)/car.o $(BIN)/messages.o $(BIN)/dataSet.o $(BIN)/constants.o
OBJECTS = $(OBJECTS0) $(BIN)/truck.o

# Build rule
$(TARGET): $(SRC)/main.cpp $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)/main.cpp $(BIN)/*

$(BIN)/menucli.o: $(SRC)/menucli.cpp $(SRC)/menucli.h
	$(CXX) $(NOLINK) $(CXXFLAGS) -o $(BIN)/menucli.o $(SRC)/menucli.cpp

$(BIN)/dataSet.o: $(SRC)/dataSet.cpp $(SRC)/dataSet.h
	$(CXX) $(NOLINK) $(CXXFLAGS) -o $(BIN)/dataSet.o $(SRC)/dataSet.cpp

$(BIN)/constants.o: $(SRC)/constants.cpp $(SRC)/constants.h
	$(CXX) $(NOLINK) $(CXXFLAGS) -o $(BIN)/constants.o $(SRC)/constants.cpp

$(BIN)/messages.o: $(SRC)/messages.cpp $(SRC)/messages.h
	$(CXX) $(NOLINK) $(CXXFLAGS) -o $(BIN)/messages.o $(SRC)/messages.cpp

$(BIN)/vehicle.o: $(SRC)/vehicle.cpp $(SRC)/vehicle.h
	$(CXX) $(NOLINK) $(CXXFLAGS) -o $(BIN)/vehicle.o $(SRC)/vehicle.cpp

$(BIN)/car.o: $(SRC)/car.cpp $(SRC)/car.h $(BIN)/vehicle.o
	$(CXX) $(NOLINK) $(CXXFLAGS) -o $(BIN)/car.o $(SRC)/car.cpp

$(BIN)/truck.o: $(SRC)/truck.cpp $(SRC)/truck.h $(BIN)/vehicle.o
	$(CXX) $(NOLINK) $(CXXFLAGS) -o $(BIN)/truck.o $(SRC)/truck.cpp

# Run rule
run: $(TARGET)
	./$(TARGET)

# Clean rule
clean:
	rm $(BIN)/*
	rm project.app

