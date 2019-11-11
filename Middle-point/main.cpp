//Naomi Mwangi - 101426
//Gabriel Wangai - 101536
//Hezekiel Gachu - 100384
//Ian Kiragu - 99928
#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>
using namespace std;

int pntX1 = 0, pntY1 = 0, r; //Setting the centre points to be zero

void plot(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x + pntX1, y + pntY1);
	glEnd();
}


void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100.0, 100.0, -100.0, 100.0);
}


void midPointCircleAlgo()
{
	int x = 0;
	int y = r; //the y coordinate is set to be the radius for our first point
	float decision = 5 / 4 - r; //This is our first p value
	plot(x, y);

	while (y > x)
	{
		if (decision < 0) //if p is less than zero
		{
			x++;
			decision += 2 * x + 1; 
		}
		else  //if p is greater than zero
		{
			y--;
			x++;
			decision += 2 * (x - y) + 1;
		}
		plot(x, y);
		plot(x, -y);
		plot(-x, y);
		plot(-x, -y);
		plot(y, x);
		plot(-y, x);
		plot(y, -x);
		plot(-y, -x);
	}

}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(1.0);

	midPointCircleAlgo();

	glFlush();
}

void main(int argc, char** argv)
{
	cout << "Enter the radius of the cirlce:\n\n" << endl;

	
	cout << "\nEnter radius : "; cin >> r;


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Line Drawing Alogrithms");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();

}