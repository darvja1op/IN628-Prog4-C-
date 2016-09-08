#pragma once
#include "SimpleSprite.h"
ref class Avoider :
public SimpleSprite
{
public:
	Avoider(Graphics^ offScreenCanvas, Bitmap^ redShipBitmap, int shipFrames, Random^ rGen, int shipSpeed, Rectangle backgroundRectangle);

	virtual void orient(SimpleSprite^ target) override;
};

