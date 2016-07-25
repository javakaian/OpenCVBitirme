#include <iostream>
#include "Block.h"
#include "KeyBoard.h"
#include <GLFW/glfw3.h>
#include "FileSystem.h"
Block::Block(float xKord,float yKord,float width,float height) 
{


	
}
Block::Block() 
{

}
Block::Block(int segment) 
{
	//std::cout << "Block olusturuldu" << std::endl;
	movable = true;
	
	
	this->currentSegmentX = segment;
	this->prevSegmentX = segment;
	this->currentSegmentY = 0;
	this->prevSegmentY = 0;
	previousTime = glfwGetTime();
	
	
	
	
	

}
void Block::render(Batcher *b) 
{
	b->drawRectangle(currentSegmentX*50+1,currentSegmentY*50,48,48);

}
void Block::update() 
{
	currentTime = glfwGetTime();
	if (movable) 
	{
		if (currentTime - previousTime >=0.2)
		{
			previousTime = currentTime;
			
				moveOneStepDown();
				
			
		}
	}
	
	if ((FileSystem::right && movable)) 
	{
       
		moveOneStepRight();
		
		
	}
    if ((FileSystem::left && movable))
	{
		
		moveOneStepLeft();
		
	}
	
	
	if ((KeyBoard::RIGHT && movable)) 
	{
       
		moveOneStepRight();
		
		
	}
	if (KeyBoard::DOWN && movable)
	{
		//moveThreeStepDown();

	}
    if ((KeyBoard::LEFT && movable))
	{
		
		moveOneStepLeft();
		
	}
}
void Block::moveOneStepDown()
{
	
	

		if (currentSegmentY != 15)
		{
			currentSegmentY ++;
			prevSegmentY = currentSegmentY - 1;
			
			prevSegmentX = currentSegmentX;
			

		}
		if (currentSegmentY == 15)
		{
			
			//currentSegmentY = currentSegmentY;
			this->movable = false;
		}
		
}
/*
void Block::moveOneStepRight()
{
	if (FileSystem::runOnce ) 
	{
		
		if (currentSegmentX !=7)
		{
			prevSegmentX = currentSegmentX;
			currentSegmentX =prevSegmentX +1;
			prevSegmentY = currentSegmentY;
			
		}
		if(currentSegmentX == 7)
		{
			//currentSegmentX = currentSegmentX;
			
		}
	FileSystem::runOnce=false;
	}
    
    
	
	
	
}*/
/*

void Block::moveOneStepLeft() 
{
	if (FileSystem::runOnce) 
	{
		
		if (currentSegmentX !=0) 
		{
			prevSegmentX = currentSegmentX;
			currentSegmentX = prevSegmentX - 1;
			prevSegmentY = currentSegmentY;
			
			
		}
		if(currentSegmentX ==0)
		{
			//currentSegmentX = currentSegmentX;
			
		}

        FileSystem::runOnce=false;
		 
	}
    
   
   
	
}

*/

void Block::moveOneStepLeft() 
{
	if (KeyBoard::runOnce) 
	{
		
		if (currentSegmentX !=0) 
		{
			prevSegmentX = currentSegmentX;
			currentSegmentX = prevSegmentX - 1;
			prevSegmentY = currentSegmentY;
			
			
		}
		if(currentSegmentX ==0)
		{
			//currentSegmentX = currentSegmentX;
			
		}

		
		
			
		
		KeyBoard::runOnce = false;
       
		
	}
	
}
void Block::moveOneStepRight()
{
	if (KeyBoard::runOnce ) 
	{
		
		if (currentSegmentX !=7)
		{
			prevSegmentX = currentSegmentX;
			currentSegmentX =prevSegmentX +1;
			prevSegmentY = currentSegmentY;
			
		}
		if(currentSegmentX == 7)
		{
			//currentSegmentX = currentSegmentX;
			
		}
	

		KeyBoard::runOnce = false;
		
	}
	
	
}

int Block::getCurrentSegmentX() 
{
	return this->currentSegmentX;
}
void Block::setCurrentSegmentX(int segment) 
{
	this->currentSegmentX = segment;
}
int Block::getPreviousSegmentX() 
{
	return this->prevSegmentX;
}
void Block::setPreviousSegmentX(int segment) 
{
	this->prevSegmentX = segment;
}
bool Block::isMovable() 
{
	return this->movable;
}
void Block::setMovable(bool movable)
{
	this->movable = movable;
}
int Block::getCurrentSegmentY()
{
	return this->currentSegmentY;
}
void Block::setCurrentSegmentY(int segment)
{
	this->currentSegmentY = segment;
}
int Block::getPreviousSegmentY()
{
	return this->prevSegmentY;
}
void Block::setPreviousSegmentY(int segment)
{
	this->prevSegmentY = segment;
}

Block::~Block() 
{
	std::cout << "Block yok edildi.." << std::endl;
	
}