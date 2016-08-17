#pragma once

#define EAST 0
#define SOUTH 1
#define WEST 2
#define NORTH 3
#define WIDTH 600
#define HEIGHT 800

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
	Random^ rGen;
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

public:
	Sprite(Graphics^ startCanvas, array<String^>^ startFileNames, Random^ startRGen, int startNFrames);
	void draw();
	void move();
	void erase(Color eraseColour);
	void updateFrame();
};

