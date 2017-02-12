#include "BetterLeaves.h"
#include "mcpe/level/BlockSource.h"
#include "mcpe/level/Level.h"

BetterLeaves::BetterLeaves(std::string const &name,int id) : Block(name,id,Material::getMaterial(MaterialType::DEVICE)){
	init();
	//setCategory(CreativeItemCategory::DECORATIONS);
	setTicking(true);
	setSolid(false);
	renderLayer = mLeaves -> renderLayer;
}

void BetterLeaves::onGraphicsModeChanged(bool, bool, bool)
{
	renderLayer = mLeaves -> renderLayer;
}

bool BetterLeaves::checkIsPathable(Entity&, BlockPos const&, BlockPos const&)const
{
	return true;
}

int BetterLeaves::getRenderLayer(BlockSource&s, BlockPos const&pos) const
{
	return mLeaves -> getRenderLayer(s,pos);
}

int BetterLeaves::getExtraRenderLayers() const
{
	return mLeaves -> getExtraRenderLayers();
}
