#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;

int ww=500,wh=500;
float x11,y11,x22,y22;
float boundaryCol[3]={0.0,0.0,0.0};
float fillCol[3]={1.0,0.0,0.0};
int size=8,x_arr[8]={204,275,134,207,277,345,204,276},y_arr[8]={348,348,282,277,277,277,207,207};

void setPixel(int x,int y,float fcol[3])
{
	glPointSize(2);
	glBegin(GL_POINTS);
		glColor3fv(fcol);
		glVertex2i(x,y);
	glEnd();
	glFlush();
}

void getPixel(int x,int y,float *color)
{
    glReadPixels(x,y,1,1,GL_RGB,GL_FLOAT,color);
}

void dda(double x1,double y1,double x2,double y2)
{
	double dx=(x2-x1);
	double dy=(y2-y1);
	double len;
	float xInc,yInc,x=x1,y=y1;
	len=(abs(dx)>abs(dy))?(abs(dx)):(abs(dy));
	xInc=dx/(float)len;
	yInc=dy/(float)len;
	setPixel(round(x),round(y),boundaryCol);
	int k;
	for(k=0;k<len;k++)
	{
		x+=xInc;
		y+=yInc;
		setPixel(round(x),round(y),boundaryCol);
	}
}

void rotate(int a,int b,int c,int d)
{
	x11=a*cos(0.785398)-b*sin(0.785398);
	y11=a*sin(0.785398)+b*cos(0.785398);
	x22=c*cos(0.785398)-d*sin(0.785398);
	y22=c*sin(0.785398)+d*cos(0.785398);
}

void translate(int a,int b,int c,int d)
{
	x11=a+100;
	y11=b-75;
	x22=c+100;
	y22=d-75;
}

void display()
{
	glClearColor(1.0,1.0,1.0,0);
	glLoadIdentity();
	gluOrtho2D(0.0,ww,0.0,wh);
	glClear(GL_COLOR_BUFFER_BIT);

	rotate(250,50,450,50);
	translate(x11,y11,x22,y22);
	dda(x11,y11,x22,y22);
	rotate(450,50,450,250);
	translate(x11,y11,x22,y22);
	dda(x11,y11,x22,y22);
	rotate(450,250,250,250);
	translate(x11,y11,x22,y22);
	dda(x11,y11,x22,y22);
	rotate(250,250,250,50);
	translate(x11,y11,x22,y22);
	dda(x11,y11,x22,y22);

	rotate(300,50,300,250);
	translate(x11,y11,x22,y22);
	dda(x11,y11,x22,y22);
	rotate(350,50,350,250);
	translate(x11,y11,x22,y22);
	dda(x11,y11,x22,y22);
	rotate(400,50,400,250);
	translate(x11,y11,x22,y22);
	dda(x11,y11,x22,y22);

	rotate(250,100,450,100);
	translate(x11,y11,x22,y22);
	dda(x11,y11,x22,y22);
	rotate(250,150,450,150);
	translate(x11,y11,x22,y22);
	dda(x11,y11,x22,y22);
	rotate(250,200,450,200);
	translate(x11,y11,x22,y22);
	dda(x11,y11,x22,y22);
}

void floodfill(int x,int y,float oldcolor[3],float newcolor[3])
{
	float color[3];
	getPixel(x,y,color);
	//cout<<x<<" "<<y<<endl;
	//cout<<color[0]<<" "<<color[1]<<" "<<color[2]<<endl;
	if(color[0] && color[1] && color[2])
	{
		setPixel(x,y,newcolor);
		floodfill(x+1,y,oldcolor,newcolor); //4 point
		floodfill(x-2,y,oldcolor,newcolor); //w
		floodfill(x,y+1,oldcolor,newcolor);
		floodfill(x,y-2,oldcolor,newcolor);
		/*floodfill(x+2,y+2,oldcolor,newcolor); //8 point
		floodfill(x-2,y+2,oldcolor,newcolor);
		floodfill(x+2,y-2,oldcolor,newcolor);
		floodfill(x-2,y-2,oldcolor,newcolor);*/
		//setPixel(x,y,newcolor);
	}
}

void mouse(int btn,int state,int x,int y)
{
	if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		int xi=x;
		int yi=(wh-y);
		//cout<<xi<<" "<<yi<<endl;
		for(int i=0;i<size;i++)
			floodfill(x_arr[i],y_arr[i],boundaryCol,fillCol);
	}
}

int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(ww,wh);
	glutCreateWindow("assign4");
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}
