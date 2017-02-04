#pragma once

#include "Screen.h"

class MessageBoxScreen : public Screen
{
public:
	MessageBoxScreen(MinecraftClient&,const std::string &);
	virtual ~MessageBoxScreen();
	virtual void render(int, int, float);
	virtual void init();
	virtual bool handleBackEvent(bool);
	void _buttonClicked(Button &);
};
