#pragma once

#include "TileList.h"

#define MAP_COLS 40
#define MAP_ROWS 25

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;

ref class TileMap
{
private:
	TileList^ tileList;
	array<int, 2>^ map;
	Graphics^ canvas;
public:
	TileMap(TileList^ startTileList, Graphics^ startCanvas);
	void SetMapEntry(int col, int row, int tileIndex);
	Bitmap^ GetMapEntry(int col, int row);

	void DrawMap();
	void LoadMapFromFile(String^ mapFileName);
	void LoadMapFromArray(array<int, 2>^ cellArray);
	bool isTileWalkable(int col, int row);
};

