#include <iostream>
#include <GL/glut.h>
#include "global.h"

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize (300, 300);
    glutInitWindowPosition (200, 200);
    glutCreateWindow (argv[0]);
    init();

    // printf("FullScreen?(y/n) ");
    
    // if (getchar() == 'y')
    //     glutFullScreen();

    glutIdleFunc(idle);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;
}