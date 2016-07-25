#include "GameWorld.h"
#include <iostream>

GameWorld::GameWorld() 
{
	map = new Map();
	blockHandler = new BlockHandler(map);
	
	//std::cout << "GameWorld olusturuldu.." << std::endl;

}

void GameWorld::update() 
{
	
	
	blockHandler->update();
	
}


BlockHandler* GameWorld::getBlockHandler()
{
	return blockHandler;
}
Map* GameWorld::getMap() 
{
	return map;
}
GameWorld::~GameWorld() 
{
	std::cout << "GameWorld yok edildi.." << std::endl;
	delete blockHandler;
	delete map;
}