#include "mcpe/client/renderer/BlockTessellator.h"
#include "mcpe/util/Vec3.h"
#include "mcpe/util/Vec2.h"
#include "mcpe/block/BlockGraphics.h"
#include "mcpe/util/AABB.h"
#include "mcpe/level/BlockSource.h"

bool BlockTessellator::grassblockRenderer(/*BlockSource&bs, */Block*bltile, BlockPos const&blpos, unsigned char c){
	int x = blpos.x, y = blpos.y, z = blpos.z;
	float offsetx = ((x - z + y) % 10) / 45 , offsetz = ((x - z - y) % 10) / 45;
	//tessellateBlockInWorld(*Block::mBlocks[2],BlockPos(x,y,z),1);
	//tessellateCrossInWorld(*Block::mBlocks[201],BlockPos(x + offsetx,y + 0.8,z + offsetz),c,true);
}
