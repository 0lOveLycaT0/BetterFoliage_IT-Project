#include <jni.h>
#include <dlfcn.h>
#include <Substrate.h>
#include <cstdlib>

#include "mcpe/client/renderer/BlockTessellator.h"
#include "mcpe/block/Block.h"
#include "mcpe/block/BlockGraphics.h"
#include "mcpe/item/Item.h"
#include "mcpe/item/BlockItem.h"
#include "mcpe/item/AuxDataBlockItem.h"
#include "mcpe/level/BlockSource.h"
#include "mcpe/entity/Entity.h"
#include "mcpe/client/renderer/Tessellator.h"
#include "mcpe/util/FullBlock.h"
#include "mcpe/level/Level.h"

#include "betterfoliage/blocks/betterGrass/BetterGrass.h"

//Entity* e;
//BlockSource* bs;

static bool (*_TessellateInWorld)(BlockTessellator*,Block &,BlockPos const&,unsigned char,bool);
static bool TessellateInWorld(BlockTessellator *tess,Block &block,BlockPos const &pos,unsigned char aux,bool b)
{
	Block* blockk = const_cast<Block*>(&block);
	int x = pos.x, y = pos.y, z = pos.z;
	
	int TR = Block::mTallgrass -> renderLayer1;
	Block::mBlocks[2] -> renderLayer1 = TR;
	
	Block::mBlocks[2] -> setSolid(false);
	
	if(block.blockId == 2){
		srand(x^y^z);
		unsigned char raux = rand()%3;
		float const  offsetx = fmod((((float)rand())/((float)RAND_MAX)),0.2)*((rand()%2)?1:-1);
		float const  offsety = fmod((((float)rand())/((float)RAND_MAX)),0.1)*((rand()%2)?1:-1);
		float const  offsetz = fmod((((float)rand())/((float)RAND_MAX)),0.2)*((rand()%2)?1:-1);
        
		if(tess -> getRegion().getBlock(x,y+1,z) == Block::mAir){
			Tessellator& t = tess -> getTessellator();
	        t.init();
		    //t.color(tess -> _getBlockColor({x, y, z},block,aux));
		    TextureUVCoordinateSet const& uv = tess -> _getTexture(*Block::mBlocks[230],0,raux);
		
		    t.vertexUV(x + offsetx + 0.00,y + 0.80,z + offsetz + 0.00,uv.maxU,uv.maxV);
		    t.vertexUV(x + offsetx + 0.00,y + offsety + 1.90,z + offsetz + 0.00,uv.maxU,uv.minV);
		    t.vertexUV(x + offsetx + 1.00,y + offsety + 1.90,z + offsetz + 1.00,uv.minU,uv.minV);
		    t.vertexUV(x + offsetx + 1.00,y + 0.80,z + offsetz + 1.00,uv.minU,uv.maxV);
		
		    t.vertexUV(x + offsetx + 0.00,y + 0.80,z + offsetz + 0.00,uv.minU,uv.maxV);
		    t.vertexUV(x + offsetx + 1.00,y + 0.80,z + offsetz + 1.00,uv.maxU,uv.maxV);
		    t.vertexUV(x + offsetx + 1.00,y + offsety + 1.90,z + offsetz + 1.00,uv.maxU,uv.minV);
	        t.vertexUV(x + offsetx + 0.00,y + offsety + 1.90,z + offsetz + 0.00,uv.minU,uv.minV);
		
		    t.vertexUV(x + offsetx + 0.00,y + 0.80,z + offsetz + 1.00,uv.maxU,uv.maxV);
		    t.vertexUV(x + offsetx + 0.00,y + offsety + 1.90,z + offsetz + 1.00,uv.maxU,uv.minV);
		    t.vertexUV(x + offsetx + 1.00,y + offsety + 1.90,z + offsetz + 0.00,uv.minU,uv.minV);
		    t.vertexUV(x + offsetx + 1.00,y + 0.80,z + offsetz + 0.00,uv.minU,uv.maxV);
		
		    t.vertexUV(x + offsetx + 0.00,y + 0.80,z + offsetz + 1.00,uv.minU,uv.maxV);
	        t.vertexUV(x + offsetx + 1.00,y + 0.80,z + offsetz + 0.00,uv.maxU,uv.maxV);
	    	t.vertexUV(x + offsetx + 1.00,y + offsety + 1.90,z + offsetz + 0.00,uv.maxU,uv.minV);
		    t.vertexUV(x + offsetx + 0.00,y + offsety + 1.90,z + offsetz + 1.00,uv.minU,uv.minV);
		}
		return _TessellateInWorld(tess,block,pos,aux,b);
	}
	else{
		return _TessellateInWorld(tess,block,pos,aux,b);
	}
}

static void (*_InitClientData)();
static void InitClientData(){
	_InitClientData();
	
	//BetterGrass
	Item::mItems[230] = new AuxDataBlockItem("better_grass",230-256,Block::mBlocks[230]);
}

static void (*_BG_InitBlocks)();
static void BG_InitBlocks(){
	_BG_InitBlocks();
	
	//BetterGrass
    BlockGraphics::mBlocks[230]=new BlockGraphics("portal");
	BlockGraphics::mBlocks[230]->setTextureItem("better_grass");
	BlockGraphics::mBlocks[230]->setBlockShape(BlockShape::CROSS);
	BlockGraphics::mBlocks[230]->setSoundType(BlockSoundType::GRASS);
}

static void (*_Bl_InitBlocks)();
static void Bl_InitBlocks(){
	_Bl_InitBlocks();
	
	//BetterGrass
    Block::mBlocks[230]=new BetterGrass("better_grass",230);
}

static void (*_InitCreativeItems)();
static void InitCreativeItems(){
	_InitCreativeItems();
	
	//BetterGrass
	//Item::addCreativeItem(230,0);
	//Item::addCreativeItem(230,1);
	//Item::addCreativeItem(230,2);
}

/*static void (*_NormalTick)(Entity*entity);
static void NormalTick(Entity*entity){
	_NormalTick(entity);
	
    ::e = entity;
	*bs = e -> getRegion();
}*/

JNIEXPORT jint JNI_OnLoad(JavaVM*,void*){
	MSHookFunction((void *)&BlockTessellator::tessellateInWorld,(void *)TessellateInWorld,(void **)&_TessellateInWorld);
    MSHookFunction((void *)&Item::initClientData,(void *)InitClientData,(void **)&_InitClientData);
	MSHookFunction((void *)&Item::initCreativeItems,(void *)InitCreativeItems,(void **)&_InitCreativeItems);
	MSHookFunction((void *)&BlockGraphics::initBlocks,(void *)BG_InitBlocks,(void **)&_BG_InitBlocks);
	MSHookFunction((void *)&Block::initBlocks,(void *)Bl_InitBlocks,(void **)&_Bl_InitBlocks);
	//MSHookFunction((void *)&Entity::normalTick,(void *)NormalTick,(void **)&_NormalTick);
	return JNI_VERSION_1_6;
}




