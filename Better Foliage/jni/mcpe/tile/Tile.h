#pragma once

#include <string>
#include <vector>

#include "material/Material.h"
class TileEntity;
#include "../util/TilePos.h"
#include "mcpe/item/TileItem.h"
#include "mcpe/level/TileSource.h"
#include "../client/renderer/texture/TextureUVCoordinateSet.h"
class Entity;
class Player;
class Mob;
class Random;
#include "../util/AABB.h"
class ItemInstance;
class Brightness;

class Tile {
public:
    class SoundType {
	public:
		float volume;
		float pitch;
		std::string breakSound;
		std::string stepSound;


		SoundType() {};
		SoundType(std::string const&, float, float);
	};


	bool replaceable; // 4
	AABB hitbox; // 8
	TextureUVCoordinateSet tex; // 36
	unsigned char id; // 68
	const Tile::SoundType* soundType; // 72
	int canBuildOver; // 76
	int renderPass; // 80
	int renderType; // 84
	int tileType; // 88
	int tileEntityType; // 92
	float thickness; // 96
	bool canFall; // 100
	bool canInstaTick; // 101
	float gravity; // 104
	Material* material; // 108
	float friction; // 112
	float destroyTime; // 116
	float explosionResistance; // 120
	int category; // 124
	bool fancy; // 128
	unsigned int textureIsotropic; // 132
	std::string descriptionId; // 136


	static Tile* tiles[256];
	static bool solid[256];
	static float translucency[256];
	static uint_fast8_t lightBlock[256];
	static uint_fast8_t lightEmission[256];
	static bool shouldTick[256];

	static const Tile::SoundType SOUND_NORMAL;
	static const Tile::SoundType SOUND_WOOD;
	static const Tile::SoundType SOUND_GRAVEL;
	static const Tile::SoundType SOUND_GRASS;
	static const Tile::SoundType SOUND_STONE;
	static const Tile::SoundType SOUND_METAL;
	static const Tile::SoundType SOUND_GLASS;
	static const Tile::SoundType SOUND_CLOTH;
	static const Tile::SoundType SOUND_SAND;
	static const Tile::SoundType SOUND_LADDER;
	static const Tile::SoundType SOUND_SILENT;


	Tile(int, Material const*);
	Tile(int, TextureUVCoordinateSet, Material const*);
	Tile(int, std::string const&, Material const*);

	virtual ~Tile();
	virtual void onFertilized(TileSource*, int, int, int);
	virtual AABB const& getVisualShape(TileSource*, int, int, int, AABB&, bool);
	virtual AABB const& getVisualShape(unsigned char, AABB&, bool);
	virtual AABB const& getCollisionShape(AABB&, TileSource&, int, int, int);
	virtual bool isObstructingChests(TileSource*, int, int, int);
	virtual bool shouldRenderFace(TileSource*, int, int, int, signed char, const AABB&) const;
	virtual TextureUVCoordinateSet const& getTexture(signed char);
	virtual TextureUVCoordinateSet const& getTexture(signed char, int);
	virtual TextureUVCoordinateSet const& getTexture(TileSource*, int, int, int, signed char);
	virtual void getTessellatedUVs();
	virtual void getCarriedTexture(signed char, int);
	virtual AABB* getAABB(TileSource*, int, int, int, AABB&, int, bool, int);
	virtual void addAABBs(TileSource*, int, int, int, const AABB*, std::vector<AABB, std::allocator<AABB>>&);
	virtual void addCollisionShapes(TileSource&, int, int, int, const AABB*, std::vector<AABB, std::allocator<AABB>>&);
	virtual int getRenderLayer(TileSource*, TilePos const&) const; //
	virtual float getThickness() const;
	virtual bool isCropTile() const;
	virtual bool isPathfindable(Entity*, const TilePos&, int, int, int);
	virtual bool mayPick();
	virtual bool mayPick(TileSource*, int, bool); //
	virtual bool mayPlace(TileSource*, int, int, int, signed char);
	virtual bool mayPlace(TileSource*, int, int, int);
	virtual void tryToPlace(TileSource*, TilePos const&, unsigned char); //
	virtual void tick(TileSource*, int, int, int, Random*);
	virtual void animateTick(TileSource*, int, int, int, Random*);
	virtual void destroy(TileSource*, int, int, int, int, Entity*);
	virtual void playerWillDestroy(Player*, int, int, int, int);
	virtual void neighborChanged(TileSource*, int, int, int, int, int, int);
	virtual void onPlace(TileSource*, int, int, int);
	virtual void onRemove(TileSource*, int, int, int);
	virtual void getSecondPart(TileSource&, TilePos const&, TilePos&);
	virtual void onGraphicsModeChanged(bool, bool);
	virtual int getResource(Random*, int, int); //
	virtual int getResourceCount(Random*, int, int); //
	virtual void getDestroyProgress(Player*);
	virtual void spawnResources(TileSource*, int, int, int, int, float, int); //
	virtual void spawnBurnResources(TileSource*, float, float, float);
	virtual float getExplosionResistance(Entity*);
	virtual void clip(TileSource*, int, int, int, const Vec3&, const Vec3&, bool, int);
	virtual void wasExploded(TileSource*, int, int, int, Entity*);
	virtual bool use(Player*, int, int, int);
	virtual void stepOn(Entity*, int, int, int);
	virtual void fallOn(TileSource*, int, int, int, Entity*, float);
	virtual int getPlacementDataValue(Mob*, int, int, int, signed char, float, float, float, int);
	virtual void prepareRender(TileSource*, int, int, int);
	virtual void attack(Player*, int, int, int);
	virtual void handleEntityInside(TileSource*, int, int, int, Entity*, Vec3&);
	virtual int getColor(int);
	virtual int getColor(TileSource*, int, int, int);
	virtual bool isSeasonTinted() const;
	virtual bool isSignalSource();
	virtual bool getSignal(TileSource*, int, int, int);
	virtual int getSignal(TileSource*, int, int, int, int);
	virtual int getDirectSignal(TileSource*, int, int, int, int);
	virtual bool entityInside(TileSource*, int, int, int, Entity*);
	virtual void playerDestroy(Player*, int, int, int, int);
	virtual bool canSurvive(TileSource*, int, int, int);
	virtual int getExperienceDrop(Random*) const;
	virtual bool canBeBuiltOver(TileSource&, int, int, int) const;
	virtual Tile* setNameId(const std::string&);
	virtual std::string getName(const ItemInstance*) const;
	virtual void triggerEvent(TileSource*, int, int, int, int, int);
	virtual TextureUVCoordinateSet getTextureNum(int);
	virtual void getMobToSpawn(TileSource&, const TilePos&) const;
	virtual int getIconYOffset() const;
	virtual bool shouldStopFalling(Entity*);
	virtual float calcGroundFriction(Mob*, const TilePos&) const;
	virtual bool canHaveExtraData() const;
	virtual void setVisualShape(float, float, float, float, float, float);
	virtual Tile* setSoundType(const Tile::SoundType&);
	virtual Tile* setLightBlock(Brightness);
	virtual Tile* setLightEmission(float);
	virtual Tile* setExplodeable(float);
	virtual Tile* setDestroyTime(float);
	virtual Tile* setFriction(float);
	virtual void setTicking(bool);
	virtual void getSpawnResourcesAuxValue(int);
	virtual Tile* init();
	virtual bool _canBeSilkTouched() const;
	
	
	void addAABB(const AABB&, const AABB*, std::vector<AABB, std::allocator<AABB>>&);
	void popResource(TileSource*, int, int, int, const ItemInstance&);
	TextureUVCoordinateSet getTextureUVCoordinateSet(const std::string&, int);
	Tile* setCategory(int);
	static void initTiles();


	static Tile* rock;
	static Tile* grass;
	static Tile* dirt;
	static Tile* podzol;
	static Tile* stoneBrick;
	static Tile* wood;
	static Tile* sapling;
	static Tile* unbreakable;
	static Tile* water;
	static Tile* calmWater;
	static Tile* lava;
	static Tile* calmLava;
	static Tile* sand;
	static Tile* gravel;
	static Tile* goldOre;
	static Tile* ironOre;
	static Tile* coalOre;
	static Tile* log;
	static Tile* leaves;
	static Tile* sponge;
	static Tile* web;
	static Tile* glass;
	static Tile* thinGlass;
	static Tile* lapisOre;
	static Tile* lapisBlock;
	static Tile* dispenser;
	static Tile* sandStone;
	static Tile* musicBlock;
	static Tile* bed;
	static Tile* tallgrass;
	static Tile* cloth;
	static Tile* yellowFlower;
	static Tile* redFlower;
	static Tile* brownMushroom;
	static Tile* redMushroom;
	static Tile* goldBlock;
	static Tile* ironBlock;
	static Tile* stoneSlab;
	static Tile* stoneSlabHalf;
	static Tile* redBrick;
	static Tile* tnt;
	static Tile* bookshelf;
	static Tile* mossStone;
	static Tile* obsidian;
	static Tile* torch;
	static Tile* fire;
	static Tile* mobSpawner;
	static Tile* stairs_wood;
	static Tile* chest;
	static Tile* redStoneDust;
	static Tile* diamondOre;
	static Tile* diamondBlock;
	static Tile* workBench;
	static Tile* stonecutterBench;
	static Tile* crops;
	static Tile* farmland;
	static Tile* furnace;
	static Tile* furnace_lit;
	static Tile* sign;
	static Tile* door_wood;
	static Tile* ladder;
	static Tile* rail;
	static Tile* goldenRail;
	static Tile* stairs_stone;
	static Tile* wallSign;
	static Tile* door_iron;
	static Tile* redStoneOre;
	static Tile* redStoneOre_lit;
	static Tile* topSnow;
	static Tile* ice;
	static Tile* snow;
	static Tile* cactus;
	static Tile* clay;
	static Tile* reeds;
	static Tile* recordPlayer;
	static Tile* fence;
	static Tile* stairs_brick;
	static Tile* fenceGateOak;
	static Tile* fenceGateSpruce;
	static Tile* fenceGateBirch;
	static Tile* fenceGateJungle;
	static Tile* fenceGateBigOak;
	static Tile* fenceGateAcacia;
	static Tile* pumpkin;
	static Tile* lightGem;
	static Tile* litPumpkin;
	static Tile* cake;
	static Tile* trapdoor;
	static Tile* monsterStoneEgg;
	static Tile* stoneBrickSmooth;
	static Tile* melon;
	static Tile* pumpkinStem;
	static Tile* melonStem;
	static Tile* netherReactor;
	static Tile* glowingObsidian;
	static Tile* woodSlab;
	static Tile* woodSlabHalf;
	static Tile* activatorRail;
	static Tile* cobbleWall;
	static Tile* carrots;
	static Tile* potatoes;
	static Tile* beetroot;
	static Tile* woodStairsDark;
	static Tile* woodStairsBirch;
	static Tile* woodStairsJungle;
	static Tile* woodStairsAcacia;
	static Tile* woodStairsBigOak;
	static Tile* hayBlock;
	static Tile* coalBlock;
	static Tile* woolCarpet;
	static Tile* deadBush;
	static Tile* leaves2;
	static Tile* log2;
	static Tile* stairs_stoneBrickSmooth;
	static Tile* netherBrick;
	static Tile* netherrack;
	static Tile* ironFence;
	static Tile* netherFence;
	static Tile* stairs_netherBricks;
	static Tile* stairs_sandStone;
	static Tile* quartzBlock;
	static Tile* quartzOre;
	static Tile* stairs_quartz;
	static Tile* endPortalFrame;
	static Tile* mycelium;
	static Tile* brownMushroomBlock;
	static Tile* redMushroomBlock;
	static Tile* stainedClay;
	static Tile* hardenedClay;
	static Tile* vine;
	static Tile* packedIce;
	static Tile* cocoa;
	static Tile* doublePlant;
	static Tile* endStone;
	static Tile* waterlily;
	static Tile* emeraldOre;
	static Tile* emeraldBlock;
	static Tile* redstoneBlock;
	static Tile* invisible_bedrock;
	static Tile* info_updateGame1;
	static Tile* info_updateGame2;
	static Tile* info_reserved6;
	static Tile* brewing_stand;
	static Tile* anvil;
	static Tile* enchantingTable;
	static Tile* flowerPot;
	static Tile* portal;
	static Tile* skull;
	static Tile* soulSand;
};
