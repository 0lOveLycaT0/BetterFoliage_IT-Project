#pragma once

#include <string>

class ItemInstance;
class Mob;
class Entity;
class EntityDamageSource;

class Enchant
{
public:
	void ** vtable;  //0
public:
	static Enchant* mEnchants[100];
public:
	Enchant(int,int,std::string const&,int,int);
	~Enchant();
	static void initEnchants();
public:
	virtual bool canEnchant(int)const;
	virtual bool canEnchant(ItemInstance const&)const;
	virtual int getMinCost(int)const;
	virtual int getMaxCost(int)const;
	virtual int getMinLevel()const;
	virtual int getMaxLevel()const;
	virtual void /*?*/ getDamageBonus(int,Entity const&)const; 
	virtual void doPostAttack(Mob&,Mob&,int)const; 
	virtual bool isMeleeDamageEnchant()const;
	virtual void /*?*/ getDamageProtection(int,EntityDamageSource const&)const; 
	virtual void doPostHurt(ItemInstance&,Mob&,Mob&,int)const; 
	virtual bool isProtectionEnchant()const;
	virtual void /*?*/ getFrequency()const; 
	virtual bool isCompatibleWith(int)const; 
	virtual void /*?*/ getDescription()const; 
	virtual bool canPrimaryEnchant(int)const; 
	virtual bool canPrimaryEnchant(ItemInstance const&)const; 
	virtual bool canSecondaryEnchant(int)const; 
	virtual bool canSecondaryEnchant(ItemInstance const&)const;
	virtual void teardownEnchants();
};
