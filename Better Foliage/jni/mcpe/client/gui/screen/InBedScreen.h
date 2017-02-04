#pragma once

#include "Screen.h"

class Button;

class InBedScreen : public Screen
{
public:
	InBedScreen();
	virtual ~InBedScreen();
	virtual bool handleBackEvent(bool);
	static void init();
	virtual void setupPositions();
	static void _buttonClicked(Button &);
	void render(int,int,float);
};
