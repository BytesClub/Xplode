/*
 * Xplode - game.h
 * Copyright (C) 2016 Bytes Club
 * 
 * AUTHORS
 * Rudra Nil Basu <rudra.nil.basu.1996@gmail.com>
 */
#ifndef GAME_H
#define GAME_H

/*
 * File Guards:
 * To protect the file from getting included
 * more than once
 */

#define UP 1
#define DOWN -1
#define RIGHT 2
#define LEFT -2

void initGrid(int, int);
void drawGrid();
void drawSnake();

#endif
