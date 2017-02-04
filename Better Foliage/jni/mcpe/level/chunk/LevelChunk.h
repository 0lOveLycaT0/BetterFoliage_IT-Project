#pragma once

#include "mcpe/util/ChunkBlockPos.h"
#include "mcpe/level/biome/Biome.h"

class LevelChunk
{
public:
	LevelChunk(Level &, const ChunkPos &, bool);
	ChunkPos const&getPosition()const;
	Biome& getBiome(ChunkBlockPos const&)const;
};
