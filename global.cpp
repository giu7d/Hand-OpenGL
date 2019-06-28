#include <iostream>
#include <GL/glut.h>
#include "hand.h"
#include "global.h"

float ang = 0;
float ang2 = 0;
float ang3 = 0;
bool swingSideWays = false;

Hand m(1.0);  

void init(void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glClearDepth(1.0);				// Enables Clearing Of The Depth Buffer
    glDepthFunc(GL_LEQUAL);				// The Type Of Depth Test To Do
    glEnable(GL_DEPTH_TEST);			// Enables Depth Testing
    glShadeModel(GL_SMOOTH);			// Enables Smooth Color Shading
}

void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   //////////////ISSO AQUI EH PRA LUZ///////////E EU AINDA N SEI COMO FUNCA/////
    GLfloat			diffuseLight[] = { 1.0f, 1.0f, 1.0f, 1.0};
    GLfloat			ambientLight[] = { 0.2f, 0.2f, 0.4f, 1.0};
    GLfloat			lightPos[] = { 0.0f, 500.0f, 100.0f, 1.0f };
    glEnable(GL_LIGHTING);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT0, GL_SPECULAR, diffuseLight);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glColor3f(1.0f,1.0f,1.0f);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, diffuseLight );
    glMateriali(GL_FRONT_AND_BACK, GL_SHININESS, 50);
    //////////////////////////////////////////////////////////////////////////

    glPushMatrix();

      glTranslatef (0.0, -5.0, -15.0);
      glRotatef (ang3, 0.0, 0.0, 1.0);
      glRotatef (ang, 0.0, 1.0, 0.0);
      glRotatef (ang2, 1.0, 0.0, 0.0);
      glColor3f(1.0,0.8,0);

      m.draw();

    glPopMatrix();

    glutSwapBuffers();
}

void reshape(int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluPerspective(55.0, (GLfloat) w/(GLfloat) h, 1.0, 40.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glTranslatef (0.0, 0.0, -10.0);
}

void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 'q':
            if (m.getCurve(0) < 100)
                m.setCurve(0,m.getCurve(0)+5);
            break;
        case 'a':
            if (m.getCurve(0) > 0)
                m.setCurve(0,m.getCurve(0)-5);
            break;
        case 'w':
            if (m.getCurve(1) < 100)
                m.setCurve(1,m.getCurve(1)+5);
            break;
        case 's':
            if (m.getCurve(1) > 0)
                m.setCurve(1,m.getCurve(1)-5);
            break;
         case 'e':
            if (m.getCurve(2) < 100)
                m.setCurve(2,m.getCurve(2)+5);
            break;
        case 'd':
            if (m.getCurve(2) > 0)
                m.setCurve(2,m.getCurve(2)-5);
            break;
        case 'r':
            if (m.getCurve(3) < 100)
                m.setCurve(3,m.getCurve(3)+5);
            break;
        case 'f':
            if (m.getCurve(3) > 0)
                m.setCurve(3,m.getCurve(3)-5);
            break;
        case 't':
            if (m.getCurve(4) < 100)
                m.setCurve(4,m.getCurve(4)+5);
            break;
        case 'g':
            if (m.getCurve(4) > 0)
                m.setCurve(4,m.getCurve(4)-5);
            break;
        case '.': //>
            ang += 5;
            if (ang>360)
                ang -= 360;
            break;
        case ',': //<
            ang -= 5;
            if (ang<0)
                ang += 360;
            break;
        case ']':
            ang2 += 5;
            if (ang2>360)
                ang2 -= 360;
            break;
        case '[':
            ang2 -= 5;
            if (ang2<0)
                ang2 += 360;
            break;
        case '+':
            m.open();
            break;
        case '*' :
            m.open(true);
            break;
        case '/' :
            m.close(true);
            break;
        case '-':
            m.close();
            break;
        case 27: //ESC
            exit(0);
            break;
        case '9':
            ang3 += 5;
            if (ang3>360)
                ang3 -= 360;
            break;
        case '0':
            ang3 -= 5;
            if (ang3<0)
                ang3 += 360;
            break;
        case '1' :
            m.bye();
            break;
        case '2' :
            m.fuck();
            break;
        case '3' :
            m.hangloose();
            break;
        case '4' :
            m.vemProPau();
            break;
        case '5' :
            m.dedoDuro();
            break;
        case '6' :
            m.positivo();
            break;
        case '7' :
            m.chavesPattern();
            break;
        case '8' :
            m.nao();
            break;
        case 9 :
            m.home();
            break;

        default:
            return;
    }
    glutPostRedisplay();
}

void idle()
{
}
