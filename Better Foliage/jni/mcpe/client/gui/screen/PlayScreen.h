#pragma once

#include "Screen.h"

class Button;

class PlayScreen : public Screen
{
public:
	virtual bool handleBackEvent(bool);
	static void init();
	virtual void setupPositions();
	static void _buttonClicked(Button &);
	static void _init(int,int);
};
