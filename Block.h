#pragma once
#include "Batcher.h"
#include "Rectangle.h"
#include "Map.h"
class Block
{
private:
	
	
	
	
	bool movable;
	
	int prevSegmentX;
	int currentSegmentX;
	int prevSegmentY;
	int currentSegmentY;
	double currentTime;
	double previousTime;

	
public:
	Block(float xKord, float yKord, float width, float height);
	Block(int segment);
	Block();
	void render(Batcher *b);
	void update();
	
	bool isMovable();
	void setMovable(bool movable);
	
	int getPreviousSegmentX();
	void setPreviousSegmentX(int segment);
	int getCurrentSegmentX();
	void setCurrentSegmentX(int segment);
	int getPreviousSegmentY();
	void setPreviousSegmentY(int segment);
	int getCurrentSegmentY();
	void setCurrentSegmentY(int segment);
	void moveOneStepLeft();
	void moveOneStepRight();
	void moveOneStepDown();
	
	~Block();
};