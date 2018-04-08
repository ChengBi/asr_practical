CUR_DIR=$(shell pwd)
# echo $(CUR_DIR)
CC=gcc
SRC_DIR=$(CUR_DIR)/src
BUILD_DIR=$(CUR_DIR)/build
INCLUDE_DIR=$(CUR_DIR)/include
BIN_DIR=$(CUR_DIR)/bin
VPATH=$(BUILD_DIR)

MATH_DIR=$(SRC_DIR)/math
OBJ=$(BUILD_DIR)/ops.o $(BUILD_DIR)/main.o
EXE=$(BIN_DIR)/main

$(EXE): $(OBJ)
	$(shell mv $(CUR_DIR)/*.o $(BUILD_DIR)/)
	$(CC) -o $(EXE) $(OBJ)

$(BUILD_DIR)/ops.o:
	$(CC) -c $(MATH_DIR)/ops.cc -I $(INCLUDE_DIR)

$(BUILD_DIR)/main.o:
	$(CC) -c $(MATH_DIR)/main.cc -I $(INCLUDE_DIR)


clean:
	rm -rf $(BUILD_DIR)/*.o
