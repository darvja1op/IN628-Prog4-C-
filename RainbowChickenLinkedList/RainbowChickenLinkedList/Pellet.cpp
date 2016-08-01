#include "Pellet.h"


Pellet::Pellet(int startXPos, int startYPos, Graphics^ startCanvas, Random^ startRGen)
{
	xPos = startXPos;
	yPos = startYPos;
	canvas = startCanvas;
	rGen = startRGen;
}
