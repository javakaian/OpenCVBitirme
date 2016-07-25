#pragma once
#include "Block.h"
#include "BlockHandler.h"
#include "Map.h"
class GameWorld 
{

private:
	
	BlockHandler *blockHandler;
	Map *map;

	
public:
	GameWorld();
	
	
	void update();
	
	
	
	BlockHandler* getBlockHandler();
	Map *getMap();
	~GameWorld();
};