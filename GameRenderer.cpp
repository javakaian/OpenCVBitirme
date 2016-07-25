#include "GameRenderer.h"
#include "GameWorld.h"
#include <GLFW/glfw3.h>
#include <iostream>
GameRenderer::GameRenderer(GameWorld *gm,int width,int height) 
{
	this->gm = gm;
	this->width = width;
	this->height = height;
	//std::cout << "GameRenderer olusturuldu.." << std::endl;
}

void GameRenderer::render(Batcher *b) 
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, height, 0, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.1f, 0.1f, 0.1f, 1);

	
	gm->getBlockHandler()->render(b);
	gm->getMap()->render(b);
}
GameRenderer::~GameRenderer() 
{
	std::cout << "GameRenderer yok edildi.." << std::endl;
}


