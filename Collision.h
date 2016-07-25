#pragma once
#include "Block.h"
class Collision
{
public:
	Collision();
	~Collision();
	static void checkCollision(Block *b1,Block *b2);
};

