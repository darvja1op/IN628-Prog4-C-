#pragma once

#define MAX_TILES 5

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
ref class Tile
{
public:
	property Bitmap^ TileBitmap;
	property bool IsWalkable;
public:
	Tile(Bitmap^ startTileBitmap, bool startIsWalkable);
};

