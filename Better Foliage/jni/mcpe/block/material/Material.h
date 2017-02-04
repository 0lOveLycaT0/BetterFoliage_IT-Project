#pragma once

#include "MaterialType.h"

// Size : 16
class Material
{
public:
	static Material *mInitialized;
	static Material *mMaterials;

public:
	bool flammable;				// 0
	bool neverBuildable;		// 1
	bool notAlwaysDestroyable;	// 2
	bool replaceable;			// 3
	char filler1[9];			// 4
	bool notBlockingMotion;		// 12
	char filler2[3];			// 13
	
	enum Settings : int {
		DefaultMaterialSettings
	};

public:
	Material(MaterialType, Material::Settings, float);
	void _setFlammable();
	void _setNeverBuildable();
	void _setNotAlwaysDestroyable();
	void _setNotBlockingMotion();
	void _setReplaceable();
	static void initMaterials();
	static void tearDownMaterials();
	static Material& getMaterial(MaterialType);
};
