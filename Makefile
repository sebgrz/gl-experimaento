CC := g++
V20 := -std=c++20
CFLAGS := -Wall -g $(V20) `sdl2-config --libs --cflags` 
GLEW_HEADERS := -Iglew/include
TARGET := main
SRC_DIR := src
OBJ_DIR := obj
MAIN := $(SRC_DIR)/main.cpp

#Other solution which use only make wildcards
#https://stackoverflow.com/a/12959764
SRCS := $(shell find $(SRC_DIR) -name "*.cpp")

SRCS_OBJS := $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SRCS))
OBJS := $(patsubst %.cpp,%.o,$(SRCS_OBJS))

all: clean $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(V20) $(GLEW_HEADERS)  -o $@ $^ -lSDL2 -lGL glew/lib/libGLEW.a
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(GLEW_HEADERS) -c $< -o $@

clean:
	rm -rf $(TARGET) $(OBJ_DIR)

.PHONY: all clean
