#include "BetterGrass.h"
#include "mcpe/level/BlockSource.h"
#include "mcpe/level/Level.h"

BetterGrass::BetterGrass(std::string const &name,int id) : Block(name,id,Material::getMaterial(MaterialType::DEVICE)){
	init();
	setCategory(CreativeItemCategory::DECORATIONS);
	setTicking(true);
	setSolid(false);
	renderLayer = mTallgrass -> renderLayer;
}

const AABB& BetterGrass::getCollisionShape(AABB&box, BlockSource&s, BlockPos const&pos, Entity*e)const
{
	return mTallgrass -> getCollisionShape(box,s,pos,e);
}

bool BetterGrass::mayPlaceOn(Block const&b)const
{
	return mTallgrass -> mayPlaceOn(b);
}

bool BetterGrass::canSurvive(BlockSource&s, BlockPos const&pos)const
{
	return mTallgrass -> canSurvive(s,pos);
}

void BetterGrass::onGraphicsModeChanged(bool, bool, bool)
{
	renderLayer = mTallgrass -> renderLayer;
}

bool BetterGrass::checkIsPathable(Entity&, BlockPos const&, BlockPos const&)const
{
	return true;
}

int BetterGrass::getRenderLayer(BlockSource&s, BlockPos const&pos) const
{
	return mTallgrass -> getRenderLayer(s,pos);
}

int BetterGrass::getExtraRenderLayers() const
{
	return mTallgrass -> getExtraRenderLayers();
}


