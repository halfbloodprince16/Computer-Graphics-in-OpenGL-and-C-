#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;

float rtri = 0.0f;
float rquad = 0.0f;

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

float ballX = -0.4f;
float ballY = 0.0f;
float ballZ = 0.0f;

void drawBall(void) 
{
  glColor3f(0.1, 0.1, 0.1);
  glTranslatef(ballX,ballY,ballZ);
  glutSolidSphere(0.2, 20, 20);
  
   glColor3f(1.0, 1.0, 1.0);
  glTranslatef(ballX+0.4,ballY,ballZ);
  glutSolidSphere(0.1, 20, 20);
  
   glColor3f(0.1, 0.1, 0.1);
  glTranslatef(ballX+1.5,ballY,ballZ);
  glutSolidSphere(0.2, 20, 20);
  
  glColor3f(1.0, 1.0, 1.0);
  glTranslatef(ballX+0.4,ballY,ballZ);
  glutSolidSphere(0.1, 20, 20);
  
  
}

void DrawGLScene()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  
  glBegin(GL_LINES);
  glColor3f(0.0f,0.0f,0.0f);
  glVertex2f(-2.0,0.0);
  glVertex2f(2.0,0.0);
  glEnd();
  
  glTranslatef(rtri,0.0f,-6.0f);
  glBegin(GL_POLYGON);
  glColor3f(1.0f,0.3f,0.0f);
  /*glVertex3f(-1.0f, 1.0f, 0.0f);
  glVertex3f(0.4f, 1.0f, 0.0f);
  glVertex3f(1.0f, 0.4f, 0.0f);
  glVertex3f( 1.0f,0.0f, 0.0f);
  glVertex3f(-1.0f,0.0f, 0.0f);*/
  glVertex2f(-1.0,0.0);
  glVertex2f(-1.0,0.5);
  glVertex2f(-0.5,0.5);
  glVertex2f(-0.5,1.0);
  glVertex2f(0.5,1.0);
  glVertex2f(1.0,0.5);
  glVertex2f(1.5,0.5);
  glVertex2f(1.5,0.0);
   glEnd();
   
   glBegin(GL_POLYGON);
  glColor3f(0.0f,0.2f,0.5f);
  glVertex2f(0.9,0.5);
  glVertex2f(0.4,0.9);
  glVertex2f(0.0,0.9);
  glVertex2f(0.0,0.5);
  glEnd();
   glBegin(GL_POLYGON);
  glColor3f(0.0f,0.2f,0.5f);
  glVertex2f(-0.1,0.9);
  glVertex2f(-0.4,0.9);
  glVertex2f(-0.5,0.5);
  glVertex2f(-0.1,0.5);
  glEnd();
  
  /*
 glBegin(GL_LINES);
  glColor3f(0.0f,0.0f,0.0f);
  glVertex2f(-2.0,0.0);
  glVertex2f(2.0,0.0);
  glEnd();*/
  
   
  drawBall();
  rtri+=0.005f;
  if(rtri>2)
      rtri=-2.0f;
  rquad-=15.0f;
  
 // glLoadIdentity();
 glLineWidth(10.0);
  glBegin(GL_LINES);
  
  glColor3f(0.0f,0.0f,0.0f);
  glVertex2f(-110.0,-0.24);
  glVertex2f(110.0,-0.24);
  glEnd();
  
  glutSwapBuffers();
}

int main(int argc, char **argv) 
{  
  glutInit(&argc, argv);  
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);  
  glutInitWindowSize(640, 480);  
  glutInitWindowPosition(0, 0);  
  glutCreateWindow("vehicleLocomotion");  
  glutDisplayFunc(&DrawGLScene);  
  glutIdleFunc(&DrawGLScene);
  glutReshapeFunc(&ReSizeGLScene);
  InitGL(640, 480);
  glutMainLoop();  
  return 0;
}
