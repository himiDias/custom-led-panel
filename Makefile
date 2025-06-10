#Makefile for Desk panel project

#---Directories---
SRC_DIR = src
INCLUDE_DIR = include
LIB_DIR = lib
BIN_DIR = bin
BUILD_DIR = build

#---Compiler,Linker---
CXX = g++
CXXFLAGS = -O3 -Wall -std=c++17
LDFLAGS = -L$(LIB_DIR)/rpi-rgb-led-matrix/lib
LDLIBS = -lrgbmatrix -lrt -lm -lpthread

#---Include---
INC_PATHS = -I$(INCLUDE_DIR) -I$(LIB_DIR)/rpi-rgb-led-matrix/include

#--Source---
SOURCES = $(SRC_DIR)/led/run_panel.cpp \
$(SRC_DIR)/led/panel_element.cpp \
$(SRC_DIR)/led/status_elem.cpp 

OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))

#---Executable---
TARGET = $(BIN_DIR)/run_panel

.PHONY: all clean run setup


$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $(OBJECTS) $(LDFLAGS) $(LDLIBS) -o $@
	@echo "Build successful: $(TARGET)"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INC_PATHS) -c $< -o $@
	@echo "Compiled: $<"

clean:
	@echo "Cleaning build artifacts..."
	$(RM) -r $(BUILD_DIR) $(BIN_DIR)

run: $(TARGET)
	@echo "Running $(TARGET)... (requires sudo)"
	sudo $(TARGET)

setup:
	@echo "Creating necessary directories..."
	@mkdir -p $(BIN_DIR) $(BUILD_DIR)
	@echo "Remember to build the rpi-rgb-led-matrix library in $(LIB_DIR)/rpi-rgb-led-matrix/"
	@echo " cd $(LIB_DIR)/rpi-rgb-led-matrix/ && make"