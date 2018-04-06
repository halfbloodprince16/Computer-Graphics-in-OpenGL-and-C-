#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;

#define w 500
#define h 500

void init()
{
	glClearColor(0.0,0.0,0.0,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-w/2,w/2,-h/2,h/2);
}

void setpixel(GLint x, GLint y)
{      
	glColor3f(1.0,1.0,1.0);
	glPointSize(2.0);
	glBegin (GL_POINTS);
		glVertex2f(x,y);
	glEnd();
	glFlush();
}

float mati[30][2],mato[30][2];
int k=0,c;

class trans
{
	int transl[2][2];
public:
	void mul(float s[2][2])
	{
		int i,j,k;
		float sum;
		for(i=0;i<c;i++)
		{
			for(j=0;j<2;j++)
			{
				sum=0;
				for(k=0;k<2;k++)
				sum=sum+mati[i][k]*s[k][j];
				mato[i][j]=sum;
			}
		}
	}
	void plot(float m[][2])
	{
		glColor3f(0.0,1.0,0.0);
		glBegin(GL_LINE_LOOP);
			for(int i=0;i<c;i++)
				glVertex2f(m[i][0],m[i][1]);
		glEnd();
		glFlush();
	}
	void translation(float tx,float ty)
	{
		int i;
		for(i=0;i<c;i++)
		{
			mato[i][0]=mati[i][0]+ tx;
			mato[i][1]=mati[i][1]+ ty;
		}             
	}
	void scaling()
	{
		float scale[2][2];
		int i;
		float sx,sy;
		cout<<"Scaling->\nEnter Sx factor::";
		cin>>sx;
		cout<<"Enter Sy factor::";
		cin>>sy;
		scale[0][0]=sx;
		scale[0][1]=0;
		scale[1][0]=0;
		scale[1][1]=sy;
		mul(scale);
		plot(mato);
	}
	void rotation()
	{
		int rot;
		float angle,rota[2][2];
		cout<<"Rotation->\nEnter angle::";
		cin>>angle;
		angle=(3.14*angle)/180;
		cout<<"1.For Clockwise rotation\n2.For Anti-Clockwise rotation\nEnter your choice::";
		cin>>rot;
		switch(rot)
		{
			case 1 :rota[0][0]=cos(angle);
					rota[0][1]=-sin(angle);
					rota[1][0]=sin(angle);
					rota[1][1]=cos(angle);
					break;
			case 2 :rota[0][0]=cos(angle);
					rota[0][1]=sin(angle);
					rota[1][0]=-sin(angle);
					rota[1][1]=cos(angle);
					break;
			default:cout<<"Invalid Input!!!\n";
					system("pause");
					exit(0);
		}
		mul(rota);    
	}
	void rot_arbit()
	{
		float xm,ym;
		int i,j;
		cout<<"Rotation about arbitrary point->\nEnter x corrdinate::";
		cin>>xm;
		cout<<"Enter y corrdinate::";
		cin>>ym;
		translation(-xm,-ym);
		for(i=0;i<c;i++)
		{
			for(j=0;j<2;j++)
			{
				mati[i][j]=mato[i][j];
			}
		}
		rotation();
		for(i=0;i<c;i++)
		{
			for(j=0;j<2;j++)
			{
				mati[i][j]=mato[i][j];
			}
		}
		translation(xm,ym);
		plot(mato);
	}
};

void menu()
{
	trans t;
	float tx,ty;
	int choice;
	do
	{
		cout<<"\n1. Translation\n2. Scaling\n3. Rotation\n4. Rotation about arbitrary point\n5. Exit\nEnter your choice::";
		cin>>choice;
		switch(choice)
		{
			case 1 :cout<<"Translation->\nEnter tx factor::";
					cin>>tx;
					cout<<"Enter ty factor::";
					cin>>ty;
					t.translation(tx,ty);
					t.plot(mato);
					break;
			case 2 :t.scaling();
					break;
			case 3 :t.rotation();
					t.plot(mato);
					break;
			case 4 :t.rot_arbit();
					break;
			case 5 :exit(0);
			default:cout<<"Invalid Input!!!\n";
		}
		cout<<"Want to continue(1/0)::";
		cin>>choice;
	}while(choice==1);
}

void keyboard(unsigned char key,int x,int y) 
{
	if(key==27) 
		exit (0); 
}

void mouse(int button,int state,int x,int y)
{
	int x1,y1,p,q;
	if(state== GLUT_DOWN)
	{
		if(button==GLUT_LEFT_BUTTON)
		{
			mati[k][0]=(float)(x-250);
			mati[k][1]=(float)(250-y);
			glColor3f(1.0,0.0,0.0);
			glBegin(GL_POINTS);
			glVertex2f(mati[k][0],mati[k][1]);
			glEnd();
			k++;
			glFlush();
		}
		else if(button==GLUT_RIGHT_BUTTON)
		{
			glBegin(GL_LINE_LOOP);
			for(int i=0;i<k;i++)
			glVertex2f(mati[i][0],mati[i][1]);
			glEnd();
			c=k;
			k=0;
			glFlush();
		}
		else if(button==GLUT_MIDDLE_BUTTON)
			menu();
	}
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(w,h);
	glutCreateWindow("assign6"); 
	glutDisplayFunc(init);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}