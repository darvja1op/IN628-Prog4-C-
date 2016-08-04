#include "Pellet.h"


Pellet::Pellet(int startXPos, int startYPos, Graphics^ startCanvas, Random^ startRGen)
{
	xPos = startXPos;
	yPos = startYPos;
	canvas = startCanvas;
	rGen = startRGen;
	diameter = 10;
	brush = gcnew SolidBrush(Color::White);
	eraseBrush = gcnew SolidBrush(Color::Black);

	yVel = rGen->Next(1,20);
	//xVel = rGen->Next(10);
	IsAlive = true;
}

void Pellet::draw()
{
 	canvas->FillEllipse(brush, xPos, yPos, diameter,diameter);
}

void Pellet::move()
{
	//xPos -= xVel;
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