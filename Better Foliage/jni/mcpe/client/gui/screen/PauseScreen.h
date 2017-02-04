#pragma once

#include "Screen.h"
#include "../../../level/LevelListener.h"

class PackedScrollContainer;
class Label;
class ScreenChooser;

// Size : 236
class PauseScreen : public Screen, public LevelListener
{
public:
	void **vtable;							// 200
	char filler1[12];							// 204
	Touch::TButton *backButton;					// 216
	Touch::TButton *quitButton;					// 220
	Touch::TButton *optionButton;				// 224
	Label *headerLabel;							// 228
	PackedScrollContainer *playerListContainer;	// 232
	ScreenChooser* cctv;

public:
	PauseScreen(bool);
	virtual ~PauseScreen();
	virtual void render(int, int, float);
	static void init();
	static void setupPositions();
	virtual bool handleBackEvent(bool);
	static void tick();
	virtual bool renderGameBehind();
	static void _buttonClicked(Button &);
	virtual void controllerDirectionChanged(int, Controller::StickDirection);
	virtual void onEntityAdded(Entity &);
	virtual void onEntityRemoved(Entity &);
};
