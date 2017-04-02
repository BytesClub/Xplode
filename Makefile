# 
#	#$(CC)  -o $@ $^ $(CFLANGS)
#	$(CC) $^ $(CFLANGS)
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
	$(CC) $(CFLAGS) -c $< -o $@

help:
	@echo "src: $(SOURCE)"
	@echo "obj: $(OBJECT)"
