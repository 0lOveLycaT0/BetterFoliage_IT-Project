#pragma once

class BlockSource;
class BlockPos;
class Random;
class BiomeSource;

#include "level/ChunkPos.h"

struct FancyTreeFeature
{
	void place(BlockSource&,BlockPos const&,Random&)const;
};
struct JungleTreeFeature
{
	void place(BlockSource&,BlockPos const&,Random&)const;
};
struct TreeFeature
{
	void place(BlockSource&,BlockPos const&,Random&,int)const;
	void _placeLeaf(BlockSource&,BlockPos const&)const;
	void placeTrunk(BlockSource&,BlockPos const&,Random&,int)const;
};
struct MegaJungleTreeFeature
{
	void place(BlockSource&,BlockPos const&,Random&)const;
};
struct MegaTreeFeature
{
	void place(BlockSource&,BlockPos const&,Random&)const;
};
struct MegaPineTreeFeature
{
	void place(BlockSource&,BlockPos const&,Random&)const;
};
struct RoofTreeFeature
{
	void place(BlockSource&,BlockPos const&,Random&)const;
};
struct SavannaTreeFeature
{
	void place(BlockSource&,BlockPos const&,Random&)const;
};
struct SwampTreeFeature
{
	void place(BlockSource&,BlockPos const&,Random&)const;
};
struct BirchFeature
{
	void place(BlockSource&,BlockPos const&,Random&)const;
};
struct PineFeature
{
	void place(BlockSource&,BlockPos const&,Random&)const;
};
struct MineshaftFeature
{
	bool isFeatureChunk(BiomeSource*,Random&,ChunkPos const&);
};
struct StrongholdFeature
{
	bool isFeatureChunk(BiomeSource*,Random&,ChunkPos const&);
};
struct VillageFeature
{
	bool isFeatureChunk(BiomeSource*,Random&,ChunkPos const&);
};
struct OreFeature
{
	char filler[50];
	OreFeature(BlockID,int);
	void place(BlockSource&,BlockPos const&,Random&)const;
};
