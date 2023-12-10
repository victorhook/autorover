CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic -DPLATFORM_LINUX

SRC_DIR = src
BUILD_DIR = build
TARGET = autorover_linux

# List of source files
SRCS = $(SRC_DIR)/main.cpp \
	   $(SRC_DIR)/autorover.cpp \
	   $(SRC_DIR)/settings.cpp \

# Generate a list of object files from the source files
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

# Main target
$(BUILD_DIR)/$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to generate object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Clean rule
clean:
	rm -f $(TARGET) $(BUILD_DIR)/*.o

# Phony target to avoid conflicts with file names
.PHONY: clean