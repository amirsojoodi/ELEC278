# Tutorial 10 - Heap
# Code provided for ELEC-278 Tutorial at Queen's University
# @author AmirHossein Sojoodi
# @date 2022-11

.PHONY: all clean

BIN_DIR=./bin
SRC_DIR=./src

SRC_FILES:=$(wildcard $(SRC_DIR)/*.c)
BIN_FILES:=$(patsubst $(SRC_DIR)/%.c, $(BIN_DIR)/%, $(SRC_FILES))

all: | $(BIN_DIR) $(BIN_FILES)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(BIN_FILES): $(SRC_FILES)
	gcc $< -o $@

clean:
	rm -f $(BIN_DIR)/*
