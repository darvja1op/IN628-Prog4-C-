#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

#include "Dungeon.h"
#include "TileMap.h"
#include "Hero.h"

#define NUM_ROOMS 4

ref class GameManager
{
private:
	Dungeon^ dungeon;
	TileMap^ tileMap;
	Bitmap^ offScreenBitmap;
	Graphics^ offScreenCanvas;
	Graphics^ mainCanvas;
	Hero^ chickenHero;
public:
	GameManager(Random^ startRGen, Graphics^ startOffScreenCanvas, Graphics^ startMainCanvas, Bitmap^ startBitmap, Hero^ startHero);
	void runGame();
	void loadDungeon();
};

