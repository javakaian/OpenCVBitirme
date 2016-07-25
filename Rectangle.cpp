#include "Rectangle.h"

Rectangle::Rectangle()
{
}
Rectangle::Rectangle(float xKord,float yKord,float width,float height) 
{
	this->xKord = xKord;
	this->yKord = yKord;
	this->width = width;
	this->height = height;

}


bool Rectangle::collideWith(Rectangle *r) 
{
	
	

	return false;
}
void Rectangle::update()
{
	
}
void Rectangle::setXKord(float x) 
{
	this->xKord = x;
}
void Rectangle::setYKord(float y) 
{
	this->yKord = y;

}
float Rectangle::getHeight() 
{
	return this->height;
}
float Rectangle::getWidth() 
{
	return this->width;
}
float Rectangle::getxKord() 
{
	return this->xKord;
}
float Rectangle::getyKord() 
{
	return this->yKord;
}
Rectangle::~Rectangle()
{
}
