# Makefile for Memory Addressing C++ Project

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Wpedantic -O0 -g
INCLUDES = -I include/

# Source files and executables
SRC_DIR = src
BIN_DIR = bin
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
EXECUTABLES = $(patsubst $(SRC_DIR)/%.cpp,$(BIN_DIR)/%,$(SOURCES))

# Targets
.PHONY: all clean help run-all act1 act2 act3 act4 extra

all: $(EXECUTABLES)

$(BIN_DIR)/%: $(SRC_DIR)/%.cpp
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ $<

act1: $(BIN_DIR)/activity1
	./$(BIN_DIR)/activity1

act2: $(BIN_DIR)/activity2
	./$(BIN_DIR)/activity2

act3: $(BIN_DIR)/activity3
	./$(BIN_DIR)/activity3

act4: $(BIN_DIR)/activity4
	./$(BIN_DIR)/activity4

extra: $(BIN_DIR)/extra
	./$(BIN_DIR)/extra

run-all: $(EXECUTABLES)
	@echo "--- Running all activities ---"
	@./$(BIN_DIR)/activity1
	@./$(BIN_DIR)/activity2
	@./$(BIN_DIR)/activity3
	@./$(BIN_DIR)/activity4
	@./$(BIN_DIR)/extra
	@echo "--- All activities finished ---"

clean:
	rm -rf $(BIN_DIR)

help:
	@echo "Available targets:"
	@echo "  make all      -> Compiles all executables"
	@echo "  make act1     -> Compiles and runs activity1"
	@echo "  make act2     -> Compiles and runs activity2"
	@echo "  make act3     -> Compiles and runs activity3"
	@echo "  make act4     -> Compiles and runs activity4"
	@echo "  make extra    -> Compiles and runs the extra"
	@echo "  make run-all  -> Runs all compiled activities in sequence"
	@echo "  make clean    -> Removes all compiled binaries"
	@echo "  make help     -> Shows this help message"
