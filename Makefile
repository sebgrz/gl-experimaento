CC := g++
V20 := -std=c++20
CFLAGS := -Wall -g $(V20) `sdl2-config --libs --cflags` 
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
	$(CC) $(V20) -o $@ $^ -lSDL2

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(TARGET) $(OBJ_DIR)

.PHONY: all clean
