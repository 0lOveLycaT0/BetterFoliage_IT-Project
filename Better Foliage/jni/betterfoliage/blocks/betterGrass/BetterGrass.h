#pragma once

#include <memory>
#include "mcpe/block/Block.h"

class BetterGrass : public Block
{
public:	
    BetterGrass(std::string const&,int);
public:
	virtual const AABB& getCollisionShape(AABB&, BlockSource&, BlockPos const&, Entity*)const;
	//virtual bool mayPlaceOn(Block const&)const;
	//virtual bool canSurvive(BlockSource&, BlockPos const&)const;
	virtual void onGraphicsModeChanged(bool, bool, bool);
	virtual bool checkIsPathable(Entity&, BlockPos const&, BlockPos const&)const;
	virtual int getRenderLayer(BlockSource&, BlockPos const&) const;
	virtual int getExtraRenderLayers() const;
};
