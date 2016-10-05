#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

#include "Dungeon.h"
#include "TileMap.h"

ref class GameManager
{
private:
	Dungeon^ dungeon;
	TileMap^ tileMap;
	Bitmap^ offScreenBitmap;
	Graphics^ offScreenCanvas;
	Graphics^ mainCanvas;
public:
	GameManager(Random^ startRGen, Graphics^ startOffScreenCanvas, Graphics^ startMainCanvas, Bitmap^ startBitmap);
	void runGame();
	void loadDungeon();
};

