#include<iostream>
//#include<bits/stdc++.h>
#include<GL/glut.h>
using namespace std;

int x1,x2,x3,x4,y1,y2,y3,y4,ch;

void myInit()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 500, 0, 500);
}

void draw_pixel(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void dda(int x1,int y1,int x2,int y2)
{
  int dx=(x2-x1);
  int dy=(y2-y1);
  int len;
  float xInc,yInc,x=x1,y=y1;
  len=(abs(dx)>abs(dy))?(abs(dx)):(abs(dy));
  xInc=dx/(float)len;
  yInc=dy/(float)len;
  draw_pixel((x),(y));
  int k;
 for(k=0;k<len;k++)
  {
    x+=xInc;
    y+=yInc;
    draw_pixel((x),(y));
  }
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

void myDisplay()
{
    if(ch==1)
    {
        draw_line(x1, x2, y1, y2);
        draw_line(x2,x3,y2,y3);
        draw_line(x3,x4,y3,y4);
        draw_line(x4,x1,y4,y1);

        int midx1=(x1+x2)/2,midx2=(x2+x3)/2,midx3=(x3+x4)/2,midx4=(x4+x1)/2;
        int midy1=(y1+y2)/2,midy2=(y2+y3)/2,midy3=(y3+y4)/2,midy4=(y4+y1)/2;
        draw_line(midx1, midx2, midy1, midy2);
        draw_line(midx2,midx3,midy2,midy3);
        draw_line(midx3,midx4,midy3,midy4);
        draw_line(midx4,midx1,midy4,midy1);

        int mid2x1=(midx1+midx2)/2,mid2x2=(midx2+midx3)/2,mid2x3=(midx3+midx4)/2,mid2x4=(midx4+midx1)/2;
        int mid2y1=(midy1+midy2)/2,mid2y2=(midy2+midy3)/2,mid2y3=(midy3+midy4)/2,mid2y4=(midy4+midy1)/2;
        draw_line(mid2x1, mid2x2, mid2y1, mid2y2);
        draw_line(mid2x2,mid2x3,mid2y2,mid2y3);
        draw_line(mid2x3,mid2x4,mid2y3,mid2y4);
        draw_line(mid2x4,mid2x1,mid2y4,mid2y1);
	}
	else
    {
        dda(x1, x2, y1, y2);
        dda(x2,x3,y2,y3);
        dda(x3,x4,y3,y4);
        dda(x4,x1,y4,y1);

        int midx1=(x1+x2)/2,midx2=(x2+x3)/2,midx3=(x3+x4)/2,midx4=(x4+x1)/2;
        int midy1=(y1+y2)/2,midy2=(y2+y3)/2,midy3=(y3+y4)/2,midy4=(y4+y1)/2;
        dda(midx1, midx2, midy1, midy2);
        dda(midx2,midx3,midy2,midy3);
        dda(midx3,midx4,midy3,midy4);
        dda(midx4,midx1,midy4,midy1);

        int mid2x1=(midx1+midx2)/2,mid2x2=(midx2+midx3)/2,mid2x3=(midx3+midx4)/2,mid2x4=(midx4+midx1)/2;
        int mid2y1=(midy1+midy2)/2,mid2y2=(midy2+midy3)/2,mid2y3=(midy3+midy4)/2,mid2y4=(midy4+midy1)/2;
        dda(mid2x1, mid2x2, mid2y1, mid2y2);
        dda(mid2x2,mid2x3,mid2y2,mid2y3);
        dda(mid2x3,mid2x4,mid2y3,mid2y4);
        dda(mid2x4,mid2x1,mid2y4,mid2y1);
    }
    glFlush();
}

int main(int argc, char **argv)
{
	cout<<"<<<...Enter Coordinates...>>>"<<endl;
	cout<<"Enter 1st Points :";
	cin>>x1>>y1;
	cout<<"Enter 2nd Points : ";
	cin>>x3>>y3;
	x2=x3;
	y2=y1;
	x4=x1;
	y4=y3;
	in:
	cout<<"\n<<<...ALGORITHMS...>>>\n1.Bresenham's Line Drawing Algorithm\n2. DDA's Line Drawing Algorithm\n\nEnter your choice : ";
	cin>>ch;
	if(ch>2)
    {
        cout<<"\n!!!...Enter a valid choice...!!!"<<endl;
        goto in;
    }
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 0);
	glutCreateWindow("Ujjal Bresenham's Line Drawing");
	myInit();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
	return 0;
}

