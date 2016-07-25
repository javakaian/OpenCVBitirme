#pragma once
class Rectangle
{
private:
	float xKord;
	float yKord;
	float width;
	float height;

public:
	Rectangle();
	Rectangle(float x,float y,float width,float height);
	~Rectangle();
	float getxKord();
	float getyKord();
	float getWidth();
	float getHeight();
	void setXKord(float x);
	void setYKord(float y);
	bool collideWith(Rectangle *r);
	void update();
};

