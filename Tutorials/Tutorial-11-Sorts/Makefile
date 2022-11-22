# Tutorial 11 - Sorts
# Code provided for ELEC-278 Tutorial at Queen's University
# @author AmirHossein Sojoodi
# @date 2022-11

.PHONY: all clean

BIN_DIR=bin
SRC_DIR=src

SRC_FILES:=$(wildcard $(SRC_DIR)/*.c)
BIN_FILES:=$(patsubst $(SRC_DIR)/%.c, $(BIN_DIR)/%, $(SRC_FILES))

all: | $(BIN_DIR) $(BIN_FILES)

$(BIN_DIR):
	@echo "Folder $(BIN_DIR) does not exist!"
	mkdir -p $@

$(BIN_DIR)/%: $(SRC_DIR)/%.c
	gcc $< -o $@

clean:
	rm -rf $(BIN_DIR)/*.exe
