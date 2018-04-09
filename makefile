# CUR_DIR=$(shell pwd)
CUR_DIR=.
# echo $(CUR_DIR)
CC=g++
SRC_DIR=$(CUR_DIR)/src
BUILD_DIR=$(CUR_DIR)/build
INCLUDE_DIR=$(CUR_DIR)/include
BIN_DIR=$(CUR_DIR)/bin
VPATH=$(BUILD_DIR)

MATH_DIR=$(SRC_DIR)/math
CORE_DIR=$(SRC_DIR)/core
OBJ=asr_array.o asr_ops.o main.o
EXE=$(BIN_DIR)/main.exe

$(EXE): $(OBJ)
	$(CC) -o $(EXE) $(OBJ)

asr_array.o:
	$(CC) -c $(CORE_DIR)/asr_array.cc -I$(INCLUDE_DIR)

asr_ops.o:
	$(CC) -c $(MATH_DIR)/asr_ops.cc -I$(INCLUDE_DIR)

main.o:
	$(CC) -c $(CUR_DIR)/main.cc -I$(INCLUDE_DIR)


clean:
	rm -rf $(OBJ)
	rm -rf $(BIN_DIR)/*
