/*
 * Xplode - player.h
 * Copyright (C) 2016 Bytes Club
 *
 * AUTHORS
 * Rudra Nil Basu <rudra.nil.basu.1996@gmail.com>
 */
#include <GL/gl.h>
#include <GL/glut.h>

#include "player.h"
#include "game.h"

#include <stdio.h>

int posX = 20, posY = 20;
short sDirection = REST;
int currentState = ALIVE;

extern int gridX, gridY;

void drawPlayer()
{
	if(currentState == DEAD) {
		return;
	}
	if(posX <= 0 || posX >= gridX-1 || posY <= 0 || posY >= gridY-1) {
		currentState = DEAD;
		printf("DEAD\n");
		return;
	}
	if(sDirection == UP) {
		posY++;
	} else if(sDirection == DOWN) {
		posY--;
	} else if(sDirection == LEFT) {
		posX--;
	} else if(sDirection == RIGHT) {
		posX++;
	}
	glRectd(posX, posY, posX+1, posY+1);

}
