#pragma once
#include "Sprite.h"
ref class Hero :
public Sprite
{
private:
	property int health;
public:
	Hero(Graphics^ startCanvas, array<String^>^ startFileNames, int startNFrames, int startHealth);
	int GetHealth() { return health; }
};

