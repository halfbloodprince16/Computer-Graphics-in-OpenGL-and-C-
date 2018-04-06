#include<iostream>
#include<cmath>
#include<GL/glut.h>
using namespace std;

int xx1,xx2,xx3,yy1,yy2,yy3;

void myInit(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0,0.0,0.0,1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,500,0,500);
}

void draw_pixel(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void draw_line(int x1, int x2, int y1, int y2)
{
	int dx, dy, i=0, p;
	int incx=1, incy=1, inc1, inc2;
	int x,y;
	dx = abs(x2-x1);
	dy = abs(y2-y1);
	if (x2 < x1)
		incx = -1;
	if (y2 < y1)
		incy = -1;
	x = x1;
	y = y1;
	if (dx > dy)
	{
		draw_pixel(x, y);
		p = (2*dy)-dx;
		inc1 = 2*(dy-dx);
		inc2 = 2*dy;
		while(i<dx)
		{
			if (p >= 0)
			{
				y += incy;
				p += inc1;
			}
			else
				p += inc2;
			x += incx;
			draw_pixel(x, y);
			i++;
		}
	}
	else
        {
		draw_pixel(x, y);
		p = (2*dx)-dy;
		inc1 = 2*(dx-dy);
		inc2 = 2*dx;
		while(i<dy)
		{
			if (p >= 0)
			{
				x += incx;
				p += inc1;
			}
			else
				p += inc2;
			y += incy;
			draw_pixel(x, y);
			i++;
		}
	}
}


void draw_circle(int cx,int cy,int r)
{
	int x=0,y=r,p=3-(2*r);
	int inc1, inc2;
	glBegin(GL_POINTS);
	for(int i=x;i<y;i++)
	{
		inc1=4*x+6;
		inc2=4*(x-y)+10;
		if(p<0)
		{
			p+=inc1;
			x+=1;
		}
		else
		{
			y-=1;
			x++;
			p+=inc2;
		}
		glVertex2i(cx+x,cy+y);
		glVertex2i(cx+y,cy+x);
		glVertex2i(cx+y,cy-x);
		glVertex2i(cx+x,cy-y);
		glVertex2i(cx-x,cy-y);
		glVertex2i(cx-y,cy-x);
		glVertex2i(cx-y,cy+x);
		glVertex2i(cx-x,cy+y);

	}
	glEnd();
}

void myDisplay()
{
	draw_line(xx1,xx2,yy1,yy2);
	draw_line(xx2,xx3,yy2,yy3);
	draw_line(xx3,xx1,yy3,yy1);

	int cy=(yy1+yy2+yy3)/3;
	int cx=(xx2+xx3+xx1)/3;
	int dx=(xx2+xx3)/2;
	int dy=(yy2+yy3)/2;
	int r=sqrt((cx-dx)*(cx-dx) + (cy-dy)*(cy-dy) );
	draw_circle(cx,cy,r);

	r=sqrt((cx-xx2)*(cx-xx2) + (cy-yy2)*(cy-yy2));
	draw_circle(cx,cy,r);
	glFlush();
}

int main(int argc, char** argv)
{
    in:
	cout<<"<<<...Enter Coordinates of a Equilateral triangle...>>>"<<endl;
	cout<<"Enter 1st Vertex Points :";
	cin>>xx1>>yy1;
	cout<<"Enter 2nd Vertex Points : ";
	cin>>xx2>>yy2;
	cout<<"Enter 3rd Vertex Points : ";
	cin>>xx3>>yy3;
	int d1=sqrt((xx1-xx2)*(xx1-xx2) + (yy1-yy2)*(yy1-yy2));
	int d2=sqrt((xx2-xx3)*(xx2-xx3) + (yy2-yy3)*(yy2-yy3));
	int d3=sqrt((xx3-xx1)*(xx3-xx1) + (yy3-yy1)*(yy3-yy1));
	if(abs(d1-d2)<=2 && abs(d2-d3)<=2 && abs(d3-d1)<=2)
    {
        glutInit(&argc,argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(500,500);
        glutInitWindowPosition(0,0);
        glutCreateWindow("Ujjal Bresenham's Circle Drawing");
        myInit();
        glutDisplayFunc(myDisplay);
        glutMainLoop();
    }
    else{
        cout<<"!!!...Enter Coordinates of a Equilateral triangle...!!!"<<endl;
        goto in;
    }
	return 0;
}
