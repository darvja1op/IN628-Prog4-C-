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
#include "Enemy.h"

#define NUM_ROOMS 4
#define NUM_GOLD 3

ref class GameManager
{
private:
	Dungeon^ dungeon;
	TileMap^ tileMap;
	Graphics^ offScreenCanvas;
	Hero^ hero;
	Enemy^ enemy;
	Random^ rGen;
	array<Sprite^>^ treasure;
	int treasureScore;
public:
	GameManager(Random^ startRGen, Graphics^ startOffScreenCanvas, Hero^ startHero, Enemy^ enemy);
	void runGame();
	void loadDungeon();
};

