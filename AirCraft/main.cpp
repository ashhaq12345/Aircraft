
#include <GL/glut.h>
#include <stdlib.h>
double xx=0,yy=0;
static void display(void)
{
   glEnable(GL_BLEND);
glBlendFunc(GL_ONE_MINUS_DST_COLOR,GL_ZERO);


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //glClearColor(0.0,0.00,1.0,1.0);
    glBegin(GL_TRIANGLES);
        glColor3f(1, 1, 1);
        glVertex3f(xx-0.1, yy+0.6, 0);
        glVertex3f(xx+0.1, yy+0.6, 0);
        glVertex3f(xx+0, yy+0.8, 0);
    glEnd();
        glColor3f(1, 1, 1);
        glRectf(xx-.1,yy+0.6,xx+0.1,yy-0.4);
    glBegin(GL_TRIANGLES);
        glColor3f(1, 1, 1);
        glVertex3f(xx-0.7,yy+ 0, 0);
        glVertex3f(xx-.1, yy+0, 0);
        glVertex3f(xx-.1, yy+0.4, 0);
    glEnd();
    glBegin(GL_TRIANGLES);
        glColor3f(1, 1, 1);
        glVertex3f(xx+0.1,yy+ 0, 0);
        glVertex3f(xx+.7, yy+0, 0);
        glVertex3f(xx+.1, yy+0.4, 0);
    glEnd();
        glColor3f(1, 1, 1);
        glRectf(xx-.2,yy-.4,xx+0.2,yy-0.55);

    glutSwapBuffers();
}
void handleKeypress(unsigned char key,int x,int y)
{
    switch(key){
        case 'g' : xx=xx-.1;
                   glutPostRedisplay();
                   break;
        case 'y' : yy=yy+.1;
                   glutPostRedisplay();
                   break;
        case 'h' : yy=yy-.1;
                   glutPostRedisplay();
                   break;
        case 'j' : xx=xx+.1;
                   glutPostRedisplay();
                   break;
    }
}
void update(int value){

    glutPostRedisplay();
    glutTimerFunc(1000,update,1000);
}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("GLUT Shapes");
    //update(250);

    glutDisplayFunc(display);
    glutKeyboardFunc(handleKeypress);
    glutMainLoop();

    return EXIT_SUCCESS;
}
