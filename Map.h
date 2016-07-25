#pragma once
#include "Batcher.h"
class Map
{
private:
	int row;
	int col;
	
public:
	Map();
	int mapArray[16][8];
	void initMap();
	void render(Batcher *b);
	void update(int currentX, int currentY,int prevX,int prevY);
	void deleteRow(int);
	void clearMap();
	void reArrangeMap();
	~Map();
};

