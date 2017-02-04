#pragma once

#include "mcpe/entity/Mob.h"
#include "mcpe/gamemode/GameType.h"
class ChunkSource;
class GlobalPermissionsLevel;
class UserPermissionsLevel;
class BlockEntity;
class TelemetryEventPacket;
class Inventory;

class Player : public Mob 
{
public:
	char filler2[2971];
	bool creativeMode;
	bool surivivalMode;

	virtual ~Player();
	virtual void remove();
	virtual void getAddPacket();
	virtual void normalTick();
	virtual void rideTick();
	virtual float getRidingHeight();
	virtual float getHeadHeight();
	virtual bool isImmobile() const;
	virtual bool isPushable() const;
	virtual bool isShootable();
	virtual bool isCreativeModeAllowed();
	virtual void hurt(const EntityDamageSource&, int);
	virtual void awardKillScore(Entity&, int);
	virtual void setEquippedSlot(ArmorSlot, int, int);
	virtual void setEquippedSlot(ArmorSlot, const ItemInstance&);
	virtual EntityType getEntityTypeId() const = 0;
	virtual int getPortalCooldown() const;
	virtual int getPortalWaitTime() const;
	virtual void sendMotionPacketIfNeeded();
	virtual void lavaHurt();
	virtual void readAdditionalSaveData(const CompoundTag*) = 0;
	virtual void addAdditionalSaveData(CompoundTag*) = 0;
	virtual void die(const EntityDamageSource&);
	virtual bool isSleeping() const;
	virtual float getSpeed();
	virtual void setSpeed(float);
	virtual void travel(float, float);
	virtual void aiStep();
	virtual ItemInstance* getCarriedItem();
	virtual int getItemUseDuration();
	virtual void dropAllGear(int);
	
	virtual void drop(const ItemInstance*, bool);
	
	virtual void sendInventory() const;
	virtual void dropDeathLoot(int);
	virtual void dropRareDeathLoot();
	virtual void jumpFromGround();
	virtual void updateAi();
	virtual void getExperienceReward() const;
	virtual bool useNewAi();
	virtual void registerAttributes();
	virtual void prepareRegion(ChunkSource&);
	virtual void destroyRegion();
	virtual void suspendRegion();
	virtual void onPrepChangeDimension();
	virtual void onDimensionChanged();
	virtual void tickWorld();
	virtual void moveView();
	virtual void setName(const std::string&);
	virtual void _checkMovementStatistics(const Vec3&);
	virtual void respawn();
	virtual void resetPos(bool);
	virtual bool isOnTrialMode();
	virtual bool hasResource(int);
	virtual void completeUsingItem();
	
	virtual void drop(const ItemInstance*);
	
	virtual void setGlobalPermissions(GlobalPermissionsLevel);
	virtual void setPermissions(UserPermissionsLevel);
	virtual void startCrafting(const BlockPos&);
	virtual void startStonecutting(const BlockPos&);
	virtual void startDestroying();
	virtual void stopDestroying();
	virtual void openContainer(int, const BlockPos&);
	virtual void openContainer(int, const EntityUniqueID&);
	virtual void openFurnace(int, const BlockPos&);
	virtual void openEnchanter(int, const BlockPos&);
	virtual void openAnvil(const BlockPos&);
	virtual void openBrewingStand(int, const BlockPos&);
	virtual void openHopper(int, const BlockPos&);
	virtual void openHopper(int, const EntityUniqueID&);
	virtual void openDispenser(int, const BlockPos&);
	virtual void openPortfolio();
	virtual void displayChatMessage(const std::string&, const std::string&);
	virtual void displayClientMessage(const std::string&);
	virtual void displayLocalizableMessage(const std::string&, const std::vector<std::string, std::allocator<std::string>>&);
	virtual void startSleepInBed(const BlockPos&);
	virtual void stopSleepInBed(bool, bool);
	virtual bool canStartSleepInBed();
	virtual void getSleepTimer() const;
	virtual void openTextEdit(BlockEntity*);
	virtual bool isLocalPlayer() const;
	virtual void stopLoading();
	virtual void setPlayerGameTypePacketReceived(GameType);
	virtual void setPlayerGameType(GameType);
	virtual void _crit(Entity&);
	virtual void getTelemetry() const;
	virtual void sendTelemetryPacket(const TelemetryEventPacket&);
	virtual void deleteContainerManager();
	virtual void onMovePlayerPacketNormal(const Vec3&, const Vec2&);

	ItemInstance* getSelectedItem() const;
	bool isCreative() const;
	bool isSurvival() const;
	bool isViewer() const;
	bool hasRespawnPosition() const;
	BlockPos getSpawnPosition();
	void setRespawnPosition(const BlockPos&);
	void setSkin(const std::string&, const std::string&);
	void take(Entity&, int);
	void attack(Entity&);
	Inventory& getInventory()const;
};
