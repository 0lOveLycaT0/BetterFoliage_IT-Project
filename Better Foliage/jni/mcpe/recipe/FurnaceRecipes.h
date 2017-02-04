#pragma once

#include <string>
#include <vector>
#include "mcpe/item/ItemInstance.h"
#include "./Recipes.h"

class FurnaceRecipes : public Recipes
{
	public:
    static FurnaceRecipes *mInstance;
    
	void addFurnaceRecipeAuxData(short,short,ItemInstance const&);
	bool isFurnaceItem(ItemInstance*);
	void *getResult(ItemInstance const*);
	void addFurnaceRecipe(int,ItemInstance const&);
	void teardownFurnaceRecipes(void);
	void clearFurnaceRecipes(void);
	FurnaceRecipes(void);
	static FurnaceRecipes *getInstance(void);
};
