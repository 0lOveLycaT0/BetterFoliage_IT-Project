#pragma once

class EnchantUtils
{
public:
	static void applyEnchant(ItemInstance&,int,int);
	static void removeEnchants(ItemInstance&);
	static void randomlyEnchant(ItemInstance&,int,int);
	static bool hasEnchant(int,ItemInstance const&);
};
