/*
 * Copyright: Rudra Nil Basu <rudra.nil.basu.1996@gmail.com>
 */

#include<GL/gl.h>
#include<GL/glut.h>
#include "game.h"

#include<stdio.h>

#define ROWS 40
#define COLUMNS 40
#define FPS 10

void timer_callback(int);
void display_callback();
void reshape_callback(int w, int h);
void init();
void keyboard_callback(int, int, int);

extern short sDirection;

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(600,600);
	glutCreateWindow("SNAKE - Rudra Nil Basu");
	glutDisplayFunc(display_callback);
	glutReshapeFunc(reshape_callback);
	glutTimerFunc(0,timer_callback,0);
	glutSpecialFunc(keyboard_callback);
	init();
	glutMainLoop();
	return 0;
}

void init()
{
	glClearColor(0.0,0.0,0.0,0.0);
	initGrid(ROWS, COLUMNS);
}

void display_callback()
{
	glClear(GL_COLOR_BUFFER_BIT);
	drawGrid();
	drawSnake();
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
