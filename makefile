CUR_DIR=.
CC=g++
SRC_DIR=$(CUR_DIR)/src
BUILD_DIR=$(CUR_DIR)/build
INCLUDE_DIR=$(CUR_DIR)/include
BIN_DIR=$(CUR_DIR)/bin
LIB_DIR=$(CUR_DIR)/lib
VPATH=$(BUILD_DIR)

MATH_DIR=$(SRC_DIR)/math
CORE_DIR=$(SRC_DIR)/core
OBJ=exception.o main.o
EXE=$(BIN_DIR)/main.exe

$(EXE):$(OBJ)
	$(CC) -o $(EXE) $(OBJ)

main.o:
	$(CC) -c $(CUR_DIR)/main.cc -I$(INCLUDE_DIR)

exception.o:
	$(CC) -c $(CORE_DIR)/exception.cc -I$(INCLUDE_DIR)

clean:
	rm -rf $(OBJ)
	rm -rf $(BIN_DIR)/*
