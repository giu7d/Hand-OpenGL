#ifndef Global_H
#define Global_H

#include <iostream>
#include <GL/glut.h>
#include "hand.h"

extern float ang;
extern float ang2;
extern float ang3;
extern bool swingSideWays;
extern Hand m;
extern void init(void);
extern void display(void);
extern void reshape(int w, int h);
extern void keyboard(unsigned char key, int x, int y);
extern void idle();


#endif
