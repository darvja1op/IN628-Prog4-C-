#include "Approacher.h"


Approacher::Approacher(Graphics^ offScreenCanvas, Bitmap^ redShipBitmap, int shipFrames, Random^ rGen, int shipSpeed, Rectangle backgroundRectangle)
: SimpleSprite(offScreenCanvas, redShipBitmap, shipFrames,rGen, shipSpeed,backgroundRectangle)
{
}

void Approacher::orient(SimpleSprite^ target)
{
	double angle = computeAngleToTarget(target);

	xVel = (int)(Math::Cos(angle) * speed);
	yVel = (int)(Math::Sin(angle) * speed);
}
