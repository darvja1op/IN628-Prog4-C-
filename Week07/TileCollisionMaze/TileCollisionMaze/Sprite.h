#pragma once

#include "TileMap.h"

#define EAST 0
#define SOUTH 1
#define WEST 2
#define NORTH 3
#define MAX_DIRECTIONS 4

#define BOUNCE 0
#define WRAP 1
#define DIE 2
#define STOP 3

#define TILE_SIDE 32

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
ref class Sprite
{
private:
	Graphics^ canvas;
	array<Bitmap^>^ spriteSheets;
	array<Point>^ velocityDirections;
	int nFrames;
	int currentFrame;
	int xPos;
	int yPos;
	int frameWidth;
	int frameHeight;

public:
	Sprite^ Next;
	int SpriteDirection;
	int XVel;
	int YVel;
	property Rectangle BoundingArea;
	property int BoundsAction;
	property bool IsAlive;

public:
	Sprite(Graphics^ startCanvas, array<String^>^ startFileNames, int startNFrames, Rectangle startBoundingArea);
	void draw();
	void move();
	void erase(Color eraseColour);
	void updateFrame();
	void die();
	void bounce();
	void stop();
	void wrap();
	bool IsLegalMove(TileMap^ tileMap);
};

