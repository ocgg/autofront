# Output file name
TARGET = autofront

# Compilator
CXX = g++

# Standard & compilation opts
CXXFLAGS = -std=c++20 -Wall -Wextra -Iinclude -DCMAKE_EXPORT_COMPILE_COMMANDS=ON

# Folders
SRC_DIR = src
BUILD_DIR = build
LIB_DIR = lib

# Local libs (ex: -lmylib if libmylib.a)
LDFLAGS = -L$(LIB_DIR)
LDLIBS =

# All .cpp files in src/ & subfolders
SRCS = $(shell find $(SRC_DIR) -name "*.cpp")

# src/xxx.cpp to build/xxx.o
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Default rule (make with no arg)
all: $(TARGET)

# Link edits (?)
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS) $(LDLIBS)

# Compilation, from .cpp to .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

# Full clean
re: clean all

# Make args list
.PHONY: all clean re
