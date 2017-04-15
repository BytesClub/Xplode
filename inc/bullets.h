/*
 * Xplode - bullets.h
 * Copyright (C) 2016 Bytes Club
 *
 * AUTHORS
 * Rudra Nil Basu <rudra.nil.basu.1996@gmail.com>
 */
#ifndef BULLETS_H
#define BULLETS_H

#include <vector>

struct bullet {
	int x;
	int y;
	int dir;
};

extern std::vector<struct bullet> bullets;

void drawBullets();
void move_bullet();

#endif
