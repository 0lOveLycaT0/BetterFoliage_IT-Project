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
	
	int TR = Block::mGlass -> renderLayer1;
	Block::mBlocks[2] -> renderLayer1 = TR;
	
	/*switch(block.blockId){
		case 2:
			return tess -> grassblockRenderer(blockk,pos,aux,bs);
		break;
			
		default:
		    return _TessellateInWorld(tess,block,pos,aux,b);
		break;
	}*/
	
	if(block.blockId == 2){
		/*if(tess -> getRegion().getBlock(x,y+1,z) == Block::mAir){
			tess -> getRegion().setBlock(x,y+1,z,201,0);
		}*/
		srand(x^y^z);
		unsigned char raux = rand()%3;
		float const  offsetx = fmod((((float)rand())/((float)RAND_MAX)),0.2)*((rand()%2)?1:-1);
		float const  offsety = fmod((((float)rand())/((float)RAND_MAX)),0.1)*((rand()%2)?1:-1);
		float const  offsetz = fmod((((float)rand())/((float)RAND_MAX)),0.2)*((rand()%2)?1:-1);
		//block.setVisualShape({0,0,0,1+offsetx,0.8,1+offsetz});
		//return _TessellateInWorld(tess,block,{x + offsetx,y,z + offsetz},aux,b);
		//return _tessellateInWorld(tess,block,pos,aux,b);
		Tessellator& t = tess -> getTessellator();
		t.init();
		//t.color(tess -> _getBlockColor(pos,block,aux));
		TextureUVCoordinateSet const& uv = tess -> _getTexture(*Block::mBlocks[201],0,raux);
		t.vertexUV(x + offsetx + 0.10,y + 0.80,z + offsetz + 0.10,uv.maxU,uv.maxV);
		t.vertexUV(x + offsetx + 0.10,y + offsety + 1.70,z + offsetz + 0.10,uv.maxU,uv.minV);
		t.vertexUV(x + offsetx + 0.90,y + offsety + 1.70,z + offsetz + 0.90,uv.minU,uv.minV);
		t.vertexUV(x + offsetx + 0.90,y + 0.80,z + offsetz + 0.90,uv.minU,uv.maxV);
		
		t.vertexUV(x + offsetx + 0.10,y + 0.80,z + offsetz + 0.10,uv.minU,uv.maxV);
		t.vertexUV(x + offsetx + 0.90,y + 0.80,z + offsetz + 0.90,uv.maxU,uv.maxV);
		t.vertexUV(x + offsetx + 0.90,y + offsety + 1.70,z + offsetz + 0.90,uv.maxU,uv.minV);
		t.vertexUV(x + offsetx + 0.10,y + offsety + 1.70,z + offsetz + 0.10,uv.minU,uv.minV);
		
		t.vertexUV(x + offsetx + 0.10,y + 0.80,z + offsetz + 0.90,uv.maxU,uv.maxV);
		t.vertexUV(x + offsetx + 0.10,y + offsety + 1.70,z + offsetz + 0.90,uv.maxU,uv.minV);
		t.vertexUV(x + offsetx + 0.90,y + offsety + 1.70,z + offsetz + 0.10,uv.minU,uv.minV);
		t.vertexUV(x + offsetx + 0.90,y + 0.80,z + offsetz + 0.10,uv.minU,uv.maxV);
		
		t.vertexUV(x + offsetx + 0.10,y + 0.80,z + offsetz + 0.90,uv.minU,uv.maxV);
		t.vertexUV(x + offsetx + 0.90,y + 0.80,z + offsetz + 0.10,uv.maxU,uv.maxV);
		t.vertexUV(x + offsetx + 0.90,y + offsety + 1.70,z + offsetz + 0.10,uv.maxU,uv.minV);
		t.vertexUV(x + offsetx + 0.10,y + offsety + 1.70,z + offsetz + 0.90,uv.minU,uv.minV);
		return _TessellateInWorld(tess,block,pos,aux,b);
	}
	else if(block.blockId == 201){
        srand(x^y^z);
		float const  offsetx = fmod((((float)rand())/((float)RAND_MAX)),0.2)*((rand()%2)?1:-1);
		float const  offsety = fmod((((float)rand())/((float)RAND_MAX)),0.1)*((rand()%2)?1:-1);
		float const  offsetz = fmod((((float)rand())/((float)RAND_MAX)),0.2)*((rand()%2)?1:-1);
		//block.setVisualShape({0,0,0,1+offsetx,0.8,1+offsetz});
		//return _TessellateInWorld(tess,block,{x + offsetx,y,z + offsetz},aux,b);
		//return _tessellateInWorld(tess,block,pos,aux,b);
		Tessellator& t = tess -> getTessellator();
		t.init();
		//t.color(tess -> _getBlockColor(pos,block,aux));
		TextureUVCoordinateSet const& uv = tess -> _getTexture(block,0,aux);
		t.vertexUV(x + offsetx + 0.10,y - 0.20,z + offsetz + 0.10,uv.maxU,uv.maxV);
		t.vertexUV(x + offsetx + 0.10,y + offsety + 0.70,z + offsetz + 0.10,uv.maxU,uv.minV);
		t.vertexUV(x + offsetx + 0.90,y + offsety + 0.70,z + offsetz + 0.90,uv.minU,uv.minV);
		t.vertexUV(x + offsetx + 0.90,y - 0.20,z + offsetz + 0.90,uv.minU,uv.maxV);
		
		t.vertexUV(x + offsetx + 0.10,y - 0.20,z + offsetz + 0.10,uv.minU,uv.maxV);
		t.vertexUV(x + offsetx + 0.90,y - 0.20,z + offsetz + 0.90,uv.maxU,uv.maxV);
		t.vertexUV(x + offsetx + 0.90,y + offsety + 0.70,z + offsetz + 0.90,uv.maxU,uv.minV);
		t.vertexUV(x + offsetx + 0.10,y + offsety + 0.70,z + offsetz + 0.10,uv.minU,uv.minV);
		
		t.vertexUV(x + offsetx + 0.10,y - 0.20,z + offsetz + 0.90,uv.maxU,uv.maxV);
		t.vertexUV(x + offsetx + 0.10,y + offsety + 0.70,z + offsetz + 0.90,uv.maxU,uv.minV);
		t.vertexUV(x + offsetx + 0.90,y + offsety + 0.70,z + offsetz + 0.10,uv.minU,uv.minV);
		t.vertexUV(x + offsetx + 0.90,y - 0.20,z + offsetz + 0.10,uv.minU,uv.maxV);
		
		t.vertexUV(x + offsetx + 0.10,y - 0.20,z + offsetz + 0.90,uv.minU,uv.maxV);
		t.vertexUV(x + offsetx + 0.90,y - 0.20,z + offsetz + 0.10,uv.maxU,uv.maxV);
		t.vertexUV(x + offsetx + 0.90,y + offsety + 0.70,z + offsetz + 0.10,uv.maxU,uv.minV);
		t.vertexUV(x + offsetx + 0.10,y + offsety + 0.70,z + offsetz + 0.90,uv.minU,uv.minV);
	}
	else{
		return _TessellateInWorld(tess,block,pos,aux,b);
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




