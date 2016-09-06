#include "Pellet.h"


Pellet::Pellet(int startXPos, int startYPos, Graphics^ startCanvas, Random^ startRGen)
{
	xPos = startXPos;
	yPos = startYPos;
	canvas = startCanvas;
	rGen = startRGen;
	diameter = 10;

	int colourSwitch = rGen->Next(5);

	switch (colourSwitch)
	{
	default:
		brush = gcnew SolidBrush(Color::White);
		break;
	case 0:
		brush = gcnew SolidBrush(Color::Green);
		break;
	case 1:
		brush = gcnew SolidBrush(Color::Red);
		break;
	case 2:
		brush = gcnew SolidBrush(Color::Pink);
		break;
	case 3:
		brush = gcnew SolidBrush(Color::Blue);
		break;
	case 4:
		brush = gcnew SolidBrush(Color::Yellow);
		break;
	}
	eraseBrush = gcnew SolidBrush(Color::Black);

	yVel = rGen->Next(10,20);
	xVel = rGen->Next(4);

	int posNeg = rGen->Next(2);
	if (posNeg == 0)
	{
		xVel *= -1;
	}

	IsAlive = true;
}

void Pellet::draw()
{
 	canvas->FillEllipse(brush, xPos, yPos, diameter,diameter);
}

void Pellet::move()
{
	xPos -= xVel;
	yPos -= yVel;

	if (yPos <= 0)
	{
		IsAlive = false;
	}
}

void Pellet::erase()
{
	canvas->FillEllipse(eraseBrush, xPos, yPos, diameter, diameter);
}