#pragma once

#include <memory>
#include "../blockentity/BlockEntity.h"
#include "../util/Brightness.h"
#include "LightLayer.h"
#include "DimensionId.h"

class Color;
class Level;
class ChunkSource;
class BlockPos;
class BlockID;
class BlockTickingQueue;
class LevelChunk;
class FullBlock;
class HitResult;
class Vec3;
class AABB;
class Material;
class BlockEntity;
class LightLayer;
class ChunkPos;
class Bounds;
class Dimension;
class BlockSourceListener;
class Biome;
class Entity;

class BlockSource
{
public:
	BlockSource(Level &, Dimension &, ChunkSource &, bool, bool);
	virtual ~BlockSource();
	void addListener(BlockSourceListener &);
	void blockEvent(BlockPos const &, int, int);
	void blockEvent(int, int, int, int, int);
	bool canSeeSky(BlockPos const &);
	bool canSeeSky(int, int, int);
	void checkIsTopRainBlockPos(BlockPos const &);
	void clearCachedLastChunk();
	void clip(Vec3 const &, Vec3 const &, bool, bool, int);
	void containsAny(BlockPos const &, BlockPos const &);
	void containsAnyLiquid(AABB const &);
	void containsFireBlock(AABB const &);
	void fetchAABBs(AABB const &, bool);
	void findNextTopSolidBlockUnder(BlockPos &);
	void fireAreaChanged(BlockPos const &, BlockPos const &);
	void fireBlockChanged(BlockPos const &, FullBlock, FullBlock, int);
	void fireBlockEntityChanged(BlockEntity &);
	void fireBlockEntityRemoved(std::unique_ptr<BlockEntity>);
	void fireBlockEvent(int, int, int, int, int);
	void fireBlocksDirty(int, int, int, int, int, int);
	void fireBrightnessChanged(BlockPos const &);
	Biome* getBiome(BlockPos const &);
	Block* getBlock(BlockPos const &);
	Block* getBlock(int, int, int);
	
	FullBlock getBlockAndData(int, int, int);
	FullBlock getBlockAndData(BlockPos const &);
	
	BlockEntity* getBlockEntity(int, int, int);
	BlockID getBlockID(int, int, int);
	BlockID getBlockID(BlockPos const &);
	Brightness getBrightness(LightLayer const &, int, int, int);
	Brightness getBrightness(int, int, int);
	Brightness getBrightness(LightLayer const &, BlockPos const &);
	Brightness getBrightness(BlockPos const &);
	LevelChunk* getChunk(int, int);
	LevelChunk* getChunkAt(int, int, int);
	LevelChunk* getChunkAt(BlockPos const &);
	ChunkSource* getChunkSource();
	int getData(BlockPos const &);
	int getData(int, int, int);
	Dimension* getDimension();
	Dimension const*const getDimensionConst();
	DimensionId getDimensionId()const;
	int getExtraData(BlockPos const &);
	int getGrassColor(BlockPos const &);
	int getHeightmap(BlockPos const &);
	int getHeightmap(int, int);
	BlockPos getHeightmapPos(BlockPos const &);
	Level& getLevel();
	Level const& getLevelConst();
	Color getLightColor(BlockPos const &, int);
	Material const& getMaterial(BlockPos const &);
	Material const& getMaterial(int, int, int);
	Brightness getRawBrightness(BlockPos const &, bool);
	Brightness getRawBrightness(int, int, int, bool);
	void getSeenPercent(Vec3 const &, AABB const &);
	BlockTickingQueue getTickQueue(BlockPos const &);
	Block* getTopBlock(int, int &, int);
	BlockPos getTopRainBlockPos(BlockPos const &);
	Block* getTopSolidBlock(BlockPos const &, bool);
	Block* getTopSolidBlock(int, int, bool);
	LevelChunk* getWritableChunk(ChunkPos const &);
	bool hasBlock(BlockPos const &);
	bool hasBlock(int, int, int);
	bool hasChunksAt(AABB const &);
	bool hasChunksAt(BlockPos const &, BlockPos const &);
	bool hasChunksAt(BlockPos const &, int);
	bool hasChunksAt(Bounds const &);
	bool hasChunksAt(int, int, int, int);
	bool isConsideredSolidBlock(BlockPos const &);
	bool isConsideredSolidBlock(int, int, int);
	bool isEmptyBlock(BlockPos const &);
	bool isEmptyBlock(int, int, int);
	bool isHumidAt(BlockPos const &);
	bool isOwnerThread();
	bool isSnowTemperature(BlockPos const &);
	bool isSolidBlockingBlock(BlockPos const &);
	bool isSolidBlockingBlock(int, int, int);
	bool isTopSolidBlocking(Block *, unsigned char);
	bool isTopSolidBlocking(BlockPos const &);
	bool isTopSolidBlocking(int, int, int);
	void onChunkDiscarded(LevelChunk &);
	void removeBlock(BlockPos const &);
	void removeBlock(int, int, int);
	void removeListener(BlockSourceListener &);
	void runLightUpdates(LightLayer const &, BlockPos const &, BlockPos const &);
	void setBlock(BlockPos const &, BlockID, int);
	void setBlock(int, int, int, BlockID, int);
	void setBlockAndData(BlockPos const &, BlockID, unsigned char, int,Entity*);
	void setBlockAndData(BlockPos const &, FullBlock, int,Entity*);
	void setBlockAndData(int, int, int, BlockID, unsigned char, int);
	void setBlockAndData(int, int, int, FullBlock, int);
	void setBlockAndDataNoUpdate(int, int, int, FullBlock);
	void setBlockNoUpdate(int, int, int, BlockID);
	void setBrightness(LightLayer const &, BlockPos const &, Brightness);
	void setBrightness(LightLayer const &, int, int, int, Brightness);
	void setExtraData(BlockPos const &, unsigned short);
	void setGrassColor(int, BlockPos const &, int);
	void setTickingQueue(BlockTickingQueue &);
	bool shouldFireEvents(LevelChunk &);
	bool shouldFreeze(BlockPos const &, bool);
	bool shouldThaw(BlockPos const &, bool);
	void updateLightIfOtherThan(LightLayer const &, BlockPos const &, Brightness);
	void updateNeighborsAt(BlockPos const &);
	bool shouldFreezeIgnoreNeighbors(BlockPos const&);
};
