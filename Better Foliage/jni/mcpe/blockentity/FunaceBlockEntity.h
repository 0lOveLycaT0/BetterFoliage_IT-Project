#pragma once

class ItemInstance;

class FurnaceBlockEntity
{
public:
	FurnaceBlockEntity();
    ~FurnaceBlockEntity();
	float getBurnDuration(ItemInstance const*);
    ItemInstance* getItem(int)const;
    bool isFinished();
    void removeItem(int,int);
    bool canPullOutItem(int,int,ItemInstance*);
    bool isIngredient(ItemInstance const*);
    bool isFuel(ItemInstance const*);
    void setItem(int,ItemInstance*);
    void tick(BlockSource&);
    bool canPushInItem(int,int,ItemInstance*);
    int getBurnProgress(int);
    void resetBurnProgress(void);
};
