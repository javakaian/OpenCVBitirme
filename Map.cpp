#include "Map.h"
#include <GLFW/glfw3.h>
#include <iostream>
Map::Map()
{
	row = 16;
	col = 8;

	initMap();
	
}

void Map::initMap() 
{
	for (int i = 0; i < row;i++)
	{
		for (int j = 0; j < col;j++)
		{
			mapArray[i][j] = 0;

		}
	}
}
void Map::deleteRow(int i) 
{
	
	for (int j = 0; j < 8;j++)
	{
		mapArray[i][j] = 0;
	}
}
void Map::reArrangeMap() 
{
	/*for (int i = 0; i < row-1; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (mapArray[i][j] == 1 && mapArray[i+1][j]==0) 
			{
				mapArray[i + 1][j] = 1;
				mapArray[i ][j] = 0;
				
			}
		

		}
		
	}*/
	for (int i = row-1; i >= 0; i--)
	{
		for (int j = 0; j < col; j++)
		{
			mapArray[i + 1][j] = mapArray[i][j];


		}

	}

}
void Map::render(Batcher *b) 
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (mapArray[i][j]==1) 
			{
				
				//b->drawRectangle((j * 50) + 1, (i) * 50, 48,48);
			
			}
			
				
				glColor3f(0, 1, 0);
				b->drawRectangleLineWhite((j * 50) + 1, i * 50, 48, 48);
			
				
			
			

		}
	}
}

void Map::update(int currentX, int currentY,int prevX,int prevY) 
{
	//initMap();
	//clearMap();
	
	mapArray[currentY][currentX] = 1;
}
void Map::clearMap()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (mapArray[i][j] == 1 && mapArray[i + 1][j] == 0)
			{
				//std::cout << "javakaian" << std::endl;
				mapArray[i][j] == 0;

			}





		}
	}
}
Map::~Map()
{
}
