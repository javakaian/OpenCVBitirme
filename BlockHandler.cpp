#include "BlockHandler.h"
#include <vector>
#include "Block.h"
#include <iostream>
#include <time.h>
#include <GLFW/glfw3.h>
#include <algorithm>
BlockHandler::BlockHandler(Map *map)
{
	
	
	this->map = map;
    
	rowCounter = 0;
	addBlock();
	eraseRow = false;
	
}
void BlockHandler::addBlock() 
{
		
		vectorBlock.push_back(new Block(4));
		//std::cout << "vectore eklendi.." << std::endl;
		
}
void BlockHandler::render(Batcher *b) 
{
	map->render(b);
	for (int i = 0; i < vectorBlock.size();i++)
	{
		vectorBlock.at(i)->render(b);
	}
	
}
void BlockHandler::update() 
{
	
	if (!vectorBlock.at(vectorBlock.size() - 1)->isMovable())
	{
		map->update(vectorBlock.at(vectorBlock.size() - 1)->getCurrentSegmentX(),
			vectorBlock.at(vectorBlock.size() - 1)->getCurrentSegmentY(),
			vectorBlock.at(vectorBlock.size() - 1)->getPreviousSegmentX(),
			vectorBlock.at(vectorBlock.size() - 1)->getPreviousSegmentY());
		addBlock();
		

		for (int i = 0; i < 16; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				
				//std::cout << map->mapArray[i][j];

			}
			//std::cout << "  " << std::endl;
		}



	}
	
	

	for (int i = 0; i < vectorBlock.size(); i++)
	{
		vectorBlock.at(i)->update();
		

		//check for row
		for (int i = 0; i < 16;i++)
		{
			for (int j = 0; j < 8;j++)
			{
				if (map->mapArray[i][j]==1) 
				{
				
					rowCounter++;
					if (rowCounter==8) 
					{
						//std::cout << (i + 1) << ". row full" << std::endl;
						
						eraseRow = true;
						map->deleteRow(i);

						eraseBlock(i);
						reArrangeBlocks();
						map->reArrangeMap();
						rowCounter = 0;
					}
					
					
				}
				
			}
			rowCounter = 0;
		}
		
		
		
		
		
		//collision checking
		
			int segmentX = vectorBlock.at(vectorBlock.size()-1)->getCurrentSegmentX();
			int segmentY = vectorBlock.at(vectorBlock.size()-1)->getCurrentSegmentY();
			if (map->mapArray[segmentY + 1][segmentX] == 1)
			{
				vectorBlock.at(vectorBlock.size() - 1)->setMovable(false);
			}
		
		
		
		
	}
	
	

}
void BlockHandler::reArrangeBlocks() 
{
	for (int i = 0; i < vectorBlock.size();i++)
	{
		vectorBlock.at(i)->setCurrentSegmentY(vectorBlock.at(i)->getCurrentSegmentY() + 1);
	}
}

void BlockHandler::eraseBlock(int index)
{
	/*int iterator = 0;
	// daha sonra fonksiyon haline getir
	for (int i = 0; i < vectorBlock.size(); i++)
	{
		iterator = i;
		if (vectorBlock.at(i)->getCurrentSegmentY() == index )
		{
			vectorBlock.erase(vectorBlock.begin()+iterator);
			;
			//vectorBlock.erase(vectorBlock.begin() + i-1);
			std::cout << i << ". block silindi.." << std::endl;
		}
		*/
	for (std::vector<Block*>::iterator it = vectorBlock.begin(); it != vectorBlock.end(); )
	{
		if ((*it)->getCurrentSegmentY() == index)
			it = vectorBlock.erase(it);
		else
			++it;
	}
	
}
	


BlockHandler::~BlockHandler()
{
	std::cout << "Block Handler yok edildi.."<<std::endl;

	for (int i = 0; i < vectorBlock.size(); i++)
	{
	 delete	vectorBlock.at(i);

	}
}
