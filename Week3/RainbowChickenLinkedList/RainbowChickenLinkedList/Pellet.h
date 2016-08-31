#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class Pellet
{
private:
	int xPos;
	int yPos;
	int xVel;
	int yVel;
	int diameter;
	Color pelletColour;
	Graphics^ canvas;
	Brush^ brush;
	Brush^ eraseBrush;
	Random^ rGen;
public:
	Pellet^ Next;
	property bool IsAlive;
public:
	Pellet(int startXPos, int startYPos, Graphics^ startCanvas, Random^ startRGen);

	void draw();
	void move();
	void erase();

	int getYPos()		{ return yPos; }
};

