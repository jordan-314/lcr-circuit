# Compiler
CXX = g++

# Compilation flags
CXXFLAGS = -std=c++20 -I./includes/

# Directories
SRC_DIR = src

# Output executable
EXEC = lcr

# Default target
all: $(EXEC)

$(EXEC):
	$(CXX) $(SRC_DIR)/*.cpp $(CXXFLAGS)