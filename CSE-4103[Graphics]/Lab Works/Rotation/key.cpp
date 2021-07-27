#include<GL/gl.h>
#include<GL/glut.h>
#include<stdio.h>

void
init(void)
{
    /*initialize the x-y co-ordinate*/
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-320, 319,-240, 239);
    glClear (GL_COLOR_BUFFER_BIT);
    glFlush();
}

void
catchKey(int key, int x, int y)
{
    if(key == GLUT_KEY_LEFT)    
        printf("Left key is pressed\n");
    else if(key == GLUT_KEY_RIGHT)
        printf("Right key is pressed\n");
    else if(key == GLUT_KEY_DOWN)
        printf("Down key is pressed\n");
    else if(key == GLUT_KEY_UP)
        printf("Up key is pressed\n");
}

int
main(int argc, char *argv[])
{
    double x_0, y_0, x_1, y_1;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(400, 400);

    glutCreateWindow("Special key");
    init();
    glutSpecialFunc(catchKey);
    glutMainLoop();
}
