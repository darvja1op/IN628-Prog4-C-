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
	Graphics^ offScreenCanvas;
	Hero^ chickenHero;
public:
	GameManager(Random^ startRGen, Graphics^ startOffScreenCanvas, Hero^ startHero);
	void runGame();
	void loadDungeon();
};

