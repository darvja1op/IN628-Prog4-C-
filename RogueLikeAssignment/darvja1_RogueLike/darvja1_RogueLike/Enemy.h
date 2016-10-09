#pragma once
#include "Sprite.h"
ref class Enemy :
public Sprite
{
private:
	property int health;
public:
	Enemy(Graphics^ startCanvas, array<String^>^ startFileNames, int startNFrames, int startHealth);
};

