#pragma once

#include "BlockID.h"

class FullBlock
{
public:
	static FullBlock AIR;

public:
	BlockID id;
	unsigned char damage;

public:
	FullBlock() : id(0), damage(0) {};
	FullBlock(BlockID tileId, unsigned char damage) : id(tileId), damage(damage) {}
};
