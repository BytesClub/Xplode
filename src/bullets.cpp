/*
 * Xplode - bullets.cpp
 * Copyright (C) 2016 Bytes Club
 *
 * AUTHORS
 * Rudra Nil Basu <rudra.nil.basu.1996@gmail.com>
 */

#include "bullets.h"
#include "declaration.h"

#include <GL/gl.h>
#include <GL/glut.h>
#include <vector>

std::vector<struct bullet> bullets;

void drawBullets()
{
	glColor3f(1.0, 0.0, 0.0);
	for(int i = 0;i < bullets.size();i++) {
		glRectd(bullets[i].x + 0.25, bullets[i].y + 0.25, bullets[i].x + 0.75, bullets[i].y + 0.75);
	}
}

void move_bullet()
{
	for(int i = 0;i < bullets.size();i++) {
		if (bullets[i].dir == UP) {
			bullets[i].y++;
		} else if (bullets[i].dir == DOWN) {
			bullets[i].y--;
		} else if(bullets[i].dir == LEFT) {
			bullets[i].x--;
		} else if(bullets[i].dir == RIGHT) {
			bullets[i].x++;
		}
	}
}