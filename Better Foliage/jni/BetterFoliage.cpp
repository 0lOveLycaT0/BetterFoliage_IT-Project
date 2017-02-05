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

Entity* e;
BlockSource* bs;

static bool (*_TessellateInWorld)(BlockTessellator*,Block &,BlockPos const&,unsigned char,bool);
static bool TessellateInWorld(BlockTessellator *tess,Block &block,BlockPos const &pos,unsigned char aux,bool b)
{
	Block* blockk = const_cast<Block*>(&block);
	int x = pos.x, y = pos.y, z = pos.z;
	
	/*int TR = Block::mGlass -> renderLayer1;
	Block::mBlocks[2] -> renderLayer1 = TR;*/
	
	/*switch(block.blockId){
		case 2:
			return tess -> grassblockRenderer(blockk,pos,aux,bs);
		break;
			
		default:
		    return _TessellateInWorld(tess,block,pos,aux,b);
		break;
	}*/
	
	if(block.blockId == 2){
		if(bs -> getBlock(pos.x,pos.y+1,pos.z) == Block::mAir){
			bs -> setBlockAndData(x,y+1,z,201,0,3);
		}
		return _TessellateInWorld(tess,block,pos,aux,b);
	}
	/*else if(block.blockId == 201){
		float offsetx = ((x - z + y) % 10) / 45 , offsetz = ((x - z - y) % 10) / 45;
		Block::mBlocks[201] -> setVisualShape({0,-0.2,0,1+offsetx,0.8,1+offsetz});
	}*/
	return _TessellateInWorld(tess,block,pos,aux,b);
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

static void (*_NormalTick)(Entity*entity);
static void NormalTick(Entity*entity){
	_NormalTick(entity);
	
    ::e = entity;
	*bs = entity -> getRegion();
}

JNIEXPORT jint JNI_OnLoad(JavaVM*,void*){
	MSHookFunction((void *)&BlockTessellator::tessellateInWorld,(void *)TessellateInWorld,(void **)&_TessellateInWorld);
    MSHookFunction((void *)&Item::initClientData,(void *)InitClientData,(void **)&_InitClientData);
	MSHookFunction((void *)&Item::initCreativeItems,(void *)InitCreativeItems,(void **)&_InitCreativeItems);
	MSHookFunction((void *)&BlockGraphics::initBlocks,(void *)BG_InitBlocks,(void **)&_BG_InitBlocks);
	MSHookFunction((void *)&Block::initBlocks,(void *)Bl_InitBlocks,(void **)&_Bl_InitBlocks);
	MSHookFunction((void *)&Entity::normalTick,(void *)NormalTick,(void **)&_NormalTick);
	return JNI_VERSION_1_6;
}




