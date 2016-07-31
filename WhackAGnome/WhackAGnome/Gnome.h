#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class Gnome
{
private:
	Image^ image;
	Graphics^ canvas;
	int xPos;
	int yPos;
	bool isHamster;

public:
	Gnome(Graphics^ startCanvas, int startXPos, int startYPos);
	void draw();
	void erase();
	bool pointInGnome(int x, int y);
	void changeImage(String^ newFile);

	bool getIsHamster()			{ return isHamster; }
	void setIsHamster(bool i)	{ isHamster = i; }

};

