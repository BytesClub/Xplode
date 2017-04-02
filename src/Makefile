# Copyright (C) BytesClub 2017,
# Author(s)
# Rudra Nil Basu <rudra.nil.basu.1996@gmail.com>

output: main.o game.o
	g++ main.o game.o -lGL -lGLU -lglut

main.o: main.cpp
	g++ -c main.cpp

game.o: game.cpp game.h
	g++ -c game.cpp

clean:
	rm *.o a.out
