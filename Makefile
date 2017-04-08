# 
# Xplode: Makefile
# Copyright (C) 2016 Bytes Club
#
# AUTHORS
# Rudra Nil Basu <rudra.nil.basu.1996@gmail.com>
#
TARGET = xplode

SRC = src
INC = inc
BIN = bin

SOURCE = $(wildcard $(SRC)/*.cpp)
OBJECT = $(patsubst %,$(BIN)/%, $(notdir $(SOURCE:.cpp=.o)))

CC = g++
CFLAGS = -lGL -lGLU -lglut -I$(INC)

$(BIN)/$(TARGET): $(OBJECT)
	$(CC) $^ -o $@ $(CFLAGS)

$(BIN)/%.o: $(SRC)/%.cpp
	@mkdir -p $(BIN)
	$(CC) $(CFLAGS) -c $< -o $@

help:
	@echo "src: $(SOURCE)"
	@echo "obj: $(OBJECT)"
