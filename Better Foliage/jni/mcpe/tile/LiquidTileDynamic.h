#pragma once

#include "Tile.h"

class LiquidTileDynamic : public Tile {
public:
	bool _isWaterBlocking(TileSource*, const TilePos&);
};
