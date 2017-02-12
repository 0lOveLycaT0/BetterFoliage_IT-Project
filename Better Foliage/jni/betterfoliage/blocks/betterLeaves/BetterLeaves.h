#pragma once

#include <memory>
#include "mcpe/block/Block.h"

class BetterLeaves : public Block
{
public:	
    BetterLeaves(std::string const&,int);
public:
	virtual void onGraphicsModeChanged(bool, bool, bool);
	virtual bool checkIsPathable(Entity&, BlockPos const&, BlockPos const&)const;
	virtual int getRenderLayer(BlockSource&, BlockPos const&) const;
	virtual int getExtraRenderLayers() const;
};
