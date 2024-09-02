# Makefile (Win64) for compiling test.cpp and running a.exe

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -std=c++17 -D_INPUT

# Source file
SRC = test.cpp

# Input file 
INP = inp.txt

# Output executable
EXEC = a.exe

# Default target
all: $(EXEC)

# Rule to build the executable
$(EXEC): $(SRC)
	@$(CXX) $(CXXFLAGS) -o $(EXEC) $(SRC)

# Rule to run the executable
run: $(EXEC)
	@./$(EXEC) < $(INP)

# Clean target to remove the executable
clean:
	rm -rf $(EXEC) *.o

# Phony targets
.PHONY: all run clean
