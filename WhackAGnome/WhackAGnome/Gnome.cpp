#include "Gnome.h"


Gnome::Gnome(Graphics^ startCanvas, int startXPos, int startYPos)
{
	canvas = startCanvas;
	xPos = startXPos;
	yPos = startYPos;
	isHamster = false;
	image = Image::FromFile("gnome.jpg");
}
