#include "Screen.h"
#include <iostream>

Screen::Screen(int width,int height) 
{

	gm = new GameWorld();
	gr = new GameRenderer(gm,width,height);
	
	//std::cout << "Screen olusturuldu.." << std::endl;


}

void Screen::render(Batcher *b) 
{
	gm->update();
	gr->render(b);
}



Screen::~Screen() 
{
	std::cout << "Screen yok edildi.." << std::endl;
	delete this->gm;
	delete this->gr;
}