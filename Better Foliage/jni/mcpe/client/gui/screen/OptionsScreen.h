#pragma once

#include <vector>
#include "Screen.h"

class MinecraftClient;
class OptionsPane;

// Size : 288
class OptionsScreen : public Screen
{
public:
	char filler1[20];				// 0
	MinecraftClient *client;		// 20
	char filler2[140];				// 24
	std::vector<std::shared_ptr<OptionsPane>> vectorPanes;	// 164

public:
	OptionsScreen();
	virtual ~OptionsScreen();
	virtual void onSetKeyboardHeight(float);
	virtual void removed();
	virtual void onFocusGained();
	virtual void handleButtonRelease(short);
	void createCategoryButton(int,int,int,int,int,int); 
	void reateCategoryButtons(); 
	virtual void handleTextChar(std::string const &, bool);
	virtual void setTextboxText(std::string const &);
	virtual void renderGameBehind() const;
	virtual void render(int, int, float);
	virtual void init();
	virtual void setupPositions();
	virtual void tick();
	virtual void handleScrollWheel(float);
	void _buttonClicked(Button&);
	virtual void _pointerPressed(int, int);
	virtual void _pointerReleased(int, int);
	
	virtual void generateOptionScreens();
	virtual void renderBgFill();
	void _generateOptionScreensDefault();
};
