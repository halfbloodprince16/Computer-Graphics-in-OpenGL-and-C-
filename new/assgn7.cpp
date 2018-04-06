#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;

GLfloat angle= 0.0;

void spin (void)
{
	angle+= 1.0;
	glutPostRedisplay();
}

void display(void)
{
	glClearColor(0.3,0.7,0.3,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0.0,0.0,5.0,0.0,0.0,0.0,0.0,1.0,0.0);
	glRotatef(angle, 0, 1, 0);
	glutWireCube(2.0);//glutSolidCube(double size);
	glutSwapBuffers();
}

void keyboard(unsigned char key,int x,int y)
{
	if(key==27)
		exit(0);
}

void reshape(int width,int height)
{
	glViewport(0,0,(GLsizei) width,(GLsizei) height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60,(GLfloat) width/(GLfloat) height,1.0,100.0);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(200,100);
	glutCreateWindow("assign7");
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutReshapeFunc(reshape);
	glutIdleFunc(spin);
	glutMainLoop();
	return 0;
}
