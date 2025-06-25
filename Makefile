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
INC_PATHS = -I$(INCLUDE_DIR) \
-I$(LIB_DIR)/rpi-rgb-led-matrix/include \
-I$(LIB_DIR)/Crow/include \
-I$(LIB_DIR)/asio/asio/include

#--Source---
LED_SOURCES = $(SRC_DIR)/led/run_panel.cpp \
$(SRC_DIR)/led/panel_element.cpp \
$(SRC_DIR)/led/status_elem.cpp \
$(SRC_DIR)/led/time_elem.cpp \
$(SRC_DIR)/led/main_elem.cpp \
$(SRC_DIR)/led/icon_elem.cpp \
$(SRC_DIR)/led/settings_icon.cpp \
$(SRC_DIR)/led/display_icon.cpp \
$(SRC_DIR)/led/games_icon.cpp \
$(SRC_DIR)/led/screensaver_icon.cpp \

LED_OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(LED_SOURCES))

#---Executable---
LED_TARGET = $(BIN_DIR)/run_panel

#---CROW SERVER---
CROW_SRC = $(SRC_DIR)/http_server/main.cpp
CROW_OBJ = $(BUILD_DIR)/http_server/main.o
CROW_TARGET = $(BIN_DIR)/http_server

.PHONY: all clean run setup

all: $(LED_TARGET) $(CROW_TARGET)

$(LED_TARGET): $(LED_OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $(LED_OBJECTS) $(LDFLAGS) $(LDLIBS) -o $@
	@echo "Build successful: $(LED_TARGET)"

$(CROW_TARGET): $(CROW_OBJ)
	@mkdir -p $(@D)
	$(CXX) $(CROW_OBJ) $(CXXFLAGS) $(INC_PATHS) -o $@
	@echo "Build successul: $(CROW_TARGET)"


$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INC_PATHS) -c $< -o $@
	@echo "Compiled: $<"

$(BUILD_DIR)/http_server/%.o: $(SRC_DIR)/http_server/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INC_PATHS) -c $< -o $@
	@echo "Compiled Crow Source: $<"

clean:
	@echo "Cleaning build artifacts..."
	$(RM) -r $(BUILD_DIR) $(BIN_DIR)

run: $(LED_TARGET)
	@echo "Running $(LED_TARGET)... (requires sudo)"
	sudo $(LED_TARGET)

run_crow: $(CROW_TARGET)
	@echo "Running $(CROW_TARGET)..."
	./$(CROW_TARGET)

setup:
	@echo "Creating necessary directories..."
	@mkdir -p $(BIN_DIR) $(BUILD_DIR)
	@echo "Remember to build the rpi-rgb-led-matrix library in $(LIB_DIR)/rpi-rgb-led-matrix/"
	@echo " cd $(LIB_DIR)/rpi-rgb-led-matrix/ && make"