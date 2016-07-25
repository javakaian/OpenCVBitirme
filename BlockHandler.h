#pragma once
#include<vector>
#include "Block.h"
#include "Map.h"
class BlockHandler
{
private :
	

	std::vector<Block*> vectorBlock;
	bool firstTime;
	double first;
	double second;
	bool eraseRow;
	int rowCounter;
	Map *map;
public:
	BlockHandler(Map *map);
	~BlockHandler();

	void render(Batcher *b);
	void update();
	void addBlock();
	void eraseBlock(int index);
	void reArrangeBlocks();

	
	

};

