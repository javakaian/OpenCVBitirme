#pragma once
#include "GameWorld.h"

class GameRenderer 
{
private:
	GameWorld *gm;
	int width;
	int height;
	
public:
	GameRenderer(GameWorld *gm,int width,int height);

	void render(Batcher *b);
	
	~GameRenderer();

};