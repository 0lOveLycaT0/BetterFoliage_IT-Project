#pragma once

#include "texture/TextureUVCoordinateSet.h"
#include "mcpe/util/AABB.h"
#include "MaterialPtr.h"
#include "mcpe/block/Block.h"
#include "mcpe/block/BlockShape.h"
#include "mcpe/level/BlockSource.h"
#include "Tessellator.h"
#include "mcpe/util/BlockPos.h"
#include "mcpe/block/BlockGraphics.h"
class Vec3;
typedef unsigned char uchar;

namespace mce
{
	class TexturePtr;
};
class BlockTessellator
{
public:
	bool forceOpaque; // 0
	bool otherb; // 1
	BlockSource* blockSource; // 4
	TextureUVCoordinateSet forcedUV; // 8
	bool useForcedUV; // 36
	bool idk; // 37
	int renderLayer; // 40
	char filler[84]; // 44
	int rotBottom; // 128
	int rotTop; // 132
	int rotNorth; // 136
	int rotSouth; // 140
	int rotWest; // 144
	int rotEast; // 148
	char filler1[500]; // 152
	mce::MaterialPtr material; // 652
	Tessellator& tessellator; // 664
	AABB aabb; // 668
public:
	bool tessellateInWorld(Block const&, const BlockPos&, unsigned char, bool);
	bool tessellateBlockInWorld(Block const&, const BlockPos&,int);
	void renderGuiBlock(const FullBlock&, const mce::TexturePtr&, float, float);
	
	void renderNorth(Block&, const Vec3&, const TextureUVCoordinateSet&);
	void renderEast(Block&, const Vec3&, const TextureUVCoordinateSet&);
	void renderSouth(Block&, const Vec3&, const TextureUVCoordinateSet&);
	void renderWest(Block&, const Vec3&, const TextureUVCoordinateSet&);
	void renderFaceDown(Block&, const Vec3&, const TextureUVCoordinateSet&);
	void renderFaceUp(Block&, const Vec3&, const TextureUVCoordinateSet&);
	
	unsigned int getLightColor(const BlockPos&);
	BlockSource& getRegion() const;
	void setRegion(BlockSource&);
	int getRenderLayer() const;
	void setRenderLayer(int);
	void setForceOpaque(bool);
	void tex1(unsigned int);
	void blend(int, int, int, int);
	
	void tessellateCrossInWorld(Block const&, BlockPos const&, unsigned char, bool);
	Color _getBlockColor(BlockPos const&, Block const&);
	Color _getBlockColor(BlockPos const&, Block const&, unsigned char);
	TextureUVCoordinateSet const& _getTexture(Block const&, signed char, int) const;
	Tessellator& getTessellator();
	
	//custom
    //bool grassblockRenderer(Block*, BlockPos const&, unsigned char, BlockSource*);
};
