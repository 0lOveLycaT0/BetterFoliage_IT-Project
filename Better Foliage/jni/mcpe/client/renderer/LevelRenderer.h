#pragma once

#include <memory>
class MinecraftClient;
class FrustumCuller;
class Entity;
class Block;
class BlockPos;
class BlockSource;
class FullBlock;
// Size : 1240
class LevelRenderer
{
public:
	void tick();
	void allChanged();
	void _renderBlockOverlay(BlockSource&,float,Block*,BlockPos const&);
	void _renderShadow(float,Vec3 const&,float);
	void _renderStars(float);
	void renderWeather(float);
	void _renderSunOrMoon(float,bool);
	void renderSky(Entity &,float);
	void renderNameTags(float);
	void renderClouds(float);
	void onAreaChanged(BlockSource&,BlockPos const&,BlockPos const&);
	void onBlockChanged(BlockSource&,BlockPos const&,FullBlock,FullBlock,int);
	void renderLevel(Entity&,FrustumCuller&,FrustumCuller&,float,float);
};
