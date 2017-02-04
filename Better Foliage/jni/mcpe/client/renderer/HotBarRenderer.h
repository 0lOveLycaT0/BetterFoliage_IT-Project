#pragma once

#include <memory>

class MinecraftClient;
class UIControl;
class RectangleArea;
class HotBarRenderer
{
public:
	void render(MinecraftClient&,std::shared_ptr<UIControl>&,int,RectangleArea&);
};
