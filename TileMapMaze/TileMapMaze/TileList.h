#pragma once

#include "Tile.h"

#define MAX_TILES 3

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
ref class TileList
{
private:
	array<Tile^>^ tileArray;
public:
	TileList();

	Bitmap^ GetTileBitmap(int tileIndex);

	void SetTileArrayEntry(int tileIndex, Tile^ tileToEnter);
};

