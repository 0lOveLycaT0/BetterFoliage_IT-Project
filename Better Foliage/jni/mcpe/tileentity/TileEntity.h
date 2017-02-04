#pragma once

#include "TileEntityType.h"
#include "../inventory/FillingContainer.h"

class Packet;
class TilePos;

class TileEntity
{
public:
	TileEntity(TileEntityType, const TilePos &, const std::string &);
	virtual ~TileEntity();
	virtual void load(CompoundTag *);
	virtual void save(CompoundTag *);

	virtual void isFinished();
	virtual void getUpdatePacket();
	virtual void onUpdatePacket(CompoundTag *);
	virtual void setRemoved();
	virtual void triggerEvent(int, int);
	virtual void clearCache();


	void _destructionWobble(float &, float &, float &);
	void _resetAABB();
	void clearRemoved();
	void initTileEntities();
	bool isRemoved() const;
	bool isType(TileEntity *, TileEntityType);
	bool isType(TileEntityType);
	void loadStatic(CompoundTag &);
	void setChanged();
	void setId(TileEntityType, const std::string &);
};
