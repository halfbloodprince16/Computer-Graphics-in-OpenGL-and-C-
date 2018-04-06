#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;
int r=0,g=0,b=0;
vector<int> x_coordinates,y_coordinates;
int f=0;

void init2D()
{
	glClearColor(0.3,0.7,0.3,1.0);
	glPointSize(3);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,640,0,480);
}

void palette(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,0.0);	//yellow
	glRecti(10,10,30,30);
	glColor3f(1.0,0.0,0.0); //red
	glRecti(30,10,50,30);	
	glColor3f(0.0,1.0,1.0);	//cyan	
	glRecti(10,30,30,50);
	glColor3f(0.0,0.0,1.0);	//blue
	glRecti(30,30,50,50);
	glColor3f(1.0,1.0,1.0);	//white			
	glRecti(10,50,30,70);
	glColor3f(0.0,1.0,0.0);	//green
	glRecti(30,50,50,70);
	glColor3f(1.0,0.0,1.0);	//magenta
	glRecti(10,70,50,90);
	glColor3f(0.0,0.0,0.0);	//black
	glRecti(30,70,50,90);
	
	glFlush();
}

void drawPixel(int x,int y)
{ 
      glColor3f(r,g,b);
	glBegin(GL_POINTS);
		glVertex2i(x,480-y);
	glEnd();
	glFlush();
}

/*void getPixel(int x,int y,GLubyte *color)
{
	glReadPixels(x,y,1,1,GL_RGB,GL_UNSIGNED_BYTE,color);
}*/

void dda(double x1,double y1,double x2,double y2)
{
	double dx=(x2-x1);
	double dy=(y2-y1);
	double len;
	float xInc,yInc,x=x1,y=y1;
	len=(abs(dx)>abs(dy))?(abs(dx)):(abs(dy));
	xInc=dx/(float)len;
	yInc=dy/(float)len;
	drawPixel(round(x),round(y));
	int k;
	for(k=0;k<len;k++)
	{
		x+=xInc;
		y+=yInc;
		drawPixel(round(x),round(y));
	}
}
void rotate(int x)
{cout<<x;
}
void translate(int x)
{
cout<<-x;
}
void menu()
{
	int id[20];
	id[2]=glutCreateMenu(rotate);
	glutAddMenuEntry("30",30);
	glutAddMenuEntry("45",45);
	glutAddMenuEntry("56",56);
	id[1]=glutCreateMenu(translate);
	glutAddMenuEntry("30",30);
	glutAddMenuEntry("45",45);
	glutAddMenuEntry("56",56);
	id[0]=glutCreateMenu(NULL);
	glutAddSubMenu("translate",id[1]);
	glutAddSubMenu("scale",id[2]);
	glutAttachMenu(GLUT_MIDDLE_BUTTON);


}
void color(int x,int y)
{
     if(x>=10&& x<=30)
     {
          if(y>=10&& y<=30)
          {
             r=1; g=1;b=0;
          }
          if(y>=30&&y<=50)
           {
                   r=0;g=1;b=1;
           }
           if(y>=50&&y<=70)
           {
                   r=1;g=1;b=1;
           }
           if(y>=70&&y<=90)
           {
                   r=01;g=0;b=1;
           }
     }
     if(x>30&&x<=50)
     {
          
          if(y>=10&& y<=30)
          {
             r=1; g=0;b=0;
          }
          if(y>=30&&y<=50)
           {
                   r=0;g=0;b=1;
           }
           if(y>=50&&y<=70)
           {
                   r=0;g=1;b=0;
           }
           if(y>=70&&y<=90)
           {
                   r=0;g=0;b=0;
           }
     }
}
void mouse(int button,int state,int x,int y)
{
        color(x,480-y);
  
	if(state==GLUT_DOWN)
	{
		if(button==GLUT_LEFT_BUTTON)
		{
			if(f==1)
			{
				x_coordinates.clear();
				y_coordinates.clear();
				f=0;
			}
			drawPixel(x,y);
			x_coordinates.push_back(x);
			y_coordinates.push_back(y);
		}
		else if(button==GLUT_RIGHT_BUTTON)
		{
			GLubyte rgb[3];
			//getPixel(x,480-y,rgb);
			if(rgb[0]==0.0 && rgb[1]==0.0 && rgb[2]==0.0)
			{
				for(int i=0;i<x_coordinates.size();i++)
				{
					if(i==x_coordinates.size()-1)
						dda(x_coordinates[i],y_coordinates[i],x_coordinates[0],y_coordinates[0]);
					else
						dda(x_coordinates[i],y_coordinates[i],x_coordinates[i+1],y_coordinates[i+1]);
				}
				f=1;
			}
			//else
				//glColor3f(rgb[0],rgb[1],rgb[2]);	
		}
		
	}
}

void keyboard(unsigned char key,int x,int y)
{
	if(key==27)
		exit(0);
}

int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(0,0);
	glutCreateWindow("assign1");
	init2D();
	menu();
	glutDisplayFunc(palette);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}
