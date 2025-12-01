## Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

# Target executable
TARGET = pyramid

# Source files
SRC = main.cpp

# Build rule
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Run rule
run: $(TARGET)
	./$(TARGET)
	rm $(TARGET)

# Clean rule
clean:
	rm $(TARGET) $(OBJ)
