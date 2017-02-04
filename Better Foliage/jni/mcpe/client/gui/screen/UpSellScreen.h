#pragma once

#include "Screen.h"

class TrialUpsellScreen : public Screen
{
public:
    TrialUpsellScreen();
    virtual ~TrialUpsellScreen();
    virtual void render(int, int, float);
    static void init();
    static void setupPositions();
    virtual bool handleBackEvent(bool);
    virtual void tick();
    virtual bool renderGameBehind();
    static void _buttonClicked(Button &);
};
