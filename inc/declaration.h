/*
 * Xplode - declaration.h
 * Copyright (C) 2016 Bytes Club
 *
 * AUTHORS
 * Rudra Nil Basu <rudra.nil.basu.1996@gmail.com>
 */

/*
 * declarations: Contains global variables required
 * for all the files
 */

/* 
 * Player properties:
 * State: Alive or Dead
 * Movement: Current direction of movement
 */
#ifndef DECLARATION_H
#define DECLARATION_H

#define ALIVE 1
#define DEAD 0

#define UP 1
#define DOWN -1
#define RIGHT 2
#define LEFT -2
#define REST 0

/*
 * Bullets
 */
#define BULLET_SPEED 2

extern short sDirection;
extern int currentState;

#endif
