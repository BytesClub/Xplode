/*
 * Xplode - main.cpp
 * 
 * Copyright (C) 2016 Bytes Club
 *
 * AUTHORS:
 * Rudra Nil Basu <rudra.nil.basu.1996@gmail.com>
 */

#include<GL/gl.h>
#include<GL/glut.h>
#include<vector>

#include "game.h"
#include "player.h"

#include<stdio.h>

#define ROWS 40
#define COLUMNS 40
#define FPS 10

/*
 * Keyboard Keys
 */

#define SPACEBAR 32

void timer_callback(int);
void display_callback();
void reshape_callback(int w, int h);
void init();
void drawBullets();
void keyboard_callback(int, int, int);
void normal_key(unsigned char, int, int);

extern short sDirection;

struct bullet {
	int x;
	int y;
	int dir;
};

std::vector<struct bullet> bullets;

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1200,1200); // 600, 600
	glutCreateWindow("Xplode");
	glutDisplayFunc(display_callback);
	glutReshapeFunc(reshape_callback);
	glutTimerFunc(0,timer_callback,0);
	glutSpecialFunc(keyboard_callback);
	glutKeyboardFunc(normal_key);
	init();
	glutMainLoop();
	return 0;
}

void init()
{
	glClearColor(0.0,0.0,0.0,0.0);
	initGrid(ROWS, COLUMNS);
	startPlayer(20,20);
}

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

void display_callback()
{
	glClear(GL_COLOR_BUFFER_BIT);
	drawGrid();
	drawPlayer();
	drawBullets();
	/*
	 * For Double Buffering, read https://www2.cs.arizona.edu/classes/cs433/spring02/opengl/dblbuffer.html
	 */
	glutSwapBuffers();
}

void reshape_callback(int w, int h)
{
	/*
	 * Called when the window is reshaped
	 * and when the window is first drawn
	 */
	glViewport(0,0,(GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glOrtho(0.0, COLUMNS, 0.0, ROWS, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void timer_callback(int)
{
	move_bullet();
	glutPostRedisplay(); /* Draw the Display function */
	glutTimerFunc(1000/FPS,timer_callback,0);
}

void keyboard_callback(int key, int, int)
{
	switch(key) {
		case GLUT_KEY_UP:
			if(sDirection != DOWN) {
				sDirection = UP;
			}
			break;
		case GLUT_KEY_DOWN:
			if(sDirection != UP) {
				sDirection = DOWN;
			}
			break;
		case GLUT_KEY_LEFT:
			if(sDirection != RIGHT) {
				sDirection = LEFT;
			}
			break;
		case GLUT_KEY_RIGHT:
			if(sDirection != LEFT) {
				sDirection = RIGHT;
			}
			break;
	}
}

void normal_key(unsigned char key, int, int)
{
	switch(key) {
		case SPACEBAR:
			struct bullet bt;
			bt.x = getPlayerX();
			bt.y = getPlayerY();
			bt.dir = getPlayerDirection() == REST ? UP : getPlayerDirection();
			if (bt.dir == UP) {
				bt.y++;
			} else if (bt.dir == DOWN) {
				bt.y--;
			} else if (bt.dir == LEFT) {
				bt.x--;
			} else if (bt.dir == RIGHT) {
				bt.x++;
			}
			bullets.push_back(bt);
			break;
	}
}
