#pragma once
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
	Bitmap^ spriteSheet;
	Random^ rGen;
	int nFrames;
	int currentFrame;
	int xPos;
	int yPos;
	int frameWidth;
	int frameHeight;
	int xVel;
	int yVel;

public:
	Sprite^ Next;

public:
	Sprite(Graphics^ startCanvas, Bitmap^ startSpriteSheet, Random^ startRGen, int startNFrames);
	void draw();
	void move();
	void wander();
	void erase(Color eraseColour);
	void updateFrame();
	void setSpriteSheet(Bitmap^ newSpriteSheet, int newNFrames);
};

