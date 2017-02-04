#pragma once

#include "../Entity.h"

class ItemEntity : public Entity
{
public:
	static float LIFETIME;
	char filler[200];
public:
	ItemEntity(BlockSource&);
	ItemEntity(BlockSource&,Vec3 const&,ItemInstance const&,int,float);
	virtual ~ItemEntity();
	virtual EntityType getEntityTypeId()const;
	virtual void readAdditionalSaveData(const CompoundTag*);
	virtual void addAdditionalSaveData(CompoundTag*);
	void normalTick();
};
