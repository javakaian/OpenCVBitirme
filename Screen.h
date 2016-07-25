#pragma once
#include "GameWorld.h"
#include "GameRenderer.h"

class Screen 
{
private :
	
	GameWorld *gm;
	GameRenderer *gr;
	
	
	
public:
	Screen(int width,int height);
	
	

	void render(Batcher *b);
	

	

	~Screen();
};