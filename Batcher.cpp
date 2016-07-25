#include "Batcher.h"
#include <GLFW/glfw3.h>
#include <iostream>
Batcher::Batcher() 
{
	//std::cout << "Batcher olusturuldu.." << std::endl;
}
void Batcher::drawLine(float x1,float y1,float x2,float y2) 
{
	glBegin(GL_LINES);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glEnd();
}

void Batcher::drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3)
{
	glBegin(GL_TRIANGLES);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glEnd();
}
void Batcher::drawRectangle(float x, float y, float width, float height)
{
	

	glBegin(GL_QUADS);
	glColor3f(0.235294, 0.701961, 0.443137);
	glVertex2f(x, y);
	glVertex2f(x + width, y);
	glVertex2f(x + width, y + height);
	glVertex2f(x, y + height);
	glEnd();

}
void Batcher::drawRectangleLineWhite(float x, float y, float width, float height)
{
	glBegin(GL_LINE_LOOP);
	glColor3f((0.2),(0.2),(0.2));
	glVertex2f(x, y);
	glVertex2f(x + width, y);
	glVertex2f(x + width, y + height);
	glVertex2f(x, y + height);
	glEnd();

}
void Batcher::drawRectangleLineRed(float x, float y, float width, float height)
{


	glBegin(GL_LINE_LOOP);
	glColor3f(1, 0, 0);
	glVertex2f(x, y);
	glVertex2f(x + width, y);
	glVertex2f(x + width, y + height);
	glVertex2f(x, y + height);
	glEnd();

}
Batcher::~Batcher() 
{
	std::cout << "Batcher yok edildi.." << std::endl;
}