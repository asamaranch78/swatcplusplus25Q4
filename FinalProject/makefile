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
OBJECTS = menucli.o# Objects to builOBJECTS = screen.o# Objects to builOBJECTS = screen.o# Objects to builOBJECTS = screen.o

# Build rule
$(TARGET): $(SRC)/main.cpp $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)/main.cpp $(BIN)/*

screen.o: $(SRC)/screen.cpp $(SRC)/screen.h
	$(CXX) $(NOLINK) $(CXXFLAGS) -o $(BIN)/screen.o $(SRC)/screen.cpp

menucli.o: $(SRC)/menucli.cpp $(SRC)/menucli.h
	$(CXX) $(NOLINK) $(CXXFLAGS) -o $(BIN)/menucli.o $(SRC)/menucli.cpp

# Run rule
run: $(TARGET)
	./$(TARGET)

# Clean rule
clean:
	rm $(BIN)/*

