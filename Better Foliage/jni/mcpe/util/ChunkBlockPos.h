#pragma once

#include "BlockPos.h"

class ChunkBlockPos
{
public:
	int x;
	int y;
	int z;
public:
	ChunkBlockPos(BlockPos const&);
};
