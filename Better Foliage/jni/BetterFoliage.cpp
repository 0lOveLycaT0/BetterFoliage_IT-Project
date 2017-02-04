#include <jni.h>
#include <dlfcn.h>
#include <Substrate.h>

#include "mcpe/client/renderer/BlockTessellator.h"
#include "mcpe/block/Block.h"
#include "mcpe/block/BlockGraphics.h"
#include "mcpe/item/Item.h"
#include "mcpe/item/BlockItem.h"
#include "mcpe/item/AuxDataBlockItem.h"
#include "mcpe/level/BlockSource.h"
#include "mcpe/entity/Entity.h"

#include "betterfoliage/blocks/betterGrass/BetterGrass.h"

BlockSource *bs;

static bool (*_TessellateInWorld)(BlockTessellator*,Block const &,BlockPos const&,unsigned char,bool);
static bool TessellateInWorld(BlockTessellator *tess,Block const &block,BlockPos const &pos,unsigned char aux,bool b)
{
	Block* blockk = const_cast<Block*>(&block);
	
	/*int TR = Block::mGlass -> renderLayer1;
	Block::mBlocks[2] -> renderLayer1 = TR;*/
	
	switch(block.blockId){
		case 2:
			return tess -> grassblockRenderer(bs,blockk,pos,aux);
		break;
			
		default:
		    return _TessellateInWorld(tess,block,pos,aux,b);
		break;
	}
}

static void (*_InitClientData)();
static void InitClientData(){
	_InitClientData();
	
	//BetterGrass
	Item::mItems[201] = new AuxDataBlockItem("better_grass",201-256,Block::mBlocks[201]);
	Item::mItems[201]->setCategory(CreativeItemCategory::DECORATIONS);
}

static void (*_BG_InitBlocks)();
static void BG_InitBlocks(){
	_BG_InitBlocks();
	
	//BetterGrass
    BlockGraphics::mBlocks[201]=new BlockGraphics("portal");
	BlockGraphics::mBlocks[201]->setTextureItem("better_grass");
	BlockGraphics::mBlocks[201]->setBlockShape(BlockShape::CROSS);
	BlockGraphics::mBlocks[201]->setSoundType(BlockSoundType::GRASS);
}

static void (*_Bl_InitBlocks)();
static void Bl_InitBlocks(){
	_Bl_InitBlocks();
	
	//BetterGrass
    Block::mBlocks[201]=new BetterGrass("better_grass",201);
}

static void (*_InitCreativeItems)();
static void InitCreativeItems(){
	_InitCreativeItems();
	
	//BetterGrass
	Item::addCreativeItem(201,0);
	Item::addCreativeItem(201,1);
	Item::addCreativeItem(201,2);
	Item::addCreativeItem(201,3);
	Item::addCreativeItem(201,4);
	Item::addCreativeItem(201,5);
	Item::addCreativeItem(201,6);
	Item::addCreativeItem(201,7);
	Item::addCreativeItem(201,8);
}

/*virtual void (*_RideTick)(Entity*entity);
virtual void RideTick(Entity*entity){
	_RideTick(entity);
	entity -> Entity::getRegion();
}*/

JNIEXPORT jint JNI_OnLoad(JavaVM*,void*){
	MSHookFunction((void *)&BlockTessellator::tessellateInWorld,(void *)TessellateInWorld,(void **)&_TessellateInWorld);
    MSHookFunction((void *)&Item::initClientData,(void *)InitClientData,(void **)&_InitClientData);
	MSHookFunction((void *)&Item::initCreativeItems,(void *)InitCreativeItems,(void **)&_InitCreativeItems);
	MSHookFunction((void *)&BlockGraphics::initBlocks,(void *)BG_InitBlocks,(void **)&_BG_InitBlocks);
	MSHookFunction((void *)&Block::initBlocks,(void *)Bl_InitBlocks,(void **)&_Bl_InitBlocks);
	//MSHookFunction((void *)&Entity::rideTick,(void *)RideTick,(void **)&_RideTick);
	return JNI_VERSION_1_6;
}




