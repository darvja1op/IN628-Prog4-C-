#include "Avoider.h"


Avoider::Avoider(Graphics^ offScreenCanvas, Bitmap^ redShipBitmap, int shipFrames, Random^ rGen, int shipSpeed, Rectangle backgroundRectangle)
: SimpleSprite(offScreenCanvas, redShipBitmap, shipFrames, rGen, shipSpeed, backgroundRectangle)
{
}

void Avoider::orient(SimpleSprite^ target)
{
	double angle = computeAngleToTarget(target);

	xVel = (int)(Math::Cos(angle) * speed) * -1;
	yVel = (int)(Math::Sin(angle) * speed) * -1;
}
