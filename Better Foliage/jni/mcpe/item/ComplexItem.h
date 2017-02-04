#pragma once

#include "Item.h"

class ComplexItem : public Item
{
public:
	ComplexItem(std::string const&,int);
	bool isComplex()const;
	void /*?*/ getUpdatePacket(ItemInstance&,Level&,Entity&);
};
