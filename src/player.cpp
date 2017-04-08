/*
 * Xplode - player.cpp
 * Copyright (C) 2016 Bytes Club
 *
 * AUTHORS
 * Rudra Nil Basu <rudra.nil.basu.1996@gmail.com>
 */
#include <GL/gl.h>
#include <GL/glut.h>

#include "player.h"
#include "game.h"


short sDirection = REST;
int currentState = ALIVE;

int posX, posY;
extern int gridX, gridY;

void startPlayer(int x, int y)
{
	posX = x;
	posY = y;
}

void drawPlayer()
{
	if(currentState == DEAD) {
		return;
	}
	if(posX <= 0 || posX >= gridX-1 || posY <= 0 || posY >= gridY-1) {
		currentState = DEAD;
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
	glColor3f(0.0, 1.0, 1.0);
	glRectd(posX, posY, posX+1, posY+1);

}

int getPlayerX()
{
	return posX;
}

int getPlayerY()
{
	return posY;
}

int getPlayerDirection()
{
	return sDirection;
}
