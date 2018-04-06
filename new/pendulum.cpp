#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;

float angle=135;
float inc=1.0;

void initialize()
{
  glClearColor(1.0,1.0,1.0,0.0);
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-250,250,-250,250);
}

void midPoint(int x,int y,int r)
{
  int x1=0,y1=r;
  float dp=1-r;
  while(x1<=y1)
  {
    if(dp<=0)
    {
      x1++;
      dp+=(2*x1)+1;
    }
    else
    {
      x1++;
      y1--;
      dp+=2*(x1-y1)+1;
    }
    glBegin(GL_POINTS);
    glVertex2f(x1+x,y1+y);
    glVertex2f(x1+x,y-y1);
    glVertex2f(x-x1,y1+y);
    glVertex2f(x-x1,y-y1);
    glVertex2f(x+y1,y+x1);
    glVertex2f(x+y1,y-x1);
    glVertex2f(x-y1,y+x1);
    glVertex2f(x-y1,y-x1);
    glEnd();
  }
  glFlush();
}
void delay(long long n)
{
  while(n>0)
  {
    n--;
  }
}

void display()
{
    
    glClear(GL_COLOR_BUFFER_BIT);
      glColor3f(0.0,0.0,1.0);

      char ch;
      glRasterPos2f(-70,220);
        char msg[]={"Pendulum Clock"};
      for(int i=0;msg[i]!='\0';++i)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,msg[i]);
        glRasterPos2f(-5,175);
       ch='1';
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,ch);
	  glRasterPos2f(3,175);
       ch='2';
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,ch);
	 glRasterPos2f(50,155);
       ch='1';
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,ch);
	 glRasterPos2f(70,130);
       ch='2';
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,ch);
	glRasterPos2f(75,90);
       ch='3';
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,ch);
	glRasterPos2f(70,55);
       ch='4';
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,ch);
	glRasterPos2f(40,30);
       ch='5';
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,ch);
	glRasterPos2f(-5,15);
       ch='6';
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,ch);
	glRasterPos2f(-45,30);
       ch='7';
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,ch);
	glRasterPos2f(-75,55);
       ch='8';
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,ch);
	  glRasterPos2f(-85,90);
       ch='9';
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,ch);
	glRasterPos2f(-80,130);
       ch='1';
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,ch);
	glRasterPos2f(-70,130);
       ch='0';
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,ch);
	glRasterPos2f(-50,155);
       ch='1';
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,ch);
       glRasterPos2f(-40,155);
       ch='1';
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,ch);


      glColor3f(1.0,0.0,0.0);
      midPoint(0,100,100);
      midPoint(0,100,60);
     if(angle>225)
      {
        angle=225;
        inc=-inc;
      }
      if(angle<135)
      {
        angle=135;
        inc=-inc;
      }
      angle+=inc;
      double radian=angle*3.14/180;
      float y2=150*cos((double) radian);
      float x2=150*sin((double) radian);
      midPoint(x2,y2,30);
      glColor3f(0.0,0.0,0.0);
      glLineWidth(2);
      glBegin(GL_LINES);
      {
          glVertex2f(0,0);
          glVertex2f(x2,y2);
	  glVertex2f(0,100);
          glVertex2f(0,150);
	  glVertex2f(0,100);
          glVertex2f(60,145);
     
      }
      glEnd();
      glFlush();
      delay(7000000);
      glutPostRedisplay();
}

void keyboard(unsigned char key,int x,int y)
{
  if(key==27)
    exit(0);
}

int main(int argc,char **argv)
{
  glutInit(&argc,argv);
  glutInitWindowSize(500, 500);
  glutCreateWindow("assign8");
  initialize();
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  return 0;
}
