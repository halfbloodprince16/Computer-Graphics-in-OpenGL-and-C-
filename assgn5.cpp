//============================================================================
// Name        : Rohtash.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<GL/glut.h>
using namespace std;

const int w=500,h=500;
int flag=1,wi[4][2],wo[4][2],n=0,m=0;
int ymax, ymin, xmax, xmin;
void *font[]={GLUT_BITMAP_8_BY_13,GLUT_BITMAP_HELVETICA_18 };

typedef struct point{
	int xc,yc;
}point;
point e[20],out[20] ;

void set(int x, int y)
{
	glColor3f(1,0,0);
	glPointSize(4);
	glBegin(GL_POINTS);
	glVertex2f(x,y);
	glEnd();
	glFlush();
}
void abc()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,w,0,h);
}

void menu()
{
	glColor3f(1,1,1);
	glRasterPos2f(100,480);

	char m[]="Pls read carefully Instruction Before Starting:::";
	for(int i=0;i<50;i++)
	glutBitmapCharacter(font[1],m[i]);
	glEnd();
	glRasterPos2f(10,400);
	char m1[]="1...First click by left button in upper window twice";
		char m2[]="2...right click for window creating";
		for(int i=0;i<55;i++)
		glutBitmapCharacter(font[0],m1[i]);
		glEnd();
		glRasterPos2f(10,350);
		for(int i=0;i<36;i++)
				glutBitmapCharacter(font[0],m2[i]);
		glEnd();
		char m3[]="3.....Now draw polygon with left click...";
		glRasterPos2f(10,300);
		for(int i=0;i<45;i++)
			glutBitmapCharacter(font[0],m3[i]);
		glEnd();
		char m4[]="START";
				glRasterPos2f(253,255);
				for(int i=0;i<6;i++)
				glutBitmapCharacter(font[0],m4[i]);
				glEnd();
}
void desplay()
{
	glColor3f(1,1,0);
		glPointSize(4);
	glClearColor(0.25,.13,.16,0);
	glClear(GL_COLOR_BUFFER_BIT);
	menu();
	glColor3f(1,1,1);
		glBegin(GL_LINE_LOOP);
		glVertex2d(250,250);
		glVertex2d(250,270);
		glVertex2d(300,270);
		glVertex2d(300,250);
		glEnd();
		glFlush();




}

void clip()
{
	float s;
	int c=0;
	for(int i=0;i<m;i++)
	{
		if(e[i].xc<xmin&&e[i+1].xc>xmin)
		{
			s=(float)(e[i+1].yc-e[i].yc)/(e[i+1].xc-e[i].xc);
			out[c].yc=e[i].yc+(int)(s*(xmin-e[i].xc));
			out[c].xc=xmin;
			c++;
			out[c].xc=e[i+1].xc;
			out[c].yc=e[i+1].yc;
			c++;
		}
		else if(e[i].xc>xmin&&e[i+1].xc>xmin)
		{
			out[c].xc=e[i+1].xc;
			out[c].yc=e[i+1].yc;
			c++;

		}
		else if(e[i].xc>xmin&&e[i+1].xc<xmin)
		{
			s=(float)(e[i+1].yc-e[i].yc)/(e[i+1].xc-e[i].xc);
			out[c].yc=e[i].yc+(int)(s*(xmin-e[i].xc));
			out[c].xc=xmin;
			c++;
		}
	}

	out[c]=out[0];
	m=c;
	c=0;

	for(int i=0;i<m;i++)
		{
			if(out[i].yc<ymin&&out[i+1].yc>ymin)
			{
				s=(float)(out[i+1].yc-out[i].yc)/(out[i+1].xc-out[i].xc);
				e[c].xc=out[i].xc+(int)((ymin-out[i].yc)/s);
				e[c].yc=ymin;
				c++;
				e[c].xc=out[i+1].xc;
				e[c].yc=out[i+1].yc;
				c++;
			}
			else if(out[i].yc>ymin&&out[i+1].yc>ymin)
			{
				e[c].xc=out[i+1].xc;
				e[c].yc=out[i+1].yc;
				c++;

			}
			else if(out[i].yc>ymin&&out[i+1].yc<ymin)
			{
				s=(float)(out[i+1].yc-out[i].yc)/(out[i+1].xc-out[i].xc);
				e[c].xc=out[i].xc+(int)((ymin-out[i].yc)/s);
				e[c].yc=ymin;
				c++;
			}
		}

	e[c]=e[0];
	m=c;
	c=0;

	for(int i=0;i<m;i++)
		{
			if(e[i].xc>xmax&&e[i+1].xc<xmax)
			{
				s=(float)(e[i+1].yc-e[i].yc)/(e[i+1].xc-e[i].xc);
				out[c].yc=e[i].yc+(int)(s*(xmax-e[i].xc));
				out[c].xc=xmax;
				c++;
				out[c].xc=e[i+1].xc;
				out[c].yc=e[i+1].yc;
				c++;
			}
			else if(e[i].xc<xmax&&e[i+1].xc<xmax)
			{
				out[c].xc=e[i+1].xc;
				out[c].yc=e[i+1].yc;
				c++;

			}
			else if(e[i].xc<xmax&&e[i+1].xc>xmax)
			{
				s=(float)(e[i+1].yc-e[i].yc)/(e[i+1].xc-e[i].xc);
				out[c].yc=e[i].yc+(int)(s*(xmax-e[i].xc));
				out[c].xc=xmax;
				c++;
			}
		}

	out[c]=out[0];
	m=c;
	c=0;
	for(int i=0;i<m;i++)
			{
				if(out[i].yc>ymax&&out[i+1].yc<ymax)
				{
					s=(float)(out[i+1].yc-out[i].yc)/(out[i+1].xc-out[i].xc);
					e[c].xc=out[i].xc+(int)((ymax-out[i].yc)/s);
					e[c].yc=ymax;
					c++;
					e[c].xc=out[i+1].xc;
					e[c].yc=out[i+1].yc;
					c++;
				}
				else if(out[i].yc<ymax&&out[i+1].yc<ymax)
				{
					e[c].xc=out[i+1].xc;
					e[c].yc=out[i+1].yc;
					c++;

				}
				else if(out[i].yc<ymax&&out[i+1].yc>ymax)
				{
					s=(float)(out[i+1].yc-out[i].yc)/(out[i+1].xc-out[i].xc);
					e[c].xc=out[i].xc+(int)((ymax-out[i].yc)/s);
					e[c].yc=ymax;
					c++;
				}
			}

		e[c]=e[0];

		glColor3f(0,1,0);

	glBegin(GL_LINE_LOOP);
		for(int i=0; i<c;i++)
			glVertex2f(e[i].xc,e[i].yc-250);
			glEnd();
			glFlush();



}
void draw()
{
	wi[1][0]=wi[2][0];
	wi[1][1]=wi[0][1];
	wi[3][0]=wi[0][0];
	wi[3][1]=wi[2][1];


	if(wi[0][1]>wi[3][1])
	{
		ymax=wi[0][1];
		ymin=wi[3][1];
	}
	else
	{
		ymax=wi[3][1];
		ymin=wi[0][1];

	}
	if(wi[0][0]>wi[1][0])
	{
		xmax=wi[0][0];
		xmin=wi[1][0];
	}
	else
	{
		xmax=wi[1][0];
		xmin=wi[0][0];

	}
	glRasterPos2f(180,480);
	glColor3f(0.25,0.36,0.58);
	char m[]="Befor Clipping Window";
	for(int i=0;i<26;i++)
		glutBitmapCharacter(font[0],m[i]);


	glBegin(GL_LINE_LOOP);
	for(int i=0; i<4;i++)
		glVertex2f(wi[i][0],wi[i][1]);
		glEnd();
		glFlush();


}

void drawoutput()
{
	wo[0][0]=wi[0][0];
	wo[1][0]=wi[1][0];
	wo[2][0]=wi[2][0];
	wo[3][0]=wi[3][0];
	wo[0][1]=wi[0][1]-250;
		wo[1][1]=wi[1][1]-250;
		wo[2][1]=wi[2][1]-250;
		wo[3][1]=wi[3][1]-250;

		glRasterPos2f(180,480-250);

			char m[]="After Clipping Window";
			for(int i=0;i<25;i++)
				glutBitmapCharacter(font[0],m[i]);

		glPointSize(4);
		glColor3f(0,0,1);
		glBegin(GL_LINE_LOOP);
			for(int i=0; i<4;i++)
				glVertex2f(wo[i][0],wo[i][1]);
				glEnd();
				glFlush();
}

void mine(int b,int s, int x, int y)
{
	if(s==GLUT_DOWN)
	{
		if(b==GLUT_LEFT_BUTTON)
		{
			if(flag==1)
			{
				wi[n][0]=x;
				wi[n][1]=500-y;
				n+=2;
				set(x,500-y);
			}
			else
			{
				e[m].xc=x;
				e[m].yc=500-y;
				set(x, 500-y);
				glColor3f(1,1,1);
				if(m>0)
				{
					glBegin(GL_LINES);
						glVertex2f(e[m-1].xc,e[m-1].yc);
						glVertex2f(e[m].xc, e[m].yc);
						glEnd();
						glFlush();
				}
				m++;
			}
		}
		else if(b==GLUT_RIGHT_BUTTON)
		{
			if(flag==1)
			{
				draw();
				flag=0;
			}
			else
			{
				glColor3f(1,1,1);
				e[m].xc=e[0].xc;
				e[m].yc=e[0].yc;
				glBegin(GL_LINES);
				glVertex2f(e[m-1].xc, e[m-1].yc);
				glVertex2f(e[m].xc,e[m].yc);
				glEnd();
				glFlush();
				drawoutput();
				clip();

			}
		}
	}
}

void mine1(int b, int s, int x, int y)
{
	if(s==GLUT_DOWN)
		{
			if(b==GLUT_LEFT_BUTTON &&(250<x &&x<300))
			{
				glClearColor(0.25,.13,.16,0);
				glClear(GL_COLOR_BUFFER_BIT);
				for(int i=0;i<500;i++)
					{
						set(i,250);
					}
				glutMouseFunc(mine);
			}
		}

}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(w,h);
	glutCreateWindow("rohit chahar: poly clip");\
	abc();
	glutDisplayFunc(desplay);
	glutMouseFunc(mine1);
	glutMainLoop();
	return 0;



}
