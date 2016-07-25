#pragma once
class Batcher 
{
public :
	Batcher();
	void drawLine(float x1,float y1,float x2,float y2);
	void drawRectangle(float x,float y,float width,float height);
	void drawRectangleLineRed(float x, float y, float width, float height);
	void drawRectangleLineWhite(float x, float y, float width, float height);

	void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3);
	~Batcher();
};