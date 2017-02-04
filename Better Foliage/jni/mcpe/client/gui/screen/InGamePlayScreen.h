#pragma once

#include "Screen.h"
class ScreenContext;
class InGamePlayScreen : public Screen
{
    public:
    InGamePlayScreen();
    virtual ~InGamePlayScreen();
    virtual void tick();
    virtual void handleDirection(DirectionId, float, float);
	virtual void init();
	virtual void setupPositions();
	virtual void _buttonClicked(Button &);
	virtual void render(ScreenContext&);
};
