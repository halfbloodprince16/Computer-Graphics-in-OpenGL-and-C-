#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;

float rtri =-1.0f;

void InitGL(int Width,int Height)         
{
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);     
  glClearDepth(1.0);              
  glDepthFunc(GL_LESS);               
  glEnable(GL_DEPTH_TEST);          
  glShadeModel(GL_SMOOTH);           
  glLoadIdentity();             
  gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.1f,100.0f);  
  glMatrixMode(GL_MODELVIEW);
}

void ReSizeGLScene(int Width, int Height)
{
  if (Height==0)             
    Height=1;
  glViewport(0, 0, Width, Height);   
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.1f,100.0f);
  glMatrixMode(GL_MODELVIEW);
}


void drawRect()
{
	glBegin(GL_POLYGON);
		glColor3f(1.0f,0.0f,0.0f);
		glVertex2f(-1.1f, 1.0f);
		glVertex2f(-1.0f, 1.0f);
		glVertex2f(-1.1f,-10.0f);

		glVertex2f(-1.0f, 1.0f);
		glVertex2f(-1.0f, -10.0f);
		glVertex2f(-1.1f,-10.0f);
	glEnd();
	glFlush();
}

void DrawGLScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0.0f,rtri,-6.0f);
	glBegin(GL_POLYGON);
		glColor3f(1.0f,0.3f,0.0f);
		glVertex2f(-1.0f, 1.0f);
		glVertex2f(0.4f, 1.0f);
		glVertex2f(-1.0f,0.0f);

		glVertex2f(0.4f, 1.0f);
		glVertex2f(0.4f, 0.0f);
		glVertex2f(-1.0f,0.0f);
	glEnd();
	rtri+=0.005f;
	if(rtri>1)
		rtri-=0.005f;
	drawRect();
	glutSwapBuffers();
}

int main(int argc, char **argv) 
{  
  glutInit(&argc, argv);  
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);  
  glutInitWindowSize(640, 480);  
  glutInitWindowPosition(0, 0);  
  glutCreateWindow("flagHoistingBETAver1.0");  
  glutDisplayFunc(&DrawGLScene);  
  glutIdleFunc(&DrawGLScene);
  glutReshapeFunc(&ReSizeGLScene);
  InitGL(640, 480);
  glutMainLoop();  
  return 0;
}